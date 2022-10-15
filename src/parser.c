#include <tree_sitter/parser.h>

#if defined(__GNUC__) || defined(__clang__)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wmissing-field-initializers"
#endif

#define LANGUAGE_VERSION 14
#define STATE_COUNT 18
#define LARGE_STATE_COUNT 2
#define SYMBOL_COUNT 19
#define ALIAS_COUNT 0
#define TOKEN_COUNT 12
#define EXTERNAL_TOKEN_COUNT 0
#define FIELD_COUNT 0
#define MAX_ALIAS_SEQUENCE_LENGTH 3
#define PRODUCTION_ID_COUNT 1

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
  sym_heading1 = 15,
  aux_sym_document_repeat1 = 16,
  aux_sym_paragraph_segment_repeat1 = 17,
  aux_sym_paragraph_repeat1 = 18,
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
  [sym_heading1] = "heading1",
  [aux_sym_document_repeat1] = "document_repeat1",
  [aux_sym_paragraph_segment_repeat1] = "paragraph_segment_repeat1",
  [aux_sym_paragraph_repeat1] = "paragraph_repeat1",
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
  [sym_heading1] = sym_heading1,
  [aux_sym_document_repeat1] = aux_sym_document_repeat1,
  [aux_sym_paragraph_segment_repeat1] = aux_sym_paragraph_segment_repeat1,
  [aux_sym_paragraph_repeat1] = aux_sym_paragraph_repeat1,
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
  [sym_heading1] = {
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
  [9] = 6,
  [10] = 7,
  [11] = 11,
  [12] = 8,
  [13] = 13,
  [14] = 14,
  [15] = 15,
  [16] = 16,
  [17] = 17,
};

static bool ts_lex(TSLexer *lexer, TSStateId state) {
  START_LEXER();
  eof = lexer->eof(lexer);
  switch (state) {
    case 0:
      if (eof) ADVANCE(7);
      if (lookahead == '*') ADVANCE(16);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') SKIP(0)
      if (lookahead != 0) ADVANCE(9);
      END_STATE();
    case 1:
      if (lookahead == '\n') ADVANCE(15);
      if (lookahead == '\r') SKIP(2)
      if (lookahead == '\t' ||
          lookahead == ' ') ADVANCE(11);
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
          lookahead == ' ') ADVANCE(11);
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
          lookahead == ' ') ADVANCE(18);
      END_STATE();
    case 5:
      if (eof) ADVANCE(7);
      if (lookahead == '\n') ADVANCE(13);
      if (lookahead == '*') ADVANCE(17);
      if (lookahead == '\t' ||
          lookahead == '\r' ||
          lookahead == ' ') SKIP(5)
      if (lookahead != 0) ADVANCE(9);
      END_STATE();
    case 6:
      if (eof) ADVANCE(7);
      if (lookahead == '\n') ADVANCE(14);
      if (lookahead == '\r') SKIP(6)
      if (lookahead == '*') ADVANCE(17);
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
    case 7:
      ACCEPT_TOKEN(ts_builtin_sym_end);
      END_STATE();
    case 8:
      ACCEPT_TOKEN(sym_word);
      if (lookahead == '\t' ||
          lookahead == ' ') ADVANCE(12);
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
      if (lookahead == '\n') ADVANCE(14);
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
          lookahead == ' ') ADVANCE(11);
      if (lookahead == 160 ||
          lookahead == 5760 ||
          (8192 <= lookahead && lookahead <= 8202) ||
          lookahead == 8239 ||
          lookahead == 8287 ||
          lookahead == 12288) ADVANCE(8);
      END_STATE();
    case 12:
      ACCEPT_TOKEN(sym_whitespace);
      if (lookahead == '\t' ||
          lookahead == ' ' ||
          lookahead == 160 ||
          lookahead == 5760 ||
          (8192 <= lookahead && lookahead <= 8202) ||
          lookahead == 8239 ||
          lookahead == 8287 ||
          lookahead == 12288) ADVANCE(12);
      END_STATE();
    case 13:
      ACCEPT_TOKEN(sym_paragraph_break);
      if (lookahead == '\n') ADVANCE(13);
      END_STATE();
    case 14:
      ACCEPT_TOKEN(sym_paragraph_break);
      if (lookahead == '\n') ADVANCE(14);
      if (lookahead == '\t' ||
          lookahead == ' ') ADVANCE(10);
      END_STATE();
    case 15:
      ACCEPT_TOKEN(anon_sym_LF);
      END_STATE();
    case 16:
      ACCEPT_TOKEN(anon_sym_STAR);
      if (lookahead == '*') ADVANCE(19);
      if (lookahead != 0 &&
          lookahead != '\t' &&
          lookahead != '\n' &&
          lookahead != '\r' &&
          lookahead != ' ') ADVANCE(9);
      END_STATE();
    case 17:
      ACCEPT_TOKEN(anon_sym_STAR);
      if (lookahead != 0 &&
          lookahead != '\t' &&
          lookahead != '\n' &&
          lookahead != '\r' &&
          lookahead != ' ') ADVANCE(9);
      END_STATE();
    case 18:
      ACCEPT_TOKEN(aux_sym_heading1_token1);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') ADVANCE(18);
      END_STATE();
    case 19:
      ACCEPT_TOKEN(anon_sym_STAR_STAR);
      if (lookahead == '*') ADVANCE(20);
      if (lookahead != 0 &&
          lookahead != '\t' &&
          lookahead != '\n' &&
          lookahead != '\r' &&
          lookahead != ' ') ADVANCE(9);
      END_STATE();
    case 20:
      ACCEPT_TOKEN(anon_sym_STAR_STAR_STAR);
      if (lookahead == '*') ADVANCE(21);
      if (lookahead != 0 &&
          lookahead != '\t' &&
          lookahead != '\n' &&
          lookahead != '\r' &&
          lookahead != ' ') ADVANCE(9);
      END_STATE();
    case 21:
      ACCEPT_TOKEN(anon_sym_STAR_STAR_STAR_STAR);
      if (lookahead == '*') ADVANCE(22);
      if (lookahead != 0 &&
          lookahead != '\t' &&
          lookahead != '\n' &&
          lookahead != '\r' &&
          lookahead != ' ') ADVANCE(9);
      END_STATE();
    case 22:
      ACCEPT_TOKEN(anon_sym_STAR_STAR_STAR_STAR_STAR);
      if (lookahead == '*') ADVANCE(23);
      if (lookahead != 0 &&
          lookahead != '\t' &&
          lookahead != '\n' &&
          lookahead != '\r' &&
          lookahead != ' ') ADVANCE(9);
      END_STATE();
    case 23:
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
  [2] = {.lex_state = 5},
  [3] = {.lex_state = 5},
  [4] = {.lex_state = 5},
  [5] = {.lex_state = 5},
  [6] = {.lex_state = 6},
  [7] = {.lex_state = 6},
  [8] = {.lex_state = 6},
  [9] = {.lex_state = 1},
  [10] = {.lex_state = 1},
  [11] = {.lex_state = 5},
  [12] = {.lex_state = 1},
  [13] = {.lex_state = 5},
  [14] = {.lex_state = 3},
  [15] = {.lex_state = 4},
  [16] = {.lex_state = 0},
  [17] = {.lex_state = 1},
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
    [sym_document] = STATE(16),
    [sym_paragraph_segment] = STATE(17),
    [sym_paragraph] = STATE(2),
    [sym_heading1] = STATE(2),
    [aux_sym_document_repeat1] = STATE(2),
    [aux_sym_paragraph_repeat1] = STATE(4),
    [ts_builtin_sym_end] = ACTIONS(3),
    [sym_word] = ACTIONS(5),
    [sym_paragraph_break] = ACTIONS(7),
    [anon_sym_STAR] = ACTIONS(9),
  },
};

static const uint16_t ts_small_parse_table[] = {
  [0] = 7,
    ACTIONS(5), 1,
      sym_word,
    ACTIONS(9), 1,
      anon_sym_STAR,
    ACTIONS(11), 1,
      ts_builtin_sym_end,
    ACTIONS(13), 1,
      sym_paragraph_break,
    STATE(4), 1,
      aux_sym_paragraph_repeat1,
    STATE(17), 1,
      sym_paragraph_segment,
    STATE(3), 3,
      sym_paragraph,
      sym_heading1,
      aux_sym_document_repeat1,
  [24] = 7,
    ACTIONS(15), 1,
      ts_builtin_sym_end,
    ACTIONS(17), 1,
      sym_word,
    ACTIONS(20), 1,
      sym_paragraph_break,
    ACTIONS(23), 1,
      anon_sym_STAR,
    STATE(4), 1,
      aux_sym_paragraph_repeat1,
    STATE(17), 1,
      sym_paragraph_segment,
    STATE(3), 3,
      sym_paragraph,
      sym_heading1,
      aux_sym_document_repeat1,
  [48] = 5,
    ACTIONS(5), 1,
      sym_word,
    ACTIONS(28), 1,
      anon_sym_STAR,
    STATE(5), 1,
      aux_sym_paragraph_repeat1,
    STATE(17), 1,
      sym_paragraph_segment,
    ACTIONS(26), 2,
      ts_builtin_sym_end,
      sym_paragraph_break,
  [65] = 5,
    ACTIONS(32), 1,
      sym_word,
    ACTIONS(35), 1,
      anon_sym_STAR,
    STATE(5), 1,
      aux_sym_paragraph_repeat1,
    STATE(17), 1,
      sym_paragraph_segment,
    ACTIONS(30), 2,
      ts_builtin_sym_end,
      sym_paragraph_break,
  [82] = 4,
    ACTIONS(37), 1,
      ts_builtin_sym_end,
    STATE(7), 1,
      aux_sym_paragraph_segment_repeat1,
    ACTIONS(39), 2,
      sym_word,
      sym_whitespace,
    ACTIONS(41), 2,
      sym_paragraph_break,
      anon_sym_STAR,
  [97] = 4,
    ACTIONS(43), 1,
      ts_builtin_sym_end,
    ACTIONS(47), 1,
      sym_whitespace,
    STATE(8), 1,
      aux_sym_paragraph_segment_repeat1,
    ACTIONS(45), 3,
      sym_word,
      sym_paragraph_break,
      anon_sym_STAR,
  [112] = 4,
    ACTIONS(49), 1,
      ts_builtin_sym_end,
    STATE(8), 1,
      aux_sym_paragraph_segment_repeat1,
    ACTIONS(51), 2,
      sym_word,
      sym_whitespace,
    ACTIONS(54), 2,
      sym_paragraph_break,
      anon_sym_STAR,
  [127] = 3,
    ACTIONS(37), 1,
      anon_sym_LF,
    STATE(10), 1,
      aux_sym_paragraph_segment_repeat1,
    ACTIONS(56), 2,
      sym_word,
      sym_whitespace,
  [138] = 3,
    ACTIONS(43), 1,
      anon_sym_LF,
    STATE(12), 1,
      aux_sym_paragraph_segment_repeat1,
    ACTIONS(58), 2,
      sym_word,
      sym_whitespace,
  [149] = 2,
    ACTIONS(30), 2,
      ts_builtin_sym_end,
      sym_paragraph_break,
    ACTIONS(35), 2,
      sym_word,
      anon_sym_STAR,
  [158] = 3,
    ACTIONS(49), 1,
      anon_sym_LF,
    STATE(12), 1,
      aux_sym_paragraph_segment_repeat1,
    ACTIONS(60), 2,
      sym_word,
      sym_whitespace,
  [169] = 2,
    ACTIONS(63), 2,
      ts_builtin_sym_end,
      sym_paragraph_break,
    ACTIONS(65), 2,
      sym_word,
      anon_sym_STAR,
  [178] = 2,
    ACTIONS(67), 1,
      sym_word,
    STATE(13), 1,
      sym_paragraph_segment,
  [185] = 1,
    ACTIONS(69), 1,
      aux_sym_heading1_token1,
  [189] = 1,
    ACTIONS(71), 1,
      ts_builtin_sym_end,
  [193] = 1,
    ACTIONS(73), 1,
      anon_sym_LF,
};

static const uint32_t ts_small_parse_table_map[] = {
  [SMALL_STATE(2)] = 0,
  [SMALL_STATE(3)] = 24,
  [SMALL_STATE(4)] = 48,
  [SMALL_STATE(5)] = 65,
  [SMALL_STATE(6)] = 82,
  [SMALL_STATE(7)] = 97,
  [SMALL_STATE(8)] = 112,
  [SMALL_STATE(9)] = 127,
  [SMALL_STATE(10)] = 138,
  [SMALL_STATE(11)] = 149,
  [SMALL_STATE(12)] = 158,
  [SMALL_STATE(13)] = 169,
  [SMALL_STATE(14)] = 178,
  [SMALL_STATE(15)] = 185,
  [SMALL_STATE(16)] = 189,
  [SMALL_STATE(17)] = 193,
};

static const TSParseActionEntry ts_parse_actions[] = {
  [0] = {.entry = {.count = 0, .reusable = false}},
  [1] = {.entry = {.count = 1, .reusable = false}}, RECOVER(),
  [3] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_document, 0),
  [5] = {.entry = {.count = 1, .reusable = false}}, SHIFT(9),
  [7] = {.entry = {.count = 1, .reusable = true}}, SHIFT(2),
  [9] = {.entry = {.count = 1, .reusable = false}}, SHIFT(15),
  [11] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_document, 1),
  [13] = {.entry = {.count = 1, .reusable = true}}, SHIFT(3),
  [15] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_document_repeat1, 2),
  [17] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_document_repeat1, 2), SHIFT_REPEAT(9),
  [20] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_document_repeat1, 2), SHIFT_REPEAT(3),
  [23] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_document_repeat1, 2), SHIFT_REPEAT(15),
  [26] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_paragraph, 1),
  [28] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_paragraph, 1),
  [30] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_paragraph_repeat1, 2),
  [32] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_paragraph_repeat1, 2), SHIFT_REPEAT(9),
  [35] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym_paragraph_repeat1, 2),
  [37] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_paragraph_segment, 1),
  [39] = {.entry = {.count = 1, .reusable = false}}, SHIFT(7),
  [41] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_paragraph_segment, 1),
  [43] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_paragraph_segment, 2),
  [45] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_paragraph_segment, 2),
  [47] = {.entry = {.count = 1, .reusable = false}}, SHIFT(8),
  [49] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_paragraph_segment_repeat1, 2),
  [51] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_paragraph_segment_repeat1, 2), SHIFT_REPEAT(8),
  [54] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym_paragraph_segment_repeat1, 2),
  [56] = {.entry = {.count = 1, .reusable = false}}, SHIFT(10),
  [58] = {.entry = {.count = 1, .reusable = false}}, SHIFT(12),
  [60] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_paragraph_segment_repeat1, 2), SHIFT_REPEAT(12),
  [63] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_heading1, 3),
  [65] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_heading1, 3),
  [67] = {.entry = {.count = 1, .reusable = true}}, SHIFT(6),
  [69] = {.entry = {.count = 1, .reusable = true}}, SHIFT(14),
  [71] = {.entry = {.count = 1, .reusable = true}},  ACCEPT_INPUT(),
  [73] = {.entry = {.count = 1, .reusable = true}}, SHIFT(11),
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
