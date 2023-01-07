let newline = choice("\n", "\r", "\r\n", "\0");

module.exports = grammar({
    name: "norg",

    // Tell treesitter we want to handle _whitespace ourselves
    extras: _ => [],

    externals: $ => [
    ],

    conflicts: $ => [
    ],

    precedences: $ => [
    ],

    inline: $ => [
    ],

    supertypes: $ => [
        $.non_structural,
        $.heading,
    ],

    rules: {
        document: $ => repeat(
            choice(
                $.heading,
                $.strong_delimiting_modifier,
                $.non_structural,
            ),
        ),

        _character: _ => /[^\s]/,
        _word: $ => prec.right(repeat1($._character)),
        _whitespace: _ => /[\t                　]+/,

        escape_sequence: $ => seq(
            "\\",
            alias(/./, $.escape_char),
        ),

        paragraph_segment: $ => prec.right(repeat1(
            choice(
                $._word,
                $._whitespace,
                $.escape_sequence,
            ),
        )),

        paragraph: $ => prec.right(seq(
            $.paragraph_segment,
            repeat(
                seq(
                    newline,
                    $.paragraph_segment,
                ),
            ),
            newline,
            // TODO: deal with https://github.com/nvim-neorg/norg-specs/issues/8
        )),

        heading1: $ => heading($, 1),
        heading2: $ => heading($, 2),
        heading3: $ => heading($, 3),
        heading4: $ => heading($, 4),
        heading5: $ => heading($, 5),
        heading6: $ => heading($, 6),

        heading: $ => choice(
            $.heading1,
            $.heading2,
            $.heading3,
            $.heading4,
            $.heading5,
            $.heading6,
        ),

        weak_delimiting_modifier: $ => token(seq(
            "--",
            repeat("-"),
            newline,
        )),

        strong_delimiting_modifier: $ => token(seq(
            "==",
            repeat("="),
            newline,
        )),

        unordered_list_item1: $ => nestable_detached_mod($, "unordered_list_item", "-", 1),
        unordered_list_item2: $ => nestable_detached_mod($, "unordered_list_item", "-", 2),
        unordered_list_item3: $ => nestable_detached_mod($, "unordered_list_item", "-", 3),
        unordered_list_item4: $ => nestable_detached_mod($, "unordered_list_item", "-", 4),
        unordered_list_item5: $ => nestable_detached_mod($, "unordered_list_item", "-", 5),
        unordered_list_item6: $ => nestable_detached_mod($, "unordered_list_item", "-", 6),

        ordered_list_item1: $ => nestable_detached_mod($, "ordered_list_item", "~", 1),
        ordered_list_item2: $ => nestable_detached_mod($, "ordered_list_item", "~", 2),
        ordered_list_item3: $ => nestable_detached_mod($, "ordered_list_item", "~", 3),
        ordered_list_item4: $ => nestable_detached_mod($, "ordered_list_item", "~", 4),
        ordered_list_item5: $ => nestable_detached_mod($, "ordered_list_item", "~", 5),
        ordered_list_item6: $ => nestable_detached_mod($, "ordered_list_item", "~", 6),

        list: $ => prec.right(
            repeat1(
                choice(
                    $.unordered_list_item1,
                    $.unordered_list_item2,
                    $.unordered_list_item3,
                    $.unordered_list_item4,
                    $.unordered_list_item5,
                    $.unordered_list_item6,
                    $.ordered_list_item1,
                    $.ordered_list_item2,
                    $.ordered_list_item3,
                    $.ordered_list_item4,
                    $.ordered_list_item5,
                    $.ordered_list_item6,
                ),
            ),
        ),

        quote_item1: $ => nestable_detached_mod($, "quote_item", ">", 1),
        quote_item2: $ => nestable_detached_mod($, "quote_item", ">", 2),
        quote_item3: $ => nestable_detached_mod($, "quote_item", ">", 3),
        quote_item4: $ => nestable_detached_mod($, "quote_item", ">", 4),
        quote_item5: $ => nestable_detached_mod($, "quote_item", ">", 5),
        quote_item6: $ => nestable_detached_mod($, "quote_item", ">", 6),

        quote: $ => prec.right(
            repeat1(
                choice(
                    $.quote_item1,
                    $.quote_item2,
                    $.quote_item3,
                    $.quote_item4,
                    $.quote_item5,
                    $.quote_item6,
                ),
            ),
        ),

        non_structural: $ => choice(
            $.paragraph,
            newline,
            $.list,
            $.quote,
        ),

        heading: $ => choice(
            $.heading1,
            $.heading2,
            $.heading3,
            $.heading4,
            $.heading5,
            $.heading6,
        ),

        heading1: $ => prec.right(heading($, 1)),
        heading2: $ => prec.right(heading($, 2)),
        heading3: $ => prec.right(heading($, 3)),
        heading4: $ => prec.right(heading($, 4)),
        heading5: $ => prec.right(heading($, 5)),
        heading6: $ => prec.right(heading($, 6)),
    },
});

function heading($, level) {
    // TODO: re-use nestable_detached_mod (?)
    return prec.right(
        seq(
            detached_mod_prefix($, "*", level),

            $._whitespace,

            field("title", $.paragraph_segment),

            newline,

            repeat(
                choice(
                    $.non_structural,
                    ...lower_level_items($, "heading", level),
                ),
            ),

            optional($.weak_delimiting_modifier),
        ),
    );
}

function nestable_detached_mod($, type, chr, level) {
    return prec.right(
        seq(
            detached_mod_prefix($, chr, level),

            $._whitespace,

            field("content", $.paragraph),

            repeat(
                choice(
                    ...lower_level_items($, type, level),
                ),
            ),
        ),
    );
}

function detached_mod_prefix($, chr, level) {
    return alias(chr.repeat(level), $.prefix);
}

function lower_level_items($, type, level) {
    let lower_level = []
    for (let i = 0; i + level < 6; i++) {
        lower_level[i] = $[type + (i + 1 + level)]
    }
    return lower_level;
}
