#include <cwctype>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <unordered_map>

#include "tree_sitter/parser.h"

using namespace std;

enum TokenType : char {
    WHITESPACE,
    WEAK_DELIMITING_MODIFIER,

    BOLD_OPEN,
    BOLD_CLOSE,
    ITALIC_OPEN,
    ITALIC_CLOSE,
    STRIKETHROUGH_OPEN,
    STRIKETHROUGH_CLOSE,
    UNDERLINE_OPEN,
    UNDERLINE_CLOSE,
    SPOILER_OPEN,
    SPOILER_CLOSE,
    VERBATIM_OPEN,
    VERBATIM_CLOSE,
    SUPERSCRIPT_OPEN,
    SUPERSCRIPT_CLOSE,
    SUBSCRIPT_OPEN,
    SUBSCRIPT_CLOSE,
    INLINE_COMMENT_OPEN,
    INLINE_COMMENT_CLOSE,
    INLINE_MATH_OPEN,
    INLINE_MATH_CLOSE,
    INLINE_MACRO_OPEN,
    INLINE_MACRO_CLOSE,

    _NUM_ELEMENTS, // Used to track the size of the `valid_symbols` array
};

struct Scanner {
    TSLexer* lexer;
    const std::unordered_map<int32_t, TokenType> attached_modifier_lookup = {
        {'*', BOLD_OPEN},        {'/', ITALIC_OPEN},       {'-', STRIKETHROUGH_OPEN},
        {'_', UNDERLINE_OPEN},   {'!', SPOILER_OPEN},      {'`', VERBATIM_OPEN},
        {'^', SUPERSCRIPT_OPEN}, {',', SUBSCRIPT_OPEN},    {'%', INLINE_COMMENT_OPEN},
        {'$', INLINE_MATH_OPEN}, {'&', INLINE_MACRO_OPEN},
    };

    bool scan(const bool *valid_symbols) {
        if (lexer->eof(lexer))
            return false;

        // TODO: Maybe remove this part from the scanner? Is it doable?
        if (valid_symbols[WEAK_DELIMITING_MODIFIER] && lexer->lookahead == '-') {
            lexer->mark_end(lexer);
            unsigned long count = 0;

            while (lexer->lookahead == '-') {
                advance();
                count++;
            }

            if (count >= 2 && (lexer->lookahead == '\n' || lexer->lookahead == '\r' || lexer->eof(lexer))) {
                lexer->mark_end(lexer);
                lexer->result_symbol = WEAK_DELIMITING_MODIFIER;
                return true;
            }

            return false;
        }

        if (lexer->get_column(lexer) == 0) {
            const bool found_whitespace = iswspace(lexer->lookahead) && lexer->lookahead != '\n' && lexer->lookahead != '\r';

            if (found_whitespace) {
                while (iswspace(lexer->lookahead) && lexer->lookahead != '\n' && lexer->lookahead != '\r')
                    advance();

                lexer->result_symbol = WHITESPACE;
                return true;
            }
        }

        const auto attached_mod = attached_modifier_lookup.find(lexer->lookahead);

        if (attached_mod != attached_modifier_lookup.end()) {
            if (!valid_symbols[attached_mod->second] && !valid_symbols[attached_mod->second + 1])
                return false;

            lexer->mark_end(lexer);
            advance();

            if (lexer->lookahead == attached_mod->first)
                return false;

            if (valid_symbols[attached_mod->second + 1] && (!lexer->lookahead || iswspace(lexer->lookahead) || iswpunct(lexer->lookahead))) {
                lexer->mark_end(lexer);
                lexer->result_symbol = attached_mod->second + 1;
                return true;
            } else if (valid_symbols[attached_mod->second] && lexer->lookahead && !iswspace(lexer->lookahead) && lexer->lookahead != '\n' && lexer->lookahead != '\r') {
                lexer->mark_end(lexer);
                lexer->result_symbol = attached_mod->second;
                return true;
            }  

            return false;
        }

        return false;
    }

    void skip() { lexer->advance(lexer, true); }
    void advance() { lexer->advance(lexer, false); }
};

extern "C" {
    void *tree_sitter_norg_external_scanner_create() { return new Scanner(); }

    void tree_sitter_norg_external_scanner_destroy(void *payload) {
        delete static_cast<Scanner *>(payload);
    }

    bool tree_sitter_norg_external_scanner_scan(void *payload, TSLexer *lexer,
            const bool *valid_symbols) {
        Scanner *scanner = static_cast<Scanner*>(payload);
        scanner->lexer = lexer;
        return scanner->scan(valid_symbols);
    }

    unsigned tree_sitter_norg_external_scanner_serialize(void *payload,
            char *buffer) {
        return 0;
    }

    void tree_sitter_norg_external_scanner_deserialize(void *payload,
            const char *buffer,
            unsigned length) {}
}
