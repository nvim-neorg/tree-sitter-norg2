let i = token.immediate;
let line_break = i("\n");

module.exports = grammar({
    name: "norg",

    externals: $ => [
        $.infirm_tag_begin,
    ],

    conflicts: $ => [
    ],

    precedences: $ => [
    ],

    inline: $ => [
    ],

    supertypes: $ => [
        $.non_structural,
        $.nestable_detached_modifiers,
        $.rangeable_detached_modifiers,
        $.headings,
        $.tags,
    ],

    rules: {
        document: $ => repeat(
            choice(
                $.headings,
                $.tags,
                $.non_structural,
                $.strong_delimiting_modifier,
            ),
        ),

        // ------------------------------------------------------------------------

        _word: _ => /[^\s\\]+/,
        _whitespace: _ => i(/[\t                　]+/),

        paragraph_segment: $ => repeat1(
            choice(
                $._word,
                $.escape_sequence,
            ),
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

        escape_sequence: $ => seq(i("\\"), alias(i(/[.\n\r\\]/), $.char)),

        non_structural: $ => choice(
            $.paragraph,
            $.paragraph_break,
            $.nestable_detached_modifiers,
            $.rangeable_detached_modifiers,
            $.horizontal_line_delimiting_modifier,
        ),

        nestable_detached_modifiers: $ => choice(
            $.unordered_list,
            $.ordered_list,
            $.quote,
            $.attribute,
        ),

        // ------------------------------------------------------------------------

        headings: $ => choice(
            $.heading1,
            $.heading2,
            $.heading3,
            $.heading4,
            $.heading5,
            $.heading6,
        ),

        heading1: $ => heading($, 1),
        heading2: $ => heading($, 2),
        heading3: $ => heading($, 3),
        heading4: $ => heading($, 4),
        heading5: $ => heading($, 5),
        heading6: $ => heading($, 6),

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

        unordered_list1: $ => nestable_detached_modifier($, "-", "unordered_list", 1),
        unordered_list2: $ => nestable_detached_modifier($, "-", "unordered_list", 2),
        unordered_list3: $ => nestable_detached_modifier($, "-", "unordered_list", 3),
        unordered_list4: $ => nestable_detached_modifier($, "-", "unordered_list", 4),
        unordered_list5: $ => nestable_detached_modifier($, "-", "unordered_list", 5),
        unordered_list6: $ => nestable_detached_modifier($, "-", "unordered_list", 6),

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

        ordered_list1: $ => nestable_detached_modifier($, "~", "ordered_list", 1),
        ordered_list2: $ => nestable_detached_modifier($, "~", "ordered_list", 2),
        ordered_list3: $ => nestable_detached_modifier($, "~", "ordered_list", 3),
        ordered_list4: $ => nestable_detached_modifier($, "~", "ordered_list", 4),
        ordered_list5: $ => nestable_detached_modifier($, "~", "ordered_list", 5),
        ordered_list6: $ => nestable_detached_modifier($, "~", "ordered_list", 6),

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

        quote1: $ => nestable_detached_modifier($, ">", "quote", 1),
        quote2: $ => nestable_detached_modifier($, ">", "quote", 2),
        quote3: $ => nestable_detached_modifier($, ">", "quote", 3),
        quote4: $ => nestable_detached_modifier($, ">", "quote", 4),
        quote5: $ => nestable_detached_modifier($, ">", "quote", 5),
        quote6: $ => nestable_detached_modifier($, ">", "quote", 6),

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

        attribute1: $ => nestable_detached_modifier($, "%", "attribute", 1),
        attribute2: $ => nestable_detached_modifier($, "%", "attribute", 2),
        attribute3: $ => nestable_detached_modifier($, "%", "attribute", 3),
        attribute4: $ => nestable_detached_modifier($, "%", "attribute", 4),
        attribute5: $ => nestable_detached_modifier($, "%", "attribute", 5),
        attribute6: $ => nestable_detached_modifier($, "%", "attribute", 6),

        // ------------------------------------------------------------------------

        rangeable_detached_modifiers: $ => choice(
            $.definition_list,
            $.footnote_list,
            $.table,
        ),

        definition_list:   $ => prec.right(repeat1(choice($.single_definition, $.multi_definition))),

        single_definition: $ => rangeable_detached_modifier($, "$", false, "definition"),
        multi_definition:  $ => rangeable_detached_modifier($, "$", true, "definition"),
        definition_end:    $ => token(seq("$$", line_break)),

        footnote_list:     $ => prec.right(repeat1(choice($.single_footnote, $.multi_footnote))),

        single_footnote:   $ => rangeable_detached_modifier($, "^", false, "footnote"),
        multi_footnote:    $ => rangeable_detached_modifier($, "^", true, "footnote"),
        footnote_end:      $ => token(seq("^^", line_break)),

        table:             $ => prec.right(repeat1(choice($.single_table_cell, $.multi_table_cell))),

        single_table_cell: $ => rangeable_detached_modifier($, ":", false, "table_cell"),
        multi_table_cell:  $ => rangeable_detached_modifier($, ":", true, "table_cell"),
        table_cell_end:    $ => token(seq("::", line_break)),

        // ------------------------------------------------------------------------
        weak_delimiting_modifier:            _ => token(seq("--", i(repeat("-")), line_break)),
        strong_delimiting_modifier:          _ => token(seq("==", i(repeat("=")), line_break)),
        horizontal_line_delimiting_modifier: _ => token(seq("__", i(repeat("_")), line_break)),

        // ------------------------------------------------------------------------
        // TODO: Detached mod extensions
        // ------------------------------------------------------------------------

        slide: $ => seq(
            ":",
            line_break,
            $.non_structural,
        ),

        // TODO: Indent Segments

        // ------------------------------------------------------------------------

        tags: $ => choice(
            $.infirm_tag,
        ),

        tag_name: $ => prec.right(
            seq(
                alias(/[a-zA-Z0-9\-_]+/, $.word),
                repeat(
                    seq(
                        alias($.infirm_tag_begin, "_delimiter"),
                        alias(/[a-zA-Z0-9\-_]+/, $.word),
                    ),
                ),
            ),
        ),

        tag_parameter: _ => /[^\s]+/,

        infirm_tag: $ => prec.right(
            seq(
                $.infirm_tag_begin,
                $.tag_name,
                repeat($.tag_parameter),
            ),
        ),
    },
});

function heading($, level) {
    let subheadings = [];

    for (let i = level + 1; i <= 6; i++) {
        subheadings.push($["heading" + i]);
    }

    return prec.right(
        seq(
            "*".repeat(level),
            $._whitespace,
            choice(
                field("title", $.paragraph_segment),
                $.slide,
            ),
            line_break,

            field("content",
                repeat(
                    choice(
                        $.non_structural,
                        ...subheadings,
                    ),
                ),
            ),

            optional($.weak_delimiting_modifier),
        )
    );
}

function nestable_detached_modifier($, char, name, level) {
    let submodifiers = [];

    for (let i = level + 1; i < 6; i++) {
        submodifiers.push($[name + i]);
    }

    return prec.right(
        seq(
            char.repeat(level),
            $._whitespace,
            choice(
                field("content", $.paragraph),
                $.slide,
            ),

            repeat(
                choice(
                    ...submodifiers,
                ),
            ),
        )
    );
}

function rangeable_detached_modifier($, char, multi, name) {
    if (multi) {
        return prec(1,
            seq(
                char.repeat(2),
                $._whitespace,
                choice(
                    field("title", $.paragraph_segment),
                    $.slide,
                ),
                line_break,
                repeat($.non_structural),
                // NOTE: This does not work for example with the following input:
                // $$ Definition
                // $ Nested Definition
                // content
                // $$
                //
                // There must be a paragraph break after the nested definition. Is this intended?
                $[name + "_end"],
            )
        );
    }
    else {
        return seq(
            char,
            $._whitespace,
            field("title", $.paragraph_segment),
            line_break,
            field("content", $.paragraph),
        );
    }
}
