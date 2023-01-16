#include <cwctype>
#include <iostream>

#include "tree_sitter/parser.h"

using namespace std;

enum TokenType : char {
    WHITESPACE,
    WEAK_DELIMITING_MODIFIER,
    HEADING_PREFIX1,
    HEADING_PREFIX2,
    HEADING_PREFIX3,
    HEADING_PREFIX4,
    HEADING_PREFIX5,
    HEADING_PREFIX6,
};

struct Scanner {
    TSLexer* lexer;

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

        if (*reinterpret_cast<const unsigned int*>(&valid_symbols[HEADING_PREFIX1]) != 0 && lexer->lookahead == '*') {
            lexer->mark_end(lexer);
            unsigned long count = 0;

            while (lexer->lookahead == '*') {
                advance();
                count++;
            }

            if (iswspace(lexer->lookahead) || lexer->eof(lexer)) {
                lexer->mark_end(lexer);
                lexer->result_symbol = HEADING_PREFIX1 + count - 1;
                return true;
            }

            return false;
        }

        if (lexer->get_column(lexer) == 0) {
            const bool found_whitespace = iswspace(lexer->lookahead) && lexer->lookahead != '\n' && lexer->lookahead != '\r';

            if (!found_whitespace)
                return false;

            while (iswspace(lexer->lookahead) && lexer->lookahead != '\n' && lexer->lookahead != '\r')
                advance();

            lexer->result_symbol = WHITESPACE;
            return true;
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
