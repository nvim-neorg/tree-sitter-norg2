let i = token.immediate;
let line_break = i("\n");

module.exports = grammar({
    name: "norg",

    externals: $ => [
        //$.eof,
    ],

    conflicts: $ => [
    ],

    precedences: $ => [
    ],

    supertypes: $ => [
        $.non_structural,
    ],

    rules: {
        document: $ => repeat(
            choice(
                $.paragraph,
                $.paragraph_break,
                $.heading1,
            ),
        ),

        // ------------------------------------------------------------------------

        word: _ => /[^\s]+/,
        whitespace: _ => /[\t                　]+/,

        paragraph_segment: $ => prec.right(
            seq(
                $.word,

                repeat(
                    choice(
                        $.word,
                        $.whitespace,
                    ),
                ),
            )
        ),

        paragraph_break: $ => /\n+/,

        paragraph: $ => prec.right(
            repeat1(
                seq(
                    $.paragraph_segment,
                    line_break,
                )
            )
        ),

        non_structural: $ => choice(
            $.paragraph,
            $.paragraph_break,
        ),

        // ------------------------------------------------------------------------

        heading1: $ => gen_heading($, 1),
        heading2: $ => gen_heading($, 2),
        heading3: $ => gen_heading($, 3),
        heading4: $ => gen_heading($, 4),
        heading5: $ => gen_heading($, 5),
        heading6: $ => gen_heading($, 6),
    },
});

function gen_heading($, level) {
    let subheadings = [];

    for (let i = level; i < 6; i++) {
        subheadings.push($["heading" + i]);
    }

    return prec.right(
        seq(
            "*".repeat(level),
            /\s+/,
            field("title", $.paragraph_segment),
            line_break,

            field("content",
                repeat(
                    choice(
                        $.non_structural,
                        ...subheadings,
                    ),
                ),
            ),
        )
    );
}
