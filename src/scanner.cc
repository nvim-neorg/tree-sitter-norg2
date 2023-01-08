#include <cwctype>
#include <iostream>

#include "tree_sitter/parser.h"

using namespace std;

enum TokenType : char {
    BOLD_OPEN,
    BOLD_CLOSE,

    ITALIC_OPEN,
    ITALIC_CLOSE,

    UNDERLINE_OPEN,
    UNDERLINE_CLOSE,

    STRIKETHROUGH_OPEN,
    STRIKETHROUGH_CLOSE,

    SUPERSCRIPT_OPEN,
    SUPERSCRIPT_CLOSE,

    SUBSCRIPT_OPEN,
    SUBSCRIPT_CLOSE,
};

struct Scanner {
    TSLexer* lexer;
    int32_t m_Previous = 0;

    bool scan(const bool *valid_symbols) {
        m_Previous = lexer->lookahead;
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
