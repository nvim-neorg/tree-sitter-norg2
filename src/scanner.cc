#include <cwctype>
#include <iostream>

#include "tree_sitter/parser.h"

using namespace std;

enum TokenType : char {
    WHITESPACE,
};

struct Scanner {
    TSLexer* lexer;

    bool scan(const bool *valid_symbols) {
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
