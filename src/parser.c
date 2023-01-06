#include <tree_sitter/parser.h>

#if defined(__GNUC__) || defined(__clang__)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wmissing-field-initializers"
#endif

#define LANGUAGE_VERSION 14
#define STATE_COUNT 29
#define LARGE_STATE_COUNT 8
#define SYMBOL_COUNT 22
#define ALIAS_COUNT 1
#define TOKEN_COUNT 10
#define EXTERNAL_TOKEN_COUNT 0
#define FIELD_COUNT 0
#define MAX_ALIAS_SEQUENCE_LENGTH 3
#define PRODUCTION_ID_COUNT 2

enum {
  sym__character = 1,
  sym__whitespace = 2,
  anon_sym_LF = 3,
  anon_sym_CR = 4,
  anon_sym_CR_LF = 5,
  anon_sym_ = 6,
  anon_sym_BSLASH = 7,
  aux_sym_escape_sequence_token1 = 8,
  anon_sym_STAR = 9,
  sym_document = 10,
  sym_word = 11,
  sym__newline = 12,
  sym_escape_sequence = 13,
  sym_paragraph_segment = 14,
  sym_paragraph = 15,
  sym_heading = 16,
  aux_sym_document_repeat1 = 17,
  aux_sym_word_repeat1 = 18,
  aux_sym_paragraph_segment_repeat1 = 19,
  aux_sym_paragraph_repeat1 = 20,
  aux_sym_heading_repeat1 = 21,
  alias_sym_prefix = 22,
};

static const char * const ts_symbol_names[] = {
  [ts_builtin_sym_end] = "end",
  [sym__character] = "_character",
  [sym__whitespace] = "_whitespace",
  [anon_sym_LF] = "\n",
  [anon_sym_CR] = "\r",
  [anon_sym_CR_LF] = "\r\n",
  [anon_sym_] = " ",
  [anon_sym_BSLASH] = "\\",
  [aux_sym_escape_sequence_token1] = "escape_char",
  [anon_sym_STAR] = "*",
  [sym_document] = "document",
  [sym_word] = "word",
  [sym__newline] = "_newline",
  [sym_escape_sequence] = "escape_sequence",
  [sym_paragraph_segment] = "paragraph_segment",
  [sym_paragraph] = "paragraph",
  [sym_heading] = "heading",
  [aux_sym_document_repeat1] = "document_repeat1",
  [aux_sym_word_repeat1] = "word_repeat1",
  [aux_sym_paragraph_segment_repeat1] = "paragraph_segment_repeat1",
  [aux_sym_paragraph_repeat1] = "paragraph_repeat1",
  [aux_sym_heading_repeat1] = "heading_repeat1",
  [alias_sym_prefix] = "prefix",
};

static const TSSymbol ts_symbol_map[] = {
  [ts_builtin_sym_end] = ts_builtin_sym_end,
  [sym__character] = sym__character,
  [sym__whitespace] = sym__whitespace,
  [anon_sym_LF] = anon_sym_LF,
  [anon_sym_CR] = anon_sym_CR,
  [anon_sym_CR_LF] = anon_sym_CR_LF,
  [anon_sym_] = anon_sym_,
  [anon_sym_BSLASH] = anon_sym_BSLASH,
  [aux_sym_escape_sequence_token1] = aux_sym_escape_sequence_token1,
  [anon_sym_STAR] = anon_sym_STAR,
  [sym_document] = sym_document,
  [sym_word] = sym_word,
  [sym__newline] = sym__newline,
  [sym_escape_sequence] = sym_escape_sequence,
  [sym_paragraph_segment] = sym_paragraph_segment,
  [sym_paragraph] = sym_paragraph,
  [sym_heading] = sym_heading,
  [aux_sym_document_repeat1] = aux_sym_document_repeat1,
  [aux_sym_word_repeat1] = aux_sym_word_repeat1,
  [aux_sym_paragraph_segment_repeat1] = aux_sym_paragraph_segment_repeat1,
  [aux_sym_paragraph_repeat1] = aux_sym_paragraph_repeat1,
  [aux_sym_heading_repeat1] = aux_sym_heading_repeat1,
  [alias_sym_prefix] = alias_sym_prefix,
};

static const TSSymbolMetadata ts_symbol_metadata[] = {
  [ts_builtin_sym_end] = {
    .visible = false,
    .named = true,
  },
  [sym__character] = {
    .visible = false,
    .named = true,
  },
  [sym__whitespace] = {
    .visible = false,
    .named = true,
  },
  [anon_sym_LF] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_CR] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_CR_LF] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_BSLASH] = {
    .visible = true,
    .named = false,
  },
  [aux_sym_escape_sequence_token1] = {
    .visible = true,
    .named = true,
  },
  [anon_sym_STAR] = {
    .visible = true,
    .named = false,
  },
  [sym_document] = {
    .visible = true,
    .named = true,
  },
  [sym_word] = {
    .visible = true,
    .named = true,
  },
  [sym__newline] = {
    .visible = false,
    .named = true,
  },
  [sym_escape_sequence] = {
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
  [sym_heading] = {
    .visible = true,
    .named = true,
  },
  [aux_sym_document_repeat1] = {
    .visible = false,
    .named = false,
  },
  [aux_sym_word_repeat1] = {
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
  [aux_sym_heading_repeat1] = {
    .visible = false,
    .named = false,
  },
  [alias_sym_prefix] = {
    .visible = true,
    .named = true,
  },
};

static const TSSymbol ts_alias_sequences[PRODUCTION_ID_COUNT][MAX_ALIAS_SEQUENCE_LENGTH] = {
  [0] = {0},
  [1] = {
    [0] = alias_sym_prefix,
  },
};

static const uint16_t ts_non_terminal_alias_map[] = {
  aux_sym_heading_repeat1, 2,
    aux_sym_heading_repeat1,
    alias_sym_prefix,
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
  [8] = 6,
  [9] = 7,
  [10] = 10,
  [11] = 11,
  [12] = 12,
  [13] = 13,
  [14] = 11,
  [15] = 15,
  [16] = 10,
  [17] = 17,
  [18] = 12,
  [19] = 19,
  [20] = 20,
  [21] = 21,
  [22] = 22,
  [23] = 23,
  [24] = 24,
  [25] = 25,
  [26] = 26,
  [27] = 27,
  [28] = 26,
};

static bool ts_lex(TSLexer *lexer, TSStateId state) {
  START_LEXER();
  eof = lexer->eof(lexer);
  switch (state) {
    case 0:
      if (eof) ADVANCE(6);
      if (lookahead == 0) ADVANCE(14);
      if (lookahead == '\n') ADVANCE(10);
      if (lookahead == '\r') ADVANCE(11);
      if (lookahead == '*') ADVANCE(17);
      if (lookahead == '\\') ADVANCE(15);
      if (lookahead == '\t' ||
          lookahead == ' ') ADVANCE(9);
      if (lookahead == 160 ||
          lookahead == 5760 ||
          (8192 <= lookahead && lookahead <= 8202) ||
          lookahead == 8239 ||
          lookahead == 8287 ||
          lookahead == 12288) ADVANCE(8);
      if (lookahead != 0) ADVANCE(7);
      END_STATE();
    case 1:
      if (lookahead == 0) ADVANCE(14);
      if (lookahead == '\n') ADVANCE(10);
      if (lookahead == '\r') ADVANCE(12);
      if (lookahead == '\\') ADVANCE(15);
      if (lookahead == '\t' ||
          lookahead == ' ') ADVANCE(9);
      if (lookahead == 160 ||
          lookahead == 5760 ||
          (8192 <= lookahead && lookahead <= 8202) ||
          lookahead == 8239 ||
          lookahead == 8287 ||
          lookahead == 12288) ADVANCE(8);
      if (lookahead != 0) ADVANCE(7);
      END_STATE();
    case 2:
      if (lookahead == '*') ADVANCE(17);
      if (lookahead == '\t' ||
          lookahead == ' ' ||
          lookahead == 160 ||
          lookahead == 5760 ||
          (8192 <= lookahead && lookahead <= 8202) ||
          lookahead == 8239 ||
          lookahead == 8287 ||
          lookahead == 12288) ADVANCE(9);
      END_STATE();
    case 3:
      if (lookahead == '\\') ADVANCE(15);
      if (lookahead == '\t' ||
          lookahead == ' ') ADVANCE(9);
      if (lookahead == 160 ||
          lookahead == 5760 ||
          (8192 <= lookahead && lookahead <= 8202) ||
          lookahead == 8239 ||
          lookahead == 8287 ||
          lookahead == 12288) ADVANCE(8);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r') ADVANCE(7);
      END_STATE();
    case 4:
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(16);
      END_STATE();
    case 5:
      if (eof) ADVANCE(6);
      if (lookahead == 0) ADVANCE(14);
      if (lookahead == '\n') ADVANCE(10);
      if (lookahead == '\r') ADVANCE(12);
      if (lookahead == '*') ADVANCE(17);
      if (lookahead == '\\') ADVANCE(15);
      if (lookahead == '\t' ||
          lookahead == ' ') ADVANCE(9);
      if (lookahead == 160 ||
          lookahead == 5760 ||
          (8192 <= lookahead && lookahead <= 8202) ||
          lookahead == 8239 ||
          lookahead == 8287 ||
          lookahead == 12288) ADVANCE(8);
      if (lookahead != 0) ADVANCE(7);
      END_STATE();
    case 6:
      ACCEPT_TOKEN(ts_builtin_sym_end);
      END_STATE();
    case 7:
      ACCEPT_TOKEN(sym__character);
      END_STATE();
    case 8:
      ACCEPT_TOKEN(sym__character);
      if (lookahead == '\t' ||
          lookahead == ' ' ||
          lookahead == 160 ||
          lookahead == 5760 ||
          (8192 <= lookahead && lookahead <= 8202) ||
          lookahead == 8239 ||
          lookahead == 8287 ||
          lookahead == 12288) ADVANCE(9);
      END_STATE();
    case 9:
      ACCEPT_TOKEN(sym__whitespace);
      if (lookahead == '\t' ||
          lookahead == ' ' ||
          lookahead == 160 ||
          lookahead == 5760 ||
          (8192 <= lookahead && lookahead <= 8202) ||
          lookahead == 8239 ||
          lookahead == 8287 ||
          lookahead == 12288) ADVANCE(9);
      END_STATE();
    case 10:
      ACCEPT_TOKEN(anon_sym_LF);
      END_STATE();
    case 11:
      ACCEPT_TOKEN(anon_sym_CR);
      END_STATE();
    case 12:
      ACCEPT_TOKEN(anon_sym_CR);
      if (lookahead == '\n') ADVANCE(13);
      END_STATE();
    case 13:
      ACCEPT_TOKEN(anon_sym_CR_LF);
      END_STATE();
    case 14:
      ACCEPT_TOKEN(anon_sym_);
      END_STATE();
    case 15:
      ACCEPT_TOKEN(anon_sym_BSLASH);
      END_STATE();
    case 16:
      ACCEPT_TOKEN(aux_sym_escape_sequence_token1);
      END_STATE();
    case 17:
      ACCEPT_TOKEN(anon_sym_STAR);
      END_STATE();
    default:
      return false;
  }
}

static bool ts_lex_keywords(TSLexer *lexer, TSStateId state) {
  START_LEXER();
  eof = lexer->eof(lexer);
  switch (state) {
    case 0:
      ACCEPT_TOKEN(ts_builtin_sym_end);
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
  [6] = {.lex_state = 5},
  [7] = {.lex_state = 5},
  [8] = {.lex_state = 1},
  [9] = {.lex_state = 1},
  [10] = {.lex_state = 5},
  [11] = {.lex_state = 5},
  [12] = {.lex_state = 5},
  [13] = {.lex_state = 5},
  [14] = {.lex_state = 1},
  [15] = {.lex_state = 3},
  [16] = {.lex_state = 1},
  [17] = {.lex_state = 3},
  [18] = {.lex_state = 1},
  [19] = {.lex_state = 5},
  [20] = {.lex_state = 5},
  [21] = {.lex_state = 5},
  [22] = {.lex_state = 5},
  [23] = {.lex_state = 2},
  [24] = {.lex_state = 2},
  [25] = {.lex_state = 2},
  [26] = {.lex_state = 4},
  [27] = {.lex_state = 0},
  [28] = {.lex_state = 4},
};

static const uint16_t ts_parse_table[LARGE_STATE_COUNT][SYMBOL_COUNT] = {
  [0] = {
    [ts_builtin_sym_end] = ACTIONS(1),
    [sym__character] = ACTIONS(1),
    [sym__whitespace] = ACTIONS(1),
    [anon_sym_LF] = ACTIONS(1),
    [anon_sym_CR] = ACTIONS(1),
    [anon_sym_] = ACTIONS(1),
    [anon_sym_BSLASH] = ACTIONS(1),
    [aux_sym_escape_sequence_token1] = ACTIONS(1),
    [anon_sym_STAR] = ACTIONS(1),
  },
  [1] = {
    [sym_document] = STATE(27),
    [sym_word] = STATE(9),
    [sym__newline] = STATE(2),
    [sym_escape_sequence] = STATE(9),
    [sym_paragraph_segment] = STATE(21),
    [sym_paragraph] = STATE(2),
    [sym_heading] = STATE(2),
    [aux_sym_document_repeat1] = STATE(2),
    [aux_sym_word_repeat1] = STATE(14),
    [aux_sym_paragraph_segment_repeat1] = STATE(9),
    [aux_sym_heading_repeat1] = STATE(24),
    [ts_builtin_sym_end] = ACTIONS(3),
    [sym__character] = ACTIONS(5),
    [sym__whitespace] = ACTIONS(7),
    [anon_sym_LF] = ACTIONS(9),
    [anon_sym_CR] = ACTIONS(11),
    [anon_sym_CR_LF] = ACTIONS(9),
    [anon_sym_] = ACTIONS(9),
    [anon_sym_BSLASH] = ACTIONS(13),
    [anon_sym_STAR] = ACTIONS(15),
  },
  [2] = {
    [sym_word] = STATE(9),
    [sym__newline] = STATE(3),
    [sym_escape_sequence] = STATE(9),
    [sym_paragraph_segment] = STATE(21),
    [sym_paragraph] = STATE(3),
    [sym_heading] = STATE(3),
    [aux_sym_document_repeat1] = STATE(3),
    [aux_sym_word_repeat1] = STATE(14),
    [aux_sym_paragraph_segment_repeat1] = STATE(9),
    [aux_sym_heading_repeat1] = STATE(24),
    [ts_builtin_sym_end] = ACTIONS(17),
    [sym__character] = ACTIONS(5),
    [sym__whitespace] = ACTIONS(7),
    [anon_sym_LF] = ACTIONS(19),
    [anon_sym_CR] = ACTIONS(21),
    [anon_sym_CR_LF] = ACTIONS(19),
    [anon_sym_] = ACTIONS(19),
    [anon_sym_BSLASH] = ACTIONS(13),
    [anon_sym_STAR] = ACTIONS(15),
  },
  [3] = {
    [sym_word] = STATE(9),
    [sym__newline] = STATE(3),
    [sym_escape_sequence] = STATE(9),
    [sym_paragraph_segment] = STATE(21),
    [sym_paragraph] = STATE(3),
    [sym_heading] = STATE(3),
    [aux_sym_document_repeat1] = STATE(3),
    [aux_sym_word_repeat1] = STATE(14),
    [aux_sym_paragraph_segment_repeat1] = STATE(9),
    [aux_sym_heading_repeat1] = STATE(24),
    [ts_builtin_sym_end] = ACTIONS(23),
    [sym__character] = ACTIONS(25),
    [sym__whitespace] = ACTIONS(28),
    [anon_sym_LF] = ACTIONS(31),
    [anon_sym_CR] = ACTIONS(34),
    [anon_sym_CR_LF] = ACTIONS(31),
    [anon_sym_] = ACTIONS(31),
    [anon_sym_BSLASH] = ACTIONS(37),
    [anon_sym_STAR] = ACTIONS(40),
  },
  [4] = {
    [sym_word] = STATE(9),
    [sym_escape_sequence] = STATE(9),
    [sym_paragraph_segment] = STATE(22),
    [aux_sym_word_repeat1] = STATE(14),
    [aux_sym_paragraph_segment_repeat1] = STATE(9),
    [ts_builtin_sym_end] = ACTIONS(43),
    [sym__character] = ACTIONS(5),
    [sym__whitespace] = ACTIONS(7),
    [anon_sym_LF] = ACTIONS(43),
    [anon_sym_CR] = ACTIONS(45),
    [anon_sym_CR_LF] = ACTIONS(43),
    [anon_sym_] = ACTIONS(43),
    [anon_sym_BSLASH] = ACTIONS(13),
    [anon_sym_STAR] = ACTIONS(43),
  },
  [5] = {
    [sym_word] = STATE(9),
    [sym_escape_sequence] = STATE(9),
    [sym_paragraph_segment] = STATE(22),
    [aux_sym_word_repeat1] = STATE(14),
    [aux_sym_paragraph_segment_repeat1] = STATE(9),
    [ts_builtin_sym_end] = ACTIONS(47),
    [sym__character] = ACTIONS(5),
    [sym__whitespace] = ACTIONS(7),
    [anon_sym_LF] = ACTIONS(47),
    [anon_sym_CR] = ACTIONS(49),
    [anon_sym_CR_LF] = ACTIONS(47),
    [anon_sym_] = ACTIONS(47),
    [anon_sym_BSLASH] = ACTIONS(13),
    [anon_sym_STAR] = ACTIONS(47),
  },
  [6] = {
    [sym_word] = STATE(6),
    [sym_escape_sequence] = STATE(6),
    [aux_sym_word_repeat1] = STATE(11),
    [aux_sym_paragraph_segment_repeat1] = STATE(6),
    [ts_builtin_sym_end] = ACTIONS(51),
    [sym__character] = ACTIONS(53),
    [sym__whitespace] = ACTIONS(56),
    [anon_sym_LF] = ACTIONS(51),
    [anon_sym_CR] = ACTIONS(59),
    [anon_sym_CR_LF] = ACTIONS(51),
    [anon_sym_] = ACTIONS(51),
    [anon_sym_BSLASH] = ACTIONS(61),
    [anon_sym_STAR] = ACTIONS(51),
  },
  [7] = {
    [sym_word] = STATE(6),
    [sym_escape_sequence] = STATE(6),
    [aux_sym_word_repeat1] = STATE(11),
    [aux_sym_paragraph_segment_repeat1] = STATE(6),
    [ts_builtin_sym_end] = ACTIONS(64),
    [sym__character] = ACTIONS(66),
    [sym__whitespace] = ACTIONS(68),
    [anon_sym_LF] = ACTIONS(64),
    [anon_sym_CR] = ACTIONS(70),
    [anon_sym_CR_LF] = ACTIONS(64),
    [anon_sym_] = ACTIONS(64),
    [anon_sym_BSLASH] = ACTIONS(72),
    [anon_sym_STAR] = ACTIONS(64),
  },
};

static const uint16_t ts_small_parse_table[] = {
  [0] = 7,
    ACTIONS(59), 1,
      anon_sym_CR,
    ACTIONS(74), 1,
      sym__character,
    ACTIONS(77), 1,
      sym__whitespace,
    ACTIONS(80), 1,
      anon_sym_BSLASH,
    STATE(14), 1,
      aux_sym_word_repeat1,
    ACTIONS(51), 3,
      anon_sym_LF,
      anon_sym_CR_LF,
      anon_sym_,
    STATE(8), 3,
      sym_word,
      sym_escape_sequence,
      aux_sym_paragraph_segment_repeat1,
  [26] = 7,
    ACTIONS(5), 1,
      sym__character,
    ACTIONS(13), 1,
      anon_sym_BSLASH,
    ACTIONS(70), 1,
      anon_sym_CR,
    ACTIONS(83), 1,
      sym__whitespace,
    STATE(14), 1,
      aux_sym_word_repeat1,
    ACTIONS(64), 3,
      anon_sym_LF,
      anon_sym_CR_LF,
      anon_sym_,
    STATE(8), 3,
      sym_word,
      sym_escape_sequence,
      aux_sym_paragraph_segment_repeat1,
  [52] = 4,
    ACTIONS(87), 1,
      sym__character,
    STATE(10), 1,
      aux_sym_word_repeat1,
    ACTIONS(90), 2,
      sym__whitespace,
      anon_sym_CR,
    ACTIONS(85), 6,
      ts_builtin_sym_end,
      anon_sym_LF,
      anon_sym_CR_LF,
      anon_sym_,
      anon_sym_BSLASH,
      anon_sym_STAR,
  [71] = 4,
    ACTIONS(94), 1,
      sym__character,
    STATE(10), 1,
      aux_sym_word_repeat1,
    ACTIONS(96), 2,
      sym__whitespace,
      anon_sym_CR,
    ACTIONS(92), 6,
      ts_builtin_sym_end,
      anon_sym_LF,
      anon_sym_CR_LF,
      anon_sym_,
      anon_sym_BSLASH,
      anon_sym_STAR,
  [90] = 2,
    ACTIONS(100), 3,
      sym__character,
      sym__whitespace,
      anon_sym_CR,
    ACTIONS(98), 6,
      ts_builtin_sym_end,
      anon_sym_LF,
      anon_sym_CR_LF,
      anon_sym_,
      anon_sym_BSLASH,
      anon_sym_STAR,
  [104] = 2,
    ACTIONS(104), 3,
      sym__character,
      sym__whitespace,
      anon_sym_CR,
    ACTIONS(102), 6,
      ts_builtin_sym_end,
      anon_sym_LF,
      anon_sym_CR_LF,
      anon_sym_,
      anon_sym_BSLASH,
      anon_sym_STAR,
  [118] = 4,
    ACTIONS(106), 1,
      sym__character,
    STATE(16), 1,
      aux_sym_word_repeat1,
    ACTIONS(96), 2,
      sym__whitespace,
      anon_sym_CR,
    ACTIONS(92), 4,
      anon_sym_LF,
      anon_sym_CR_LF,
      anon_sym_,
      anon_sym_BSLASH,
  [135] = 6,
    ACTIONS(66), 1,
      sym__character,
    ACTIONS(72), 1,
      anon_sym_BSLASH,
    ACTIONS(108), 1,
      sym__whitespace,
    STATE(11), 1,
      aux_sym_word_repeat1,
    STATE(13), 1,
      sym_paragraph_segment,
    STATE(7), 3,
      sym_word,
      sym_escape_sequence,
      aux_sym_paragraph_segment_repeat1,
  [156] = 4,
    ACTIONS(110), 1,
      sym__character,
    STATE(16), 1,
      aux_sym_word_repeat1,
    ACTIONS(90), 2,
      sym__whitespace,
      anon_sym_CR,
    ACTIONS(85), 4,
      anon_sym_LF,
      anon_sym_CR_LF,
      anon_sym_,
      anon_sym_BSLASH,
  [173] = 6,
    ACTIONS(5), 1,
      sym__character,
    ACTIONS(7), 1,
      sym__whitespace,
    ACTIONS(13), 1,
      anon_sym_BSLASH,
    STATE(14), 1,
      aux_sym_word_repeat1,
    STATE(22), 1,
      sym_paragraph_segment,
    STATE(9), 3,
      sym_word,
      sym_escape_sequence,
      aux_sym_paragraph_segment_repeat1,
  [194] = 2,
    ACTIONS(100), 3,
      sym__character,
      sym__whitespace,
      anon_sym_CR,
    ACTIONS(98), 4,
      anon_sym_LF,
      anon_sym_CR_LF,
      anon_sym_,
      anon_sym_BSLASH,
  [206] = 4,
    ACTIONS(116), 1,
      anon_sym_CR,
    STATE(17), 1,
      sym__newline,
    STATE(19), 1,
      aux_sym_paragraph_repeat1,
    ACTIONS(113), 3,
      anon_sym_LF,
      anon_sym_CR_LF,
      anon_sym_,
  [221] = 4,
    ACTIONS(121), 1,
      anon_sym_CR,
    STATE(5), 1,
      sym__newline,
    STATE(19), 1,
      aux_sym_paragraph_repeat1,
    ACTIONS(119), 3,
      anon_sym_LF,
      anon_sym_CR_LF,
      anon_sym_,
  [236] = 4,
    ACTIONS(125), 1,
      anon_sym_CR,
    STATE(4), 1,
      sym__newline,
    STATE(20), 1,
      aux_sym_paragraph_repeat1,
    ACTIONS(123), 3,
      anon_sym_LF,
      anon_sym_CR_LF,
      anon_sym_,
  [251] = 2,
    ACTIONS(129), 1,
      anon_sym_CR,
    ACTIONS(127), 3,
      anon_sym_LF,
      anon_sym_CR_LF,
      anon_sym_,
  [260] = 3,
    ACTIONS(131), 1,
      sym__whitespace,
    ACTIONS(133), 1,
      anon_sym_STAR,
    STATE(23), 1,
      aux_sym_heading_repeat1,
  [270] = 3,
    ACTIONS(15), 1,
      anon_sym_STAR,
    ACTIONS(136), 1,
      sym__whitespace,
    STATE(23), 1,
      aux_sym_heading_repeat1,
  [280] = 1,
    ACTIONS(138), 2,
      sym__whitespace,
      anon_sym_STAR,
  [285] = 1,
    ACTIONS(140), 1,
      aux_sym_escape_sequence_token1,
  [289] = 1,
    ACTIONS(142), 1,
      ts_builtin_sym_end,
  [293] = 1,
    ACTIONS(144), 1,
      aux_sym_escape_sequence_token1,
};

static const uint32_t ts_small_parse_table_map[] = {
  [SMALL_STATE(8)] = 0,
  [SMALL_STATE(9)] = 26,
  [SMALL_STATE(10)] = 52,
  [SMALL_STATE(11)] = 71,
  [SMALL_STATE(12)] = 90,
  [SMALL_STATE(13)] = 104,
  [SMALL_STATE(14)] = 118,
  [SMALL_STATE(15)] = 135,
  [SMALL_STATE(16)] = 156,
  [SMALL_STATE(17)] = 173,
  [SMALL_STATE(18)] = 194,
  [SMALL_STATE(19)] = 206,
  [SMALL_STATE(20)] = 221,
  [SMALL_STATE(21)] = 236,
  [SMALL_STATE(22)] = 251,
  [SMALL_STATE(23)] = 260,
  [SMALL_STATE(24)] = 270,
  [SMALL_STATE(25)] = 280,
  [SMALL_STATE(26)] = 285,
  [SMALL_STATE(27)] = 289,
  [SMALL_STATE(28)] = 293,
};

static const TSParseActionEntry ts_parse_actions[] = {
  [0] = {.entry = {.count = 0, .reusable = false}},
  [1] = {.entry = {.count = 1, .reusable = false}}, RECOVER(),
  [3] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_document, 0),
  [5] = {.entry = {.count = 1, .reusable = false}}, SHIFT(14),
  [7] = {.entry = {.count = 1, .reusable = false}}, SHIFT(9),
  [9] = {.entry = {.count = 1, .reusable = true}}, SHIFT(2),
  [11] = {.entry = {.count = 1, .reusable = false}}, SHIFT(2),
  [13] = {.entry = {.count = 1, .reusable = true}}, SHIFT(26),
  [15] = {.entry = {.count = 1, .reusable = true}}, SHIFT(25),
  [17] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_document, 1),
  [19] = {.entry = {.count = 1, .reusable = true}}, SHIFT(3),
  [21] = {.entry = {.count = 1, .reusable = false}}, SHIFT(3),
  [23] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_document_repeat1, 2),
  [25] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_document_repeat1, 2), SHIFT_REPEAT(14),
  [28] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_document_repeat1, 2), SHIFT_REPEAT(9),
  [31] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_document_repeat1, 2), SHIFT_REPEAT(3),
  [34] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_document_repeat1, 2), SHIFT_REPEAT(3),
  [37] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_document_repeat1, 2), SHIFT_REPEAT(26),
  [40] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_document_repeat1, 2), SHIFT_REPEAT(25),
  [43] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_paragraph, 2),
  [45] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_paragraph, 2),
  [47] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_paragraph, 3),
  [49] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_paragraph, 3),
  [51] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_paragraph_segment_repeat1, 2),
  [53] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_paragraph_segment_repeat1, 2), SHIFT_REPEAT(11),
  [56] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_paragraph_segment_repeat1, 2), SHIFT_REPEAT(6),
  [59] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym_paragraph_segment_repeat1, 2),
  [61] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_paragraph_segment_repeat1, 2), SHIFT_REPEAT(28),
  [64] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_paragraph_segment, 1),
  [66] = {.entry = {.count = 1, .reusable = false}}, SHIFT(11),
  [68] = {.entry = {.count = 1, .reusable = false}}, SHIFT(6),
  [70] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_paragraph_segment, 1),
  [72] = {.entry = {.count = 1, .reusable = true}}, SHIFT(28),
  [74] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_paragraph_segment_repeat1, 2), SHIFT_REPEAT(14),
  [77] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_paragraph_segment_repeat1, 2), SHIFT_REPEAT(8),
  [80] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_paragraph_segment_repeat1, 2), SHIFT_REPEAT(26),
  [83] = {.entry = {.count = 1, .reusable = false}}, SHIFT(8),
  [85] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_word_repeat1, 2),
  [87] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_word_repeat1, 2), SHIFT_REPEAT(10),
  [90] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym_word_repeat1, 2),
  [92] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_word, 1),
  [94] = {.entry = {.count = 1, .reusable = false}}, SHIFT(10),
  [96] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_word, 1),
  [98] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_escape_sequence, 2),
  [100] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_escape_sequence, 2),
  [102] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_heading, 3, .production_id = 1),
  [104] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_heading, 3, .production_id = 1),
  [106] = {.entry = {.count = 1, .reusable = false}}, SHIFT(16),
  [108] = {.entry = {.count = 1, .reusable = false}}, SHIFT(7),
  [110] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_word_repeat1, 2), SHIFT_REPEAT(16),
  [113] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_paragraph_repeat1, 2), SHIFT_REPEAT(17),
  [116] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_paragraph_repeat1, 2), SHIFT_REPEAT(17),
  [119] = {.entry = {.count = 1, .reusable = true}}, SHIFT(5),
  [121] = {.entry = {.count = 1, .reusable = false}}, SHIFT(5),
  [123] = {.entry = {.count = 1, .reusable = true}}, SHIFT(4),
  [125] = {.entry = {.count = 1, .reusable = false}}, SHIFT(4),
  [127] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_paragraph_repeat1, 2),
  [129] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym_paragraph_repeat1, 2),
  [131] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_heading_repeat1, 2),
  [133] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_heading_repeat1, 2), SHIFT_REPEAT(25),
  [136] = {.entry = {.count = 1, .reusable = true}}, SHIFT(15),
  [138] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_heading_repeat1, 1),
  [140] = {.entry = {.count = 1, .reusable = true}}, SHIFT(18),
  [142] = {.entry = {.count = 1, .reusable = true}},  ACCEPT_INPUT(),
  [144] = {.entry = {.count = 1, .reusable = true}}, SHIFT(12),
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
    .keyword_lex_fn = ts_lex_keywords,
    .keyword_capture_token = sym__character,
    .primary_state_ids = ts_primary_state_ids,
  };
  return &language;
}
#ifdef __cplusplus
}
#endif
