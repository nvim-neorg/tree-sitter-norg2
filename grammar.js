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

        heading: $ => seq(
            alias(repeat1("*"), $.prefix),
            $._whitespace,
            $.paragraph_segment,
        ),
    },
});
