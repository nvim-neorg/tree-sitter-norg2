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
                $.heading1,
                $.non_structural,
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
            $.nestable_detached_modifiers,
        ),

        nestable_detached_modifiers: $ => choice(
            $.unordered_list,
            $.ordered_list,
            $.quote,
            $.attribute,
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

        ordered_list: $ => prec.right(
            repeat1(
                choice(
                    $.ordered_list1,
                    $.ordered_list2,
                    $.ordered_list3,
                    $.ordered_list4,
                    $.ordered_list5,
                    $.ordered_list6,
                )
            ),
        ),

        ordered_list1: $ => gen_nestable_detached_modifier($, "~", "ordered_list", 1),
        ordered_list2: $ => gen_nestable_detached_modifier($, "~", "ordered_list", 2),
        ordered_list3: $ => gen_nestable_detached_modifier($, "~", "ordered_list", 3),
        ordered_list4: $ => gen_nestable_detached_modifier($, "~", "ordered_list", 4),
        ordered_list5: $ => gen_nestable_detached_modifier($, "~", "ordered_list", 5),
        ordered_list6: $ => gen_nestable_detached_modifier($, "~", "ordered_list", 6),

        quote: $ => prec.right(
            repeat1(
                choice(
                    $.quote1,
                    $.quote2,
                    $.quote3,
                    $.quote4,
                    $.quote5,
                    $.quote6,
                )
            ),
        ),

        quote1: $ => gen_nestable_detached_modifier($, ">", "quote", 1),
        quote2: $ => gen_nestable_detached_modifier($, ">", "quote", 2),
        quote3: $ => gen_nestable_detached_modifier($, ">", "quote", 3),
        quote4: $ => gen_nestable_detached_modifier($, ">", "quote", 4),
        quote5: $ => gen_nestable_detached_modifier($, ">", "quote", 5),
        quote6: $ => gen_nestable_detached_modifier($, ">", "quote", 6),

        attribute: $ => prec.right(
            repeat1(
                choice(
                    $.attribute1,
                    $.attribute2,
                    $.attribute3,
                    $.attribute4,
                    $.attribute5,
                    $.attribute6,
                )
            ),
        ),

        attribute1: $ => gen_nestable_detached_modifier($, "%", "attribute", 1),
        attribute2: $ => gen_nestable_detached_modifier($, "%", "attribute", 2),
        attribute3: $ => gen_nestable_detached_modifier($, "%", "attribute", 3),
        attribute4: $ => gen_nestable_detached_modifier($, "%", "attribute", 4),
        attribute5: $ => gen_nestable_detached_modifier($, "%", "attribute", 5),
        attribute6: $ => gen_nestable_detached_modifier($, "%", "attribute", 6),

        // ------------------------------------------------------------------------
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
