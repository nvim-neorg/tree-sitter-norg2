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
        $.nestable_detached_modifiers,
    ],

    rules: {
        document: $ => repeat(
            choice(
                $.paragraph,
                $.paragraph_break,
                $.heading1,
                $.nestable_detached_modifiers,
            ),
        ),

        // ------------------------------------------------------------------------

        _word: _ => /[^\s]+/,
        _whitespace: _ => /[\t                　]+/,

        paragraph_segment: $ => prec.right(
            seq(
                $._word,

                repeat(
                    choice(
                        $._word,
                        $._whitespace,
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

        nestable_detached_modifiers: $ => choice(
            $.unordered_list,
        ),

        // ------------------------------------------------------------------------

        heading1: $ => gen_heading($, 1),
        heading2: $ => gen_heading($, 2),
        heading3: $ => gen_heading($, 3),
        heading4: $ => gen_heading($, 4),
        heading5: $ => gen_heading($, 5),
        heading6: $ => gen_heading($, 6),

        // weak_paragraph_delimiter: _ => "---",

        // -----------------------------------------------------------------------

        unordered_list: $ => prec.right(
            repeat1(
                choice(
                    $.unordered_list1,
                    $.unordered_list2,
                    $.unordered_list3,
                    $.unordered_list4,
                    $.unordered_list5,
                    $.unordered_list6,
                )
            ),
        ),

        unordered_list1: $ => gen_nestable_detached_modifier($, "-", "unordered_list", 1),
        unordered_list2: $ => gen_nestable_detached_modifier($, "-", "unordered_list", 2),
        unordered_list3: $ => gen_nestable_detached_modifier($, "-", "unordered_list", 3),
        unordered_list4: $ => gen_nestable_detached_modifier($, "-", "unordered_list", 4),
        unordered_list5: $ => gen_nestable_detached_modifier($, "-", "unordered_list", 5),
        unordered_list6: $ => gen_nestable_detached_modifier($, "-", "unordered_list", 6),
    },
});

function gen_heading($, level) {
    let subheadings = [];

    for (let i = level + 1; i < 6; i++) {
        subheadings.push($["heading" + i]);
    }

    return prec.right(
        seq(
            "*".repeat(level),
            $._whitespace,
            field("title", $.paragraph_segment),
            line_break,

            field("content",
                repeat(
                    choice(
                        $.non_structural,
                        $.nestable_detached_modifiers,
                        ...subheadings,
                    ),
                ),
            ),

            // optional(
            //     seq(
            //         $.weak_paragraph_delimiter,
            //         line_break,
            //     ),
            // ),
        )
    );
}

function gen_nestable_detached_modifier($, char, name, level) {
    let submodifiers = [];

    for (let i = level + 1; i < 6; i++) {
        submodifiers.push($[name + i]);
    }

    return prec.right(
        seq(
            char.repeat(level),
            $._whitespace,
            field("content", $.paragraph),

            repeat(
                choice(
                    ...submodifiers,
                ),
            ),
        )
    );
}
