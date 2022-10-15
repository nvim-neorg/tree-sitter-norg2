let i = token.immediate

module.exports = grammar({
    name: "norg",

    externals: $ => [
        //$.eof,
    ],

    conflicts: $ => [
    ],

    precedences: $ => [
    ],

    rules: {
        document: $ => repeat(
            choice(
                $.paragraph,
                $.paragraph_break,
                $.heading1,
            ),
        ),

        word: _ => /[^\s]+/,
        whitespace: _ => /[\t                　]+/,

        paragraph_segment: $ => prec.right(seq(
            $.word,

            repeat(
                choice(
                    $.word,
                    $.whitespace,
                ),
            ),
        )),

        paragraph_break: $ => /\n+/,

        paragraph: $ => prec.right(repeat1(
            seq(
                $.paragraph_segment,
                i("\n"),
            )
        )),

        heading1: $ => gen_heading($, 1),
        heading2: $ => gen_heading($, 2),
        heading3: $ => gen_heading($, 3),
        heading4: $ => gen_heading($, 4),
        heading5: $ => gen_heading($, 5),
        heading6: $ => gen_heading($, 6),
    },
});

function gen_heading($, level) {
    return seq(
        "*".repeat(level),
        /\s+/,
        $.paragraph_segment,
    );
}
