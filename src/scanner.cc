#include <cwctype>
#include <iostream>

#include "tree_sitter/parser.h"

using namespace std;

enum TokenType : char {
    INFIRM_TAG_BEGIN,
};

struct Scanner {
    TSLexer* lexer;

    bool scan(const bool *valid_symbols) {
        // const bool is_on_new_line = lexer->get_column(lexer) == 0;

        while (iswspace(lexer->lookahead))
            skip();

        if (valid_symbols[INFIRM_TAG_BEGIN] && lexer->lookahead == '.') {
            advance();
            lexer->result_symbol = INFIRM_TAG_BEGIN;
            return true;
        }

        return false;
    }

    inline void skip() { lexer->advance(lexer, true); }

    inline void advance() { lexer->advance(lexer, false); }
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
