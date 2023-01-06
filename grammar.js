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
    },
});

function gen_heading($, level) {
    return gen_nestable_detached_modifier(
        $,
        "heading",
        "*",
        level,
    );
}

function gen_nestable_detached_modifier($, type, chr, level) {
    let lower_level = []
    for (let i = 0; i + level < 6; i++) {
        lower_level[i] = $[type + (i + 1 + level)]
    }

    return prec.right(
        seq(
            alias(chr.repeat(level), $.prefix),

            $._whitespace,

            field("title", $.paragraph_segment),

            $._newline,

            repeat(
                choice(
                    $.paragraph,

                    ...lower_level,
                ),
            ),
        ),
    );
}
