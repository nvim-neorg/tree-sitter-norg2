module.exports = grammar({
    name: "norg",

    // Tell treesitter we want to handle whitespace ourselves
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
        whitespace: _ => /[\t                　]+/,
        _newline: _ => choice("\n", "\r", "\r\n", "\0"),

        escape_sequence: $ => seq(
            "\\",
            alias(/./, $.escape_char),
        ),

        paragraph_segment: $ => prec.right(repeat1(
            choice(
                $.word,
                $.whitespace,
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

        heading: $ => seq(
            alias(/\*+/, $.prefix),
            $.whitespace,
            $.paragraph_segment,
        ),
    },
});
