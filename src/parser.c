#include <tree_sitter/parser.h>

#if defined(__GNUC__) || defined(__clang__)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wmissing-field-initializers"
#endif

#define LANGUAGE_VERSION 14
#define STATE_COUNT 47
#define LARGE_STATE_COUNT 14
#define SYMBOL_COUNT 29
#define ALIAS_COUNT 0
#define TOKEN_COUNT 12
#define EXTERNAL_TOKEN_COUNT 0
#define FIELD_COUNT 2
#define MAX_ALIAS_SEQUENCE_LENGTH 5
#define PRODUCTION_ID_COUNT 3

enum {
  sym_word = 1,
  sym_whitespace = 2,
  sym_paragraph_break = 3,
  anon_sym_LF = 4,
  anon_sym_STAR = 5,
  aux_sym_heading1_token1 = 6,
  anon_sym_STAR_STAR = 7,
  anon_sym_STAR_STAR_STAR = 8,
  anon_sym_STAR_STAR_STAR_STAR = 9,
  anon_sym_STAR_STAR_STAR_STAR_STAR = 10,
  anon_sym_STAR_STAR_STAR_STAR_STAR_STAR = 11,
  sym_document = 12,
  sym_paragraph_segment = 13,
  sym_paragraph = 14,
  sym_non_structural = 15,
  sym_heading1 = 16,
  sym_heading2 = 17,
  sym_heading3 = 18,
  sym_heading4 = 19,
  sym_heading5 = 20,
  aux_sym_document_repeat1 = 21,
  aux_sym_paragraph_segment_repeat1 = 22,
  aux_sym_paragraph_repeat1 = 23,
  aux_sym_heading1_repeat1 = 24,
  aux_sym_heading2_repeat1 = 25,
  aux_sym_heading3_repeat1 = 26,
  aux_sym_heading4_repeat1 = 27,
  aux_sym_heading5_repeat1 = 28,
};

static const char * const ts_symbol_names[] = {
  [ts_builtin_sym_end] = "end",
  [sym_word] = "word",
  [sym_whitespace] = "whitespace",
  [sym_paragraph_break] = "paragraph_break",
  [anon_sym_LF] = "\n",
  [anon_sym_STAR] = "*",
  [aux_sym_heading1_token1] = "heading1_token1",
  [anon_sym_STAR_STAR] = "**",
  [anon_sym_STAR_STAR_STAR] = "***",
  [anon_sym_STAR_STAR_STAR_STAR] = "****",
  [anon_sym_STAR_STAR_STAR_STAR_STAR] = "*****",
  [anon_sym_STAR_STAR_STAR_STAR_STAR_STAR] = "******",
  [sym_document] = "document",
  [sym_paragraph_segment] = "paragraph_segment",
  [sym_paragraph] = "paragraph",
  [sym_non_structural] = "non_structural",
  [sym_heading1] = "heading1",
  [sym_heading2] = "heading2",
  [sym_heading3] = "heading3",
  [sym_heading4] = "heading4",
  [sym_heading5] = "heading5",
  [aux_sym_document_repeat1] = "document_repeat1",
  [aux_sym_paragraph_segment_repeat1] = "paragraph_segment_repeat1",
  [aux_sym_paragraph_repeat1] = "paragraph_repeat1",
  [aux_sym_heading1_repeat1] = "heading1_repeat1",
  [aux_sym_heading2_repeat1] = "heading2_repeat1",
  [aux_sym_heading3_repeat1] = "heading3_repeat1",
  [aux_sym_heading4_repeat1] = "heading4_repeat1",
  [aux_sym_heading5_repeat1] = "heading5_repeat1",
};

static const TSSymbol ts_symbol_map[] = {
  [ts_builtin_sym_end] = ts_builtin_sym_end,
  [sym_word] = sym_word,
  [sym_whitespace] = sym_whitespace,
  [sym_paragraph_break] = sym_paragraph_break,
  [anon_sym_LF] = anon_sym_LF,
  [anon_sym_STAR] = anon_sym_STAR,
  [aux_sym_heading1_token1] = aux_sym_heading1_token1,
  [anon_sym_STAR_STAR] = anon_sym_STAR_STAR,
  [anon_sym_STAR_STAR_STAR] = anon_sym_STAR_STAR_STAR,
  [anon_sym_STAR_STAR_STAR_STAR] = anon_sym_STAR_STAR_STAR_STAR,
  [anon_sym_STAR_STAR_STAR_STAR_STAR] = anon_sym_STAR_STAR_STAR_STAR_STAR,
  [anon_sym_STAR_STAR_STAR_STAR_STAR_STAR] = anon_sym_STAR_STAR_STAR_STAR_STAR_STAR,
  [sym_document] = sym_document,
  [sym_paragraph_segment] = sym_paragraph_segment,
  [sym_paragraph] = sym_paragraph,
  [sym_non_structural] = sym_non_structural,
  [sym_heading1] = sym_heading1,
  [sym_heading2] = sym_heading2,
  [sym_heading3] = sym_heading3,
  [sym_heading4] = sym_heading4,
  [sym_heading5] = sym_heading5,
  [aux_sym_document_repeat1] = aux_sym_document_repeat1,
  [aux_sym_paragraph_segment_repeat1] = aux_sym_paragraph_segment_repeat1,
  [aux_sym_paragraph_repeat1] = aux_sym_paragraph_repeat1,
  [aux_sym_heading1_repeat1] = aux_sym_heading1_repeat1,
  [aux_sym_heading2_repeat1] = aux_sym_heading2_repeat1,
  [aux_sym_heading3_repeat1] = aux_sym_heading3_repeat1,
  [aux_sym_heading4_repeat1] = aux_sym_heading4_repeat1,
  [aux_sym_heading5_repeat1] = aux_sym_heading5_repeat1,
};

static const TSSymbolMetadata ts_symbol_metadata[] = {
  [ts_builtin_sym_end] = {
    .visible = false,
    .named = true,
  },
  [sym_word] = {
    .visible = true,
    .named = true,
  },
  [sym_whitespace] = {
    .visible = true,
    .named = true,
  },
  [sym_paragraph_break] = {
    .visible = true,
    .named = true,
  },
  [anon_sym_LF] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_STAR] = {
    .visible = true,
    .named = false,
  },
  [aux_sym_heading1_token1] = {
    .visible = false,
    .named = false,
  },
  [anon_sym_STAR_STAR] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_STAR_STAR_STAR] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_STAR_STAR_STAR_STAR] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_STAR_STAR_STAR_STAR_STAR] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_STAR_STAR_STAR_STAR_STAR_STAR] = {
    .visible = true,
    .named = false,
  },
  [sym_document] = {
    .visible = true,
    .named = true,
  },
  [sym_paragraph_segment] = {
    .visible = true,
    .named = true,
  },
  [sym_paragraph] = {
    .visible = true,
    .named = true,
  },
  [sym_non_structural] = {
    .visible = false,
    .named = true,
    .supertype = true,
  },
  [sym_heading1] = {
    .visible = true,
    .named = true,
  },
  [sym_heading2] = {
    .visible = true,
    .named = true,
  },
  [sym_heading3] = {
    .visible = true,
    .named = true,
  },
  [sym_heading4] = {
    .visible = true,
    .named = true,
  },
  [sym_heading5] = {
    .visible = true,
    .named = true,
  },
  [aux_sym_document_repeat1] = {
    .visible = false,
    .named = false,
  },
  [aux_sym_paragraph_segment_repeat1] = {
    .visible = false,
    .named = false,
  },
  [aux_sym_paragraph_repeat1] = {
    .visible = false,
    .named = false,
  },
  [aux_sym_heading1_repeat1] = {
    .visible = false,
    .named = false,
  },
  [aux_sym_heading2_repeat1] = {
    .visible = false,
    .named = false,
  },
  [aux_sym_heading3_repeat1] = {
    .visible = false,
    .named = false,
  },
  [aux_sym_heading4_repeat1] = {
    .visible = false,
    .named = false,
  },
  [aux_sym_heading5_repeat1] = {
    .visible = false,
    .named = false,
  },
};

enum {
  field_content = 1,
  field_title = 2,
};

static const char * const ts_field_names[] = {
  [0] = NULL,
  [field_content] = "content",
  [field_title] = "title",
};

static const TSFieldMapSlice ts_field_map_slices[PRODUCTION_ID_COUNT] = {
  [1] = {.index = 0, .length = 1},
  [2] = {.index = 1, .length = 2},
};

static const TSFieldMapEntry ts_field_map_entries[] = {
  [0] =
    {field_title, 2},
  [1] =
    {field_content, 4},
    {field_title, 2},
};

static const TSSymbol ts_alias_sequences[PRODUCTION_ID_COUNT][MAX_ALIAS_SEQUENCE_LENGTH] = {
  [0] = {0},
};

static const uint16_t ts_non_terminal_alias_map[] = {
  0,
};

static const TSStateId ts_primary_state_ids[STATE_COUNT] = {
  [0] = 0,
  [1] = 1,
  [2] = 2,
  [3] = 3,
  [4] = 4,
  [5] = 5,
  [6] = 6,
  [7] = 7,
  [8] = 8,
  [9] = 9,
  [10] = 10,
  [11] = 11,
  [12] = 12,
  [13] = 13,
  [14] = 14,
  [15] = 15,
  [16] = 16,
  [17] = 17,
  [18] = 18,
  [19] = 19,
  [20] = 20,
  [21] = 21,
  [22] = 22,
  [23] = 18,
  [24] = 17,
  [25] = 25,
  [26] = 22,
  [27] = 27,
  [28] = 28,
  [29] = 29,
  [30] = 30,
  [31] = 31,
  [32] = 32,
  [33] = 33,
  [34] = 34,
  [35] = 35,
  [36] = 36,
  [37] = 37,
  [38] = 38,
  [39] = 39,
  [40] = 40,
  [41] = 41,
  [42] = 42,
  [43] = 43,
  [44] = 44,
  [45] = 45,
  [46] = 43,
};

static bool ts_lex(TSLexer *lexer, TSStateId state) {
  START_LEXER();
  eof = lexer->eof(lexer);
  switch (state) {
    case 0:
      if (eof) ADVANCE(7);
      if (lookahead == '*') ADVANCE(14);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') SKIP(0)
      if (lookahead != 0) ADVANCE(9);
      END_STATE();
    case 1:
      if (lookahead == '\n') ADVANCE(13);
      if (lookahead == '\r') SKIP(2)
      if (lookahead == '\t' ||
          lookahead == ' ') ADVANCE(10);
      if (lookahead == 160 ||
          lookahead == 5760 ||
          (8192 <= lookahead && lookahead <= 8202) ||
          lookahead == 8239 ||
          lookahead == 8287 ||
          lookahead == 12288) ADVANCE(8);
      if (lookahead != 0) ADVANCE(9);
      END_STATE();
    case 2:
      if (lookahead == '\t' ||
          lookahead == ' ') ADVANCE(10);
      if (lookahead == '\n' ||
          lookahead == '\r') SKIP(2)
      if (lookahead == 160 ||
          lookahead == 5760 ||
          (8192 <= lookahead && lookahead <= 8202) ||
          lookahead == 8239 ||
          lookahead == 8287 ||
          lookahead == 12288) ADVANCE(8);
      if (lookahead != 0) ADVANCE(9);
      END_STATE();
    case 3:
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') SKIP(3)
      if (lookahead != 0) ADVANCE(9);
      END_STATE();
    case 4:
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') ADVANCE(17);
      END_STATE();
    case 5:
      if (eof) ADVANCE(7);
      if (lookahead == '\n') ADVANCE(12);
      if (lookahead == '*') ADVANCE(16);
      if (lookahead == '\t' ||
          lookahead == '\r' ||
          lookahead == ' ') SKIP(5)
      if (lookahead != 0) ADVANCE(9);
      END_STATE();
    case 6:
      if (eof) ADVANCE(7);
      if (lookahead == '\n') ADVANCE(12);
      if (lookahead == '*') ADVANCE(15);
      if (lookahead == '\t' ||
          lookahead == '\r' ||
          lookahead == ' ') SKIP(6)
      if (lookahead != 0) ADVANCE(9);
      END_STATE();
    case 7:
      ACCEPT_TOKEN(ts_builtin_sym_end);
      END_STATE();
    case 8:
      ACCEPT_TOKEN(sym_word);
      if (lookahead == '\t' ||
          lookahead == ' ') ADVANCE(11);
      if (lookahead == 160 ||
          lookahead == 5760 ||
          (8192 <= lookahead && lookahead <= 8202) ||
          lookahead == 8239 ||
          lookahead == 8287 ||
          lookahead == 12288) ADVANCE(8);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r') ADVANCE(9);
      END_STATE();
    case 9:
      ACCEPT_TOKEN(sym_word);
      if (lookahead != 0 &&
          lookahead != '\t' &&
          lookahead != '\n' &&
          lookahead != '\r' &&
          lookahead != ' ') ADVANCE(9);
      END_STATE();
    case 10:
      ACCEPT_TOKEN(sym_whitespace);
      if (lookahead == '\t' ||
          lookahead == ' ') ADVANCE(10);
      if (lookahead == 160 ||
          lookahead == 5760 ||
          (8192 <= lookahead && lookahead <= 8202) ||
          lookahead == 8239 ||
          lookahead == 8287 ||
          lookahead == 12288) ADVANCE(8);
      END_STATE();
    case 11:
      ACCEPT_TOKEN(sym_whitespace);
      if (lookahead == '\t' ||
          lookahead == ' ' ||
          lookahead == 160 ||
          lookahead == 5760 ||
          (8192 <= lookahead && lookahead <= 8202) ||
          lookahead == 8239 ||
          lookahead == 8287 ||
          lookahead == 12288) ADVANCE(11);
      END_STATE();
    case 12:
      ACCEPT_TOKEN(sym_paragraph_break);
      if (lookahead == '\n') ADVANCE(12);
      END_STATE();
    case 13:
      ACCEPT_TOKEN(anon_sym_LF);
      END_STATE();
    case 14:
      ACCEPT_TOKEN(anon_sym_STAR);
      if (lookahead == '*') ADVANCE(18);
      if (lookahead != 0 &&
          lookahead != '\t' &&
          lookahead != '\n' &&
          lookahead != '\r' &&
          lookahead != ' ') ADVANCE(9);
      END_STATE();
    case 15:
      ACCEPT_TOKEN(anon_sym_STAR);
      if (lookahead == '*') ADVANCE(19);
      if (lookahead != 0 &&
          lookahead != '\t' &&
          lookahead != '\n' &&
          lookahead != '\r' &&
          lookahead != ' ') ADVANCE(9);
      END_STATE();
    case 16:
      ACCEPT_TOKEN(anon_sym_STAR);
      if (lookahead != 0 &&
          lookahead != '\t' &&
          lookahead != '\n' &&
          lookahead != '\r' &&
          lookahead != ' ') ADVANCE(9);
      END_STATE();
    case 17:
      ACCEPT_TOKEN(aux_sym_heading1_token1);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') ADVANCE(17);
      END_STATE();
    case 18:
      ACCEPT_TOKEN(anon_sym_STAR_STAR);
      if (lookahead == '*') ADVANCE(20);
      if (lookahead != 0 &&
          lookahead != '\t' &&
          lookahead != '\n' &&
          lookahead != '\r' &&
          lookahead != ' ') ADVANCE(9);
      END_STATE();
    case 19:
      ACCEPT_TOKEN(anon_sym_STAR_STAR);
      if (lookahead == '*') ADVANCE(21);
      if (lookahead != 0 &&
          lookahead != '\t' &&
          lookahead != '\n' &&
          lookahead != '\r' &&
          lookahead != ' ') ADVANCE(9);
      END_STATE();
    case 20:
      ACCEPT_TOKEN(anon_sym_STAR_STAR_STAR);
      if (lookahead == '*') ADVANCE(22);
      if (lookahead != 0 &&
          lookahead != '\t' &&
          lookahead != '\n' &&
          lookahead != '\r' &&
          lookahead != ' ') ADVANCE(9);
      END_STATE();
    case 21:
      ACCEPT_TOKEN(anon_sym_STAR_STAR_STAR);
      if (lookahead == '*') ADVANCE(23);
      if (lookahead != 0 &&
          lookahead != '\t' &&
          lookahead != '\n' &&
          lookahead != '\r' &&
          lookahead != ' ') ADVANCE(9);
      END_STATE();
    case 22:
      ACCEPT_TOKEN(anon_sym_STAR_STAR_STAR_STAR);
      if (lookahead == '*') ADVANCE(24);
      if (lookahead != 0 &&
          lookahead != '\t' &&
          lookahead != '\n' &&
          lookahead != '\r' &&
          lookahead != ' ') ADVANCE(9);
      END_STATE();
    case 23:
      ACCEPT_TOKEN(anon_sym_STAR_STAR_STAR_STAR);
      if (lookahead == '*') ADVANCE(25);
      if (lookahead != 0 &&
          lookahead != '\t' &&
          lookahead != '\n' &&
          lookahead != '\r' &&
          lookahead != ' ') ADVANCE(9);
      END_STATE();
    case 24:
      ACCEPT_TOKEN(anon_sym_STAR_STAR_STAR_STAR_STAR);
      if (lookahead == '*') ADVANCE(26);
      if (lookahead != 0 &&
          lookahead != '\t' &&
          lookahead != '\n' &&
          lookahead != '\r' &&
          lookahead != ' ') ADVANCE(9);
      END_STATE();
    case 25:
      ACCEPT_TOKEN(anon_sym_STAR_STAR_STAR_STAR_STAR);
      if (lookahead != 0 &&
          lookahead != '\t' &&
          lookahead != '\n' &&
          lookahead != '\r' &&
          lookahead != ' ') ADVANCE(9);
      END_STATE();
    case 26:
      ACCEPT_TOKEN(anon_sym_STAR_STAR_STAR_STAR_STAR_STAR);
      if (lookahead != 0 &&
          lookahead != '\t' &&
          lookahead != '\n' &&
          lookahead != '\r' &&
          lookahead != ' ') ADVANCE(9);
      END_STATE();
    default:
      return false;
  }
}

static const TSLexMode ts_lex_modes[STATE_COUNT] = {
  [0] = {.lex_state = 0},
  [1] = {.lex_state = 5},
  [2] = {.lex_state = 6},
  [3] = {.lex_state = 6},
  [4] = {.lex_state = 6},
  [5] = {.lex_state = 6},
  [6] = {.lex_state = 6},
  [7] = {.lex_state = 6},
  [8] = {.lex_state = 6},
  [9] = {.lex_state = 6},
  [10] = {.lex_state = 6},
  [11] = {.lex_state = 6},
  [12] = {.lex_state = 6},
  [13] = {.lex_state = 6},
  [14] = {.lex_state = 6},
  [15] = {.lex_state = 6},
  [16] = {.lex_state = 6},
  [17] = {.lex_state = 6},
  [18] = {.lex_state = 6},
  [19] = {.lex_state = 5},
  [20] = {.lex_state = 5},
  [21] = {.lex_state = 6},
  [22] = {.lex_state = 6},
  [23] = {.lex_state = 5},
  [24] = {.lex_state = 5},
  [25] = {.lex_state = 1},
  [26] = {.lex_state = 5},
  [27] = {.lex_state = 1},
  [28] = {.lex_state = 1},
  [29] = {.lex_state = 3},
  [30] = {.lex_state = 3},
  [31] = {.lex_state = 3},
  [32] = {.lex_state = 3},
  [33] = {.lex_state = 3},
  [34] = {.lex_state = 1},
  [35] = {.lex_state = 4},
  [36] = {.lex_state = 4},
  [37] = {.lex_state = 4},
  [38] = {.lex_state = 1},
  [39] = {.lex_state = 1},
  [40] = {.lex_state = 1},
  [41] = {.lex_state = 1},
  [42] = {.lex_state = 4},
  [43] = {.lex_state = 1},
  [44] = {.lex_state = 0},
  [45] = {.lex_state = 4},
  [46] = {.lex_state = 1},
};

static const uint16_t ts_parse_table[LARGE_STATE_COUNT][SYMBOL_COUNT] = {
  [0] = {
    [ts_builtin_sym_end] = ACTIONS(1),
    [sym_word] = ACTIONS(1),
    [anon_sym_STAR] = ACTIONS(1),
    [anon_sym_STAR_STAR] = ACTIONS(1),
    [anon_sym_STAR_STAR_STAR] = ACTIONS(1),
    [anon_sym_STAR_STAR_STAR_STAR] = ACTIONS(1),
    [anon_sym_STAR_STAR_STAR_STAR_STAR] = ACTIONS(1),
    [anon_sym_STAR_STAR_STAR_STAR_STAR_STAR] = ACTIONS(1),
  },
  [1] = {
    [sym_document] = STATE(44),
    [sym_paragraph_segment] = STATE(43),
    [sym_paragraph] = STATE(20),
    [sym_heading1] = STATE(20),
    [aux_sym_document_repeat1] = STATE(20),
    [aux_sym_paragraph_repeat1] = STATE(23),
    [ts_builtin_sym_end] = ACTIONS(3),
    [sym_word] = ACTIONS(5),
    [sym_paragraph_break] = ACTIONS(7),
    [anon_sym_STAR] = ACTIONS(9),
  },
  [2] = {
    [sym_paragraph_segment] = STATE(46),
    [sym_paragraph] = STATE(21),
    [sym_non_structural] = STATE(4),
    [sym_heading1] = STATE(4),
    [sym_heading2] = STATE(4),
    [sym_heading3] = STATE(4),
    [sym_heading4] = STATE(4),
    [sym_heading5] = STATE(4),
    [aux_sym_paragraph_repeat1] = STATE(18),
    [aux_sym_heading1_repeat1] = STATE(4),
    [ts_builtin_sym_end] = ACTIONS(11),
    [sym_word] = ACTIONS(5),
    [sym_paragraph_break] = ACTIONS(13),
    [anon_sym_STAR] = ACTIONS(9),
    [anon_sym_STAR_STAR] = ACTIONS(15),
    [anon_sym_STAR_STAR_STAR] = ACTIONS(17),
    [anon_sym_STAR_STAR_STAR_STAR] = ACTIONS(19),
    [anon_sym_STAR_STAR_STAR_STAR_STAR] = ACTIONS(21),
  },
  [3] = {
    [sym_paragraph_segment] = STATE(46),
    [sym_paragraph] = STATE(21),
    [sym_non_structural] = STATE(2),
    [sym_heading1] = STATE(2),
    [sym_heading2] = STATE(2),
    [sym_heading3] = STATE(2),
    [sym_heading4] = STATE(2),
    [sym_heading5] = STATE(2),
    [aux_sym_paragraph_repeat1] = STATE(18),
    [aux_sym_heading1_repeat1] = STATE(2),
    [ts_builtin_sym_end] = ACTIONS(23),
    [sym_word] = ACTIONS(5),
    [sym_paragraph_break] = ACTIONS(13),
    [anon_sym_STAR] = ACTIONS(9),
    [anon_sym_STAR_STAR] = ACTIONS(15),
    [anon_sym_STAR_STAR_STAR] = ACTIONS(17),
    [anon_sym_STAR_STAR_STAR_STAR] = ACTIONS(19),
    [anon_sym_STAR_STAR_STAR_STAR_STAR] = ACTIONS(21),
  },
  [4] = {
    [sym_paragraph_segment] = STATE(46),
    [sym_paragraph] = STATE(21),
    [sym_non_structural] = STATE(4),
    [sym_heading1] = STATE(4),
    [sym_heading2] = STATE(4),
    [sym_heading3] = STATE(4),
    [sym_heading4] = STATE(4),
    [sym_heading5] = STATE(4),
    [aux_sym_paragraph_repeat1] = STATE(18),
    [aux_sym_heading1_repeat1] = STATE(4),
    [ts_builtin_sym_end] = ACTIONS(25),
    [sym_word] = ACTIONS(27),
    [sym_paragraph_break] = ACTIONS(30),
    [anon_sym_STAR] = ACTIONS(33),
    [anon_sym_STAR_STAR] = ACTIONS(36),
    [anon_sym_STAR_STAR_STAR] = ACTIONS(39),
    [anon_sym_STAR_STAR_STAR_STAR] = ACTIONS(42),
    [anon_sym_STAR_STAR_STAR_STAR_STAR] = ACTIONS(45),
  },
  [5] = {
    [sym_paragraph_segment] = STATE(46),
    [sym_paragraph] = STATE(21),
    [sym_non_structural] = STATE(5),
    [sym_heading2] = STATE(5),
    [sym_heading3] = STATE(5),
    [sym_heading4] = STATE(5),
    [sym_heading5] = STATE(5),
    [aux_sym_paragraph_repeat1] = STATE(18),
    [aux_sym_heading2_repeat1] = STATE(5),
    [ts_builtin_sym_end] = ACTIONS(48),
    [sym_word] = ACTIONS(50),
    [sym_paragraph_break] = ACTIONS(53),
    [anon_sym_STAR] = ACTIONS(56),
    [anon_sym_STAR_STAR] = ACTIONS(58),
    [anon_sym_STAR_STAR_STAR] = ACTIONS(61),
    [anon_sym_STAR_STAR_STAR_STAR] = ACTIONS(64),
    [anon_sym_STAR_STAR_STAR_STAR_STAR] = ACTIONS(67),
  },
  [6] = {
    [sym_paragraph_segment] = STATE(46),
    [sym_paragraph] = STATE(21),
    [sym_non_structural] = STATE(5),
    [sym_heading2] = STATE(5),
    [sym_heading3] = STATE(5),
    [sym_heading4] = STATE(5),
    [sym_heading5] = STATE(5),
    [aux_sym_paragraph_repeat1] = STATE(18),
    [aux_sym_heading2_repeat1] = STATE(5),
    [ts_builtin_sym_end] = ACTIONS(70),
    [sym_word] = ACTIONS(5),
    [sym_paragraph_break] = ACTIONS(13),
    [anon_sym_STAR] = ACTIONS(72),
    [anon_sym_STAR_STAR] = ACTIONS(15),
    [anon_sym_STAR_STAR_STAR] = ACTIONS(17),
    [anon_sym_STAR_STAR_STAR_STAR] = ACTIONS(19),
    [anon_sym_STAR_STAR_STAR_STAR_STAR] = ACTIONS(21),
  },
  [7] = {
    [sym_paragraph_segment] = STATE(46),
    [sym_paragraph] = STATE(21),
    [sym_non_structural] = STATE(6),
    [sym_heading2] = STATE(6),
    [sym_heading3] = STATE(6),
    [sym_heading4] = STATE(6),
    [sym_heading5] = STATE(6),
    [aux_sym_paragraph_repeat1] = STATE(18),
    [aux_sym_heading2_repeat1] = STATE(6),
    [ts_builtin_sym_end] = ACTIONS(74),
    [sym_word] = ACTIONS(5),
    [sym_paragraph_break] = ACTIONS(13),
    [anon_sym_STAR] = ACTIONS(76),
    [anon_sym_STAR_STAR] = ACTIONS(15),
    [anon_sym_STAR_STAR_STAR] = ACTIONS(17),
    [anon_sym_STAR_STAR_STAR_STAR] = ACTIONS(19),
    [anon_sym_STAR_STAR_STAR_STAR_STAR] = ACTIONS(21),
  },
  [8] = {
    [sym_paragraph_segment] = STATE(46),
    [sym_paragraph] = STATE(21),
    [sym_non_structural] = STATE(8),
    [sym_heading3] = STATE(8),
    [sym_heading4] = STATE(8),
    [sym_heading5] = STATE(8),
    [aux_sym_paragraph_repeat1] = STATE(18),
    [aux_sym_heading3_repeat1] = STATE(8),
    [ts_builtin_sym_end] = ACTIONS(78),
    [sym_word] = ACTIONS(80),
    [sym_paragraph_break] = ACTIONS(83),
    [anon_sym_STAR] = ACTIONS(86),
    [anon_sym_STAR_STAR] = ACTIONS(86),
    [anon_sym_STAR_STAR_STAR] = ACTIONS(88),
    [anon_sym_STAR_STAR_STAR_STAR] = ACTIONS(91),
    [anon_sym_STAR_STAR_STAR_STAR_STAR] = ACTIONS(94),
  },
  [9] = {
    [sym_paragraph_segment] = STATE(46),
    [sym_paragraph] = STATE(21),
    [sym_non_structural] = STATE(8),
    [sym_heading3] = STATE(8),
    [sym_heading4] = STATE(8),
    [sym_heading5] = STATE(8),
    [aux_sym_paragraph_repeat1] = STATE(18),
    [aux_sym_heading3_repeat1] = STATE(8),
    [ts_builtin_sym_end] = ACTIONS(97),
    [sym_word] = ACTIONS(5),
    [sym_paragraph_break] = ACTIONS(13),
    [anon_sym_STAR] = ACTIONS(99),
    [anon_sym_STAR_STAR] = ACTIONS(99),
    [anon_sym_STAR_STAR_STAR] = ACTIONS(17),
    [anon_sym_STAR_STAR_STAR_STAR] = ACTIONS(19),
    [anon_sym_STAR_STAR_STAR_STAR_STAR] = ACTIONS(21),
  },
  [10] = {
    [sym_paragraph_segment] = STATE(46),
    [sym_paragraph] = STATE(21),
    [sym_non_structural] = STATE(9),
    [sym_heading3] = STATE(9),
    [sym_heading4] = STATE(9),
    [sym_heading5] = STATE(9),
    [aux_sym_paragraph_repeat1] = STATE(18),
    [aux_sym_heading3_repeat1] = STATE(9),
    [ts_builtin_sym_end] = ACTIONS(101),
    [sym_word] = ACTIONS(5),
    [sym_paragraph_break] = ACTIONS(13),
    [anon_sym_STAR] = ACTIONS(103),
    [anon_sym_STAR_STAR] = ACTIONS(103),
    [anon_sym_STAR_STAR_STAR] = ACTIONS(17),
    [anon_sym_STAR_STAR_STAR_STAR] = ACTIONS(19),
    [anon_sym_STAR_STAR_STAR_STAR_STAR] = ACTIONS(21),
  },
  [11] = {
    [sym_paragraph_segment] = STATE(46),
    [sym_paragraph] = STATE(21),
    [sym_non_structural] = STATE(11),
    [sym_heading4] = STATE(11),
    [sym_heading5] = STATE(11),
    [aux_sym_paragraph_repeat1] = STATE(18),
    [aux_sym_heading4_repeat1] = STATE(11),
    [ts_builtin_sym_end] = ACTIONS(105),
    [sym_word] = ACTIONS(107),
    [sym_paragraph_break] = ACTIONS(110),
    [anon_sym_STAR] = ACTIONS(113),
    [anon_sym_STAR_STAR] = ACTIONS(113),
    [anon_sym_STAR_STAR_STAR] = ACTIONS(113),
    [anon_sym_STAR_STAR_STAR_STAR] = ACTIONS(115),
    [anon_sym_STAR_STAR_STAR_STAR_STAR] = ACTIONS(118),
  },
  [12] = {
    [sym_paragraph_segment] = STATE(46),
    [sym_paragraph] = STATE(21),
    [sym_non_structural] = STATE(11),
    [sym_heading4] = STATE(11),
    [sym_heading5] = STATE(11),
    [aux_sym_paragraph_repeat1] = STATE(18),
    [aux_sym_heading4_repeat1] = STATE(11),
    [ts_builtin_sym_end] = ACTIONS(121),
    [sym_word] = ACTIONS(5),
    [sym_paragraph_break] = ACTIONS(13),
    [anon_sym_STAR] = ACTIONS(123),
    [anon_sym_STAR_STAR] = ACTIONS(123),
    [anon_sym_STAR_STAR_STAR] = ACTIONS(123),
    [anon_sym_STAR_STAR_STAR_STAR] = ACTIONS(19),
    [anon_sym_STAR_STAR_STAR_STAR_STAR] = ACTIONS(21),
  },
  [13] = {
    [sym_paragraph_segment] = STATE(46),
    [sym_paragraph] = STATE(21),
    [sym_non_structural] = STATE(12),
    [sym_heading4] = STATE(12),
    [sym_heading5] = STATE(12),
    [aux_sym_paragraph_repeat1] = STATE(18),
    [aux_sym_heading4_repeat1] = STATE(12),
    [ts_builtin_sym_end] = ACTIONS(125),
    [sym_word] = ACTIONS(5),
    [sym_paragraph_break] = ACTIONS(13),
    [anon_sym_STAR] = ACTIONS(127),
    [anon_sym_STAR_STAR] = ACTIONS(127),
    [anon_sym_STAR_STAR_STAR] = ACTIONS(127),
    [anon_sym_STAR_STAR_STAR_STAR] = ACTIONS(19),
    [anon_sym_STAR_STAR_STAR_STAR_STAR] = ACTIONS(21),
  },
};

static const uint16_t ts_small_parse_table[] = {
  [0] = 9,
    ACTIONS(129), 1,
      ts_builtin_sym_end,
    ACTIONS(131), 1,
      sym_word,
    ACTIONS(134), 1,
      sym_paragraph_break,
    ACTIONS(139), 1,
      anon_sym_STAR_STAR_STAR_STAR_STAR,
    STATE(18), 1,
      aux_sym_paragraph_repeat1,
    STATE(21), 1,
      sym_paragraph,
    STATE(46), 1,
      sym_paragraph_segment,
    STATE(14), 3,
      sym_non_structural,
      sym_heading5,
      aux_sym_heading5_repeat1,
    ACTIONS(137), 4,
      anon_sym_STAR,
      anon_sym_STAR_STAR,
      anon_sym_STAR_STAR_STAR,
      anon_sym_STAR_STAR_STAR_STAR,
  [33] = 9,
    ACTIONS(5), 1,
      sym_word,
    ACTIONS(13), 1,
      sym_paragraph_break,
    ACTIONS(21), 1,
      anon_sym_STAR_STAR_STAR_STAR_STAR,
    ACTIONS(142), 1,
      ts_builtin_sym_end,
    STATE(18), 1,
      aux_sym_paragraph_repeat1,
    STATE(21), 1,
      sym_paragraph,
    STATE(46), 1,
      sym_paragraph_segment,
    STATE(14), 3,
      sym_non_structural,
      sym_heading5,
      aux_sym_heading5_repeat1,
    ACTIONS(144), 4,
      anon_sym_STAR,
      anon_sym_STAR_STAR,
      anon_sym_STAR_STAR_STAR,
      anon_sym_STAR_STAR_STAR_STAR,
  [66] = 9,
    ACTIONS(5), 1,
      sym_word,
    ACTIONS(13), 1,
      sym_paragraph_break,
    ACTIONS(21), 1,
      anon_sym_STAR_STAR_STAR_STAR_STAR,
    ACTIONS(146), 1,
      ts_builtin_sym_end,
    STATE(18), 1,
      aux_sym_paragraph_repeat1,
    STATE(21), 1,
      sym_paragraph,
    STATE(46), 1,
      sym_paragraph_segment,
    STATE(15), 3,
      sym_non_structural,
      sym_heading5,
      aux_sym_heading5_repeat1,
    ACTIONS(148), 4,
      anon_sym_STAR,
      anon_sym_STAR_STAR,
      anon_sym_STAR_STAR_STAR,
      anon_sym_STAR_STAR_STAR_STAR,
  [99] = 5,
    ACTIONS(152), 1,
      sym_word,
    STATE(17), 1,
      aux_sym_paragraph_repeat1,
    STATE(46), 1,
      sym_paragraph_segment,
    ACTIONS(150), 2,
      ts_builtin_sym_end,
      sym_paragraph_break,
    ACTIONS(155), 5,
      anon_sym_STAR,
      anon_sym_STAR_STAR,
      anon_sym_STAR_STAR_STAR,
      anon_sym_STAR_STAR_STAR_STAR,
      anon_sym_STAR_STAR_STAR_STAR_STAR,
  [120] = 5,
    ACTIONS(5), 1,
      sym_word,
    STATE(17), 1,
      aux_sym_paragraph_repeat1,
    STATE(46), 1,
      sym_paragraph_segment,
    ACTIONS(157), 2,
      ts_builtin_sym_end,
      sym_paragraph_break,
    ACTIONS(159), 5,
      anon_sym_STAR,
      anon_sym_STAR_STAR,
      anon_sym_STAR_STAR_STAR,
      anon_sym_STAR_STAR_STAR_STAR,
      anon_sym_STAR_STAR_STAR_STAR_STAR,
  [141] = 7,
    ACTIONS(161), 1,
      ts_builtin_sym_end,
    ACTIONS(163), 1,
      sym_word,
    ACTIONS(166), 1,
      sym_paragraph_break,
    ACTIONS(169), 1,
      anon_sym_STAR,
    STATE(23), 1,
      aux_sym_paragraph_repeat1,
    STATE(43), 1,
      sym_paragraph_segment,
    STATE(19), 3,
      sym_paragraph,
      sym_heading1,
      aux_sym_document_repeat1,
  [165] = 7,
    ACTIONS(5), 1,
      sym_word,
    ACTIONS(9), 1,
      anon_sym_STAR,
    ACTIONS(172), 1,
      ts_builtin_sym_end,
    ACTIONS(174), 1,
      sym_paragraph_break,
    STATE(23), 1,
      aux_sym_paragraph_repeat1,
    STATE(43), 1,
      sym_paragraph_segment,
    STATE(19), 3,
      sym_paragraph,
      sym_heading1,
      aux_sym_document_repeat1,
  [189] = 2,
    ACTIONS(176), 2,
      ts_builtin_sym_end,
      sym_paragraph_break,
    ACTIONS(178), 6,
      sym_word,
      anon_sym_STAR,
      anon_sym_STAR_STAR,
      anon_sym_STAR_STAR_STAR,
      anon_sym_STAR_STAR_STAR_STAR,
      anon_sym_STAR_STAR_STAR_STAR_STAR,
  [202] = 2,
    ACTIONS(150), 2,
      ts_builtin_sym_end,
      sym_paragraph_break,
    ACTIONS(155), 6,
      sym_word,
      anon_sym_STAR,
      anon_sym_STAR_STAR,
      anon_sym_STAR_STAR_STAR,
      anon_sym_STAR_STAR_STAR_STAR,
      anon_sym_STAR_STAR_STAR_STAR_STAR,
  [215] = 5,
    ACTIONS(5), 1,
      sym_word,
    ACTIONS(159), 1,
      anon_sym_STAR,
    STATE(24), 1,
      aux_sym_paragraph_repeat1,
    STATE(43), 1,
      sym_paragraph_segment,
    ACTIONS(157), 2,
      ts_builtin_sym_end,
      sym_paragraph_break,
  [232] = 5,
    ACTIONS(152), 1,
      sym_word,
    ACTIONS(155), 1,
      anon_sym_STAR,
    STATE(24), 1,
      aux_sym_paragraph_repeat1,
    STATE(43), 1,
      sym_paragraph_segment,
    ACTIONS(150), 2,
      ts_builtin_sym_end,
      sym_paragraph_break,
  [249] = 3,
    ACTIONS(182), 1,
      anon_sym_LF,
    STATE(28), 1,
      aux_sym_paragraph_segment_repeat1,
    ACTIONS(180), 2,
      sym_word,
      sym_whitespace,
  [260] = 2,
    ACTIONS(150), 2,
      ts_builtin_sym_end,
      sym_paragraph_break,
    ACTIONS(155), 2,
      sym_word,
      anon_sym_STAR,
  [269] = 3,
    ACTIONS(186), 1,
      anon_sym_LF,
    STATE(25), 1,
      aux_sym_paragraph_segment_repeat1,
    ACTIONS(184), 2,
      sym_word,
      sym_whitespace,
  [280] = 3,
    ACTIONS(191), 1,
      anon_sym_LF,
    STATE(28), 1,
      aux_sym_paragraph_segment_repeat1,
    ACTIONS(188), 2,
      sym_word,
      sym_whitespace,
  [291] = 2,
    ACTIONS(193), 1,
      sym_word,
    STATE(38), 1,
      sym_paragraph_segment,
  [298] = 2,
    ACTIONS(193), 1,
      sym_word,
    STATE(34), 1,
      sym_paragraph_segment,
  [305] = 2,
    ACTIONS(193), 1,
      sym_word,
    STATE(39), 1,
      sym_paragraph_segment,
  [312] = 2,
    ACTIONS(193), 1,
      sym_word,
    STATE(40), 1,
      sym_paragraph_segment,
  [319] = 2,
    ACTIONS(193), 1,
      sym_word,
    STATE(41), 1,
      sym_paragraph_segment,
  [326] = 1,
    ACTIONS(195), 1,
      anon_sym_LF,
  [330] = 1,
    ACTIONS(197), 1,
      aux_sym_heading1_token1,
  [334] = 1,
    ACTIONS(199), 1,
      aux_sym_heading1_token1,
  [338] = 1,
    ACTIONS(201), 1,
      aux_sym_heading1_token1,
  [342] = 1,
    ACTIONS(203), 1,
      anon_sym_LF,
  [346] = 1,
    ACTIONS(205), 1,
      anon_sym_LF,
  [350] = 1,
    ACTIONS(207), 1,
      anon_sym_LF,
  [354] = 1,
    ACTIONS(209), 1,
      anon_sym_LF,
  [358] = 1,
    ACTIONS(211), 1,
      aux_sym_heading1_token1,
  [362] = 1,
    ACTIONS(213), 1,
      anon_sym_LF,
  [366] = 1,
    ACTIONS(215), 1,
      ts_builtin_sym_end,
  [370] = 1,
    ACTIONS(217), 1,
      aux_sym_heading1_token1,
  [374] = 1,
    ACTIONS(219), 1,
      anon_sym_LF,
};

static const uint32_t ts_small_parse_table_map[] = {
  [SMALL_STATE(14)] = 0,
  [SMALL_STATE(15)] = 33,
  [SMALL_STATE(16)] = 66,
  [SMALL_STATE(17)] = 99,
  [SMALL_STATE(18)] = 120,
  [SMALL_STATE(19)] = 141,
  [SMALL_STATE(20)] = 165,
  [SMALL_STATE(21)] = 189,
  [SMALL_STATE(22)] = 202,
  [SMALL_STATE(23)] = 215,
  [SMALL_STATE(24)] = 232,
  [SMALL_STATE(25)] = 249,
  [SMALL_STATE(26)] = 260,
  [SMALL_STATE(27)] = 269,
  [SMALL_STATE(28)] = 280,
  [SMALL_STATE(29)] = 291,
  [SMALL_STATE(30)] = 298,
  [SMALL_STATE(31)] = 305,
  [SMALL_STATE(32)] = 312,
  [SMALL_STATE(33)] = 319,
  [SMALL_STATE(34)] = 326,
  [SMALL_STATE(35)] = 330,
  [SMALL_STATE(36)] = 334,
  [SMALL_STATE(37)] = 338,
  [SMALL_STATE(38)] = 342,
  [SMALL_STATE(39)] = 346,
  [SMALL_STATE(40)] = 350,
  [SMALL_STATE(41)] = 354,
  [SMALL_STATE(42)] = 358,
  [SMALL_STATE(43)] = 362,
  [SMALL_STATE(44)] = 366,
  [SMALL_STATE(45)] = 370,
  [SMALL_STATE(46)] = 374,
};

static const TSParseActionEntry ts_parse_actions[] = {
  [0] = {.entry = {.count = 0, .reusable = false}},
  [1] = {.entry = {.count = 1, .reusable = false}}, RECOVER(),
  [3] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_document, 0),
  [5] = {.entry = {.count = 1, .reusable = false}}, SHIFT(27),
  [7] = {.entry = {.count = 1, .reusable = true}}, SHIFT(20),
  [9] = {.entry = {.count = 1, .reusable = false}}, SHIFT(45),
  [11] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_heading1, 5, .production_id = 2),
  [13] = {.entry = {.count = 1, .reusable = true}}, SHIFT(21),
  [15] = {.entry = {.count = 1, .reusable = false}}, SHIFT(36),
  [17] = {.entry = {.count = 1, .reusable = false}}, SHIFT(35),
  [19] = {.entry = {.count = 1, .reusable = false}}, SHIFT(42),
  [21] = {.entry = {.count = 1, .reusable = false}}, SHIFT(37),
  [23] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_heading1, 4, .production_id = 1),
  [25] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_heading1_repeat1, 2),
  [27] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_heading1_repeat1, 2), SHIFT_REPEAT(27),
  [30] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_heading1_repeat1, 2), SHIFT_REPEAT(21),
  [33] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_heading1_repeat1, 2), SHIFT_REPEAT(45),
  [36] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_heading1_repeat1, 2), SHIFT_REPEAT(36),
  [39] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_heading1_repeat1, 2), SHIFT_REPEAT(35),
  [42] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_heading1_repeat1, 2), SHIFT_REPEAT(42),
  [45] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_heading1_repeat1, 2), SHIFT_REPEAT(37),
  [48] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_heading2_repeat1, 2),
  [50] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_heading2_repeat1, 2), SHIFT_REPEAT(27),
  [53] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_heading2_repeat1, 2), SHIFT_REPEAT(21),
  [56] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym_heading2_repeat1, 2),
  [58] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_heading2_repeat1, 2), SHIFT_REPEAT(36),
  [61] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_heading2_repeat1, 2), SHIFT_REPEAT(35),
  [64] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_heading2_repeat1, 2), SHIFT_REPEAT(42),
  [67] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_heading2_repeat1, 2), SHIFT_REPEAT(37),
  [70] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_heading2, 5, .production_id = 2),
  [72] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_heading2, 5, .production_id = 2),
  [74] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_heading2, 4, .production_id = 1),
  [76] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_heading2, 4, .production_id = 1),
  [78] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_heading3_repeat1, 2),
  [80] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_heading3_repeat1, 2), SHIFT_REPEAT(27),
  [83] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_heading3_repeat1, 2), SHIFT_REPEAT(21),
  [86] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym_heading3_repeat1, 2),
  [88] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_heading3_repeat1, 2), SHIFT_REPEAT(35),
  [91] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_heading3_repeat1, 2), SHIFT_REPEAT(42),
  [94] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_heading3_repeat1, 2), SHIFT_REPEAT(37),
  [97] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_heading3, 5, .production_id = 2),
  [99] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_heading3, 5, .production_id = 2),
  [101] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_heading3, 4, .production_id = 1),
  [103] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_heading3, 4, .production_id = 1),
  [105] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_heading4_repeat1, 2),
  [107] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_heading4_repeat1, 2), SHIFT_REPEAT(27),
  [110] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_heading4_repeat1, 2), SHIFT_REPEAT(21),
  [113] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym_heading4_repeat1, 2),
  [115] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_heading4_repeat1, 2), SHIFT_REPEAT(42),
  [118] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_heading4_repeat1, 2), SHIFT_REPEAT(37),
  [121] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_heading4, 5, .production_id = 2),
  [123] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_heading4, 5, .production_id = 2),
  [125] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_heading4, 4, .production_id = 1),
  [127] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_heading4, 4, .production_id = 1),
  [129] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_heading5_repeat1, 2),
  [131] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_heading5_repeat1, 2), SHIFT_REPEAT(27),
  [134] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_heading5_repeat1, 2), SHIFT_REPEAT(21),
  [137] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym_heading5_repeat1, 2),
  [139] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_heading5_repeat1, 2), SHIFT_REPEAT(37),
  [142] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_heading5, 5, .production_id = 2),
  [144] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_heading5, 5, .production_id = 2),
  [146] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_heading5, 4, .production_id = 1),
  [148] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_heading5, 4, .production_id = 1),
  [150] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_paragraph_repeat1, 2),
  [152] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_paragraph_repeat1, 2), SHIFT_REPEAT(27),
  [155] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym_paragraph_repeat1, 2),
  [157] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_paragraph, 1),
  [159] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_paragraph, 1),
  [161] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_document_repeat1, 2),
  [163] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_document_repeat1, 2), SHIFT_REPEAT(27),
  [166] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_document_repeat1, 2), SHIFT_REPEAT(19),
  [169] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_document_repeat1, 2), SHIFT_REPEAT(45),
  [172] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_document, 1),
  [174] = {.entry = {.count = 1, .reusable = true}}, SHIFT(19),
  [176] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_non_structural, 1),
  [178] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_non_structural, 1),
  [180] = {.entry = {.count = 1, .reusable = false}}, SHIFT(28),
  [182] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_paragraph_segment, 2),
  [184] = {.entry = {.count = 1, .reusable = false}}, SHIFT(25),
  [186] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_paragraph_segment, 1),
  [188] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_paragraph_segment_repeat1, 2), SHIFT_REPEAT(28),
  [191] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_paragraph_segment_repeat1, 2),
  [193] = {.entry = {.count = 1, .reusable = true}}, SHIFT(27),
  [195] = {.entry = {.count = 1, .reusable = true}}, SHIFT(16),
  [197] = {.entry = {.count = 1, .reusable = true}}, SHIFT(32),
  [199] = {.entry = {.count = 1, .reusable = true}}, SHIFT(33),
  [201] = {.entry = {.count = 1, .reusable = true}}, SHIFT(30),
  [203] = {.entry = {.count = 1, .reusable = true}}, SHIFT(3),
  [205] = {.entry = {.count = 1, .reusable = true}}, SHIFT(13),
  [207] = {.entry = {.count = 1, .reusable = true}}, SHIFT(10),
  [209] = {.entry = {.count = 1, .reusable = true}}, SHIFT(7),
  [211] = {.entry = {.count = 1, .reusable = true}}, SHIFT(31),
  [213] = {.entry = {.count = 1, .reusable = true}}, SHIFT(26),
  [215] = {.entry = {.count = 1, .reusable = true}},  ACCEPT_INPUT(),
  [217] = {.entry = {.count = 1, .reusable = true}}, SHIFT(29),
  [219] = {.entry = {.count = 1, .reusable = true}}, SHIFT(22),
};

#ifdef __cplusplus
extern "C" {
#endif
#ifdef _WIN32
#define extern __declspec(dllexport)
#endif

extern const TSLanguage *tree_sitter_norg(void) {
  static const TSLanguage language = {
    .version = LANGUAGE_VERSION,
    .symbol_count = SYMBOL_COUNT,
    .alias_count = ALIAS_COUNT,
    .token_count = TOKEN_COUNT,
    .external_token_count = EXTERNAL_TOKEN_COUNT,
    .state_count = STATE_COUNT,
    .large_state_count = LARGE_STATE_COUNT,
    .production_id_count = PRODUCTION_ID_COUNT,
    .field_count = FIELD_COUNT,
    .max_alias_sequence_length = MAX_ALIAS_SEQUENCE_LENGTH,
    .parse_table = &ts_parse_table[0][0],
    .small_parse_table = ts_small_parse_table,
    .small_parse_table_map = ts_small_parse_table_map,
    .parse_actions = ts_parse_actions,
    .symbol_names = ts_symbol_names,
    .field_names = ts_field_names,
    .field_map_slices = ts_field_map_slices,
    .field_map_entries = ts_field_map_entries,
    .symbol_metadata = ts_symbol_metadata,
    .public_symbol_map = ts_symbol_map,
    .alias_map = ts_non_terminal_alias_map,
    .alias_sequences = &ts_alias_sequences[0][0],
    .lex_modes = ts_lex_modes,
    .lex_fn = ts_lex,
    .primary_state_ids = ts_primary_state_ids,
  };
  return &language;
}
#ifdef __cplusplus
}
#endif
