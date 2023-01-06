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
        $.heading,
    ],

    supertypes: $ => [
    ],

    word: $ => $._character,

    rules: {
        document: $ => repeat(
            choice(
                $.heading,
                $.paragraph,
                $._newline,
                $.strong_delimiting_modifier,
                $.list,
            ),
        ),

        _character: _ => /[^\s]/,
        word: $ => prec.right(repeat1($._character)),
        _whitespace: _ => /[\t                　]+/,
        _newline: _ => choice("\n", "\r", "\r\n", "\0"),

        escape_sequence: $ => seq(
            "\\",
            alias(/./, $.escape_char),
        ),

        paragraph_segment: $ => prec.right(repeat1(
            choice(
                $.word,
                $._whitespace,
                $.escape_sequence,
            ),
        )),

        paragraph: $ => prec.right(seq(
            $.paragraph_segment,
            repeat(
                seq(
                    $._newline,
                    $.paragraph_segment,
                ),
            ),
            $._newline,
            // TODO: deal with https://github.com/nvim-neorg/norg-specs/issues/8
        )),

        heading1: $ => gen_heading($, 1),
        heading2: $ => gen_heading($, 2),
        heading3: $ => gen_heading($, 3),
        heading4: $ => gen_heading($, 4),
        heading5: $ => gen_heading($, 5),
        heading6: $ => gen_heading($, 6),

        heading: $ => choice(
            $.heading1,
            $.heading2,
            $.heading3,
            $.heading4,
            $.heading5,
            $.heading6,
        ),

        weak_delimiting_modifier: $ => seq(
            token.immediate("-"),
            repeat1("-"),
            $._newline,
        ),

        strong_delimiting_modifier: $ => seq(
            token.immediate("="),
            repeat1("="),
            $._newline,
        ),

        unordered_list_item1: $ => gen_list_item($, "unordered", "-", 1),
        unordered_list_item2: $ => gen_list_item($, "unordered", "-", 2),
        unordered_list_item3: $ => gen_list_item($, "unordered", "-", 3),
        unordered_list_item4: $ => gen_list_item($, "unordered", "-", 4),
        unordered_list_item5: $ => gen_list_item($, "unordered", "-", 5),
        unordered_list_item6: $ => gen_list_item($, "unordered", "-", 6),

        ordered_list_item1: $ => gen_list_item($, "ordered", "~", 1),
        ordered_list_item2: $ => gen_list_item($, "ordered", "~", 2),
        ordered_list_item3: $ => gen_list_item($, "ordered", "~", 3),
        ordered_list_item4: $ => gen_list_item($, "ordered", "~", 4),
        ordered_list_item5: $ => gen_list_item($, "ordered", "~", 5),
        ordered_list_item6: $ => gen_list_item($, "ordered", "~", 6),


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
    },
});

function gen_heading($, level) {
    return prec.right(
        seq(
            get_detached_mod_prefix($, "*", level),

            $._whitespace,

            field("title", $.paragraph_segment),

            $._newline,

            repeat(
                choice(
                    $.paragraph,

                    ...get_lower_level_items($, "heading", level),
                ),
            ),

            optional($.weak_delimiting_modifier),
        ),
    );
}

function gen_list_item($, type, chr, level) {
    return prec.right(
        seq(
            get_detached_mod_prefix($, chr, level),

            $._whitespace,

            field("content", $.paragraph),

            repeat(
                choice(
                    ...get_lower_level_items($, type + "_list_item", level),
                ),
            ),
        ),
    );
}

function get_detached_mod_prefix($, chr, level) {
    return alias(chr.repeat(level), $.prefix);
}

function get_lower_level_items($, type, level) {
    let lower_level = []
    for (let i = 0; i + level < 6; i++) {
        lower_level[i] = $[type + (i + 1 + level)]
    }
    return lower_level;
}
