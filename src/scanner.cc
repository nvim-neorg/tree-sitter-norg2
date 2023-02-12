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

    _NUM_ELEMENTS, // Used to track the size of the `valid_symbols` array
};

struct Scanner {
    TSLexer* lexer;
    int32_t previous = 0;
    const std::unordered_map<int32_t, TokenType> attached_modifier_lookup = {
        {'*', BOLD_OPEN},        {'/', ITALIC_OPEN},       {'-', STRIKETHROUGH_OPEN},
        {'_', UNDERLINE_OPEN},/*   {'!', SPOILER_OPEN},      {'`', VERBATIM_OPEN},
        {'^', SUPERSCRIPT_OPEN}, {',', SUBSCRIPT_OPEN},    {'%', INLINE_COMMENT_OPEN},
        {'$', INLINE_MATH_OPEN}, {'&', INLINE_MACRO_OPEN},*/
    };

    bool scan(const bool *valid_symbols) {
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

        for (size_t i = BOLD_OPEN; i <= UNDERLINE_CLOSE; i++) {
            if (!valid_symbols[i])
                continue;

            const auto attached_mod = attached_modifier_lookup.find(lexer->lookahead);

            if (attached_mod == attached_modifier_lookup.end())
                continue;

            const int32_t saved_previous = previous;
            lexer->mark_end(lexer);

            advance();

            if (lexer->lookahead == attached_mod->first)
                return false;

            if ((saved_previous == 0 || iswspace(saved_previous)) && (lexer->lookahead && !iswspace(lexer->lookahead))) {
                lexer->mark_end(lexer);
                lexer->result_symbol = attached_mod->second;
                return true;
            }
            else if ((saved_previous && !iswspace(saved_previous)) && (!lexer->lookahead || iswspace(lexer->lookahead))) {
                lexer->mark_end(lexer);
                lexer->result_symbol = attached_mod->second + 1;
                return true;
            }

            return false;
        }

        return false;
    }

    void skip() { lexer->advance(lexer, true); }
    void advance() {
        previous = lexer->lookahead;
        lexer->advance(lexer, false);
    }
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
        const Scanner *scanner = static_cast<Scanner*>(payload);
        std::memcpy(buffer, &scanner->previous, sizeof(scanner->previous));
        return sizeof(scanner->previous);
    }

    void tree_sitter_norg_external_scanner_deserialize(void *payload,
            const char *buffer,
            unsigned length) {
        if (!buffer)
            return;

        Scanner *scanner = static_cast<Scanner*>(payload);
        std::memcpy(&scanner->previous, buffer, sizeof(scanner->previous));
    }
}
