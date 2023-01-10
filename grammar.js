let newline = choice("\n", "\r", "\r\n", "\0");

module.exports = grammar({
    name: "norg",

    // Tell treesitter we want to handle whitespace ourselves
    extras: $ => [$._preceding_whitespace],
    externals: $ => [$._preceding_whitespace],

    conflicts: $ => [
        [$.bold, $._markup_conflict],
        [$.italic, $._markup_conflict],
        [$.strikethrough, $._markup_conflict],
        [$.underline, $._markup_conflict],
    ],

    precedences: $ => [
        [$.heading1, $._markup_conflict],
        [$.unordered_list_item1, $._markup_conflict],
    ],

    inline: $ => [
    ],

    supertypes: $ => [
        $.non_structural,
        $.heading,
        $.attached_modifier,
        $.tag,
    ],

    rules: {
        document: $ => repeat(
            choice(
                $.heading,
                $.strong_delimiting_modifier,
                $.non_structural,
            ),
        ),

        _character: _ => token(/[^\s]/),
        _word: $ => prec.right(repeat1($._character)),
        _whitespace: _ => token(/[\t                　]+/),

        escape_sequence: $ => seq(
            "\\",
            alias(/./, $.escape_char),
        ),

        paragraph_segment: $ => seq(
            choice(
                $._word,
                $.escape_sequence,
                prec.dynamic(1, $.attached_modifier),
                $._markup_conflict,
            ),
            repeat(
                choice(
                    $._word,
                    $._whitespace,
                    $.escape_sequence,
                    prec.dynamic(1, $.attached_modifier),
                    $._markup_conflict,
                ),
            ),
        ),

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

        weak_delimiting_modifier: $ => token(prec(1, seq(
            "--",
            repeat("-"),
            newline,
        ))),

        strong_delimiting_modifier: $ => token(seq(
            "==",
            repeat("="),
            newline,
        )),

        horizontal_rule: $ => token(seq(
            "__",
            repeat("_"),
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
            $.horizontal_rule,
            $.tag,
            $.footnote_list,
        ),

        footnote_list: $ => prec.right(
            repeat1(
                choice(
                    $.single_footnote,
                    $.multi_footnote,
                ),
            ),
        ),
        single_footnote: $ => rangeable_single_detached_mod($, "$"),
        multi_footnote: $ => rangeable_multi_detached_mod($, "$$"),

        undone: _ => " ",
        done: _ => "x",
        pending: _ => "-",
        uncertain: _ => "?",
        on_hold: _ => "=",
        cancelled: _ => "_",
        urgent: _ => "!",
        recurring: _ => "+",
        date: _ => "@",
        priority: _ => "#",
        due: _ => "<",
        start: _ => ">",

        _detached_modifier_extension_parameter: $ => repeat1(choice($._word, $._whitespace)),

        detached_modifier_extension: $ => choice(
            $.undone,
            $.done,
            $.pending,
            $.uncertain,
            $.on_hold,
            $.cancelled,
            $.urgent,

            prec.right(seq(
                $.recurring,
                optional(
                    seq(
                        $._whitespace,
                        alias($._detached_modifier_extension_parameter, $.timestamp)
                    ),
                ),
            )),

            // TODO(vhyrro): Abstract this
            prec.right(seq(
                $.date,
                $._whitespace,
                alias($._detached_modifier_extension_parameter, $.timestamp),
            )),

            prec.right(seq(
                $.due,
                $._whitespace,
                alias($._detached_modifier_extension_parameter, $.timestamp),
            )),

            prec.right(seq(
                $.start,
                $._whitespace,
                alias($._detached_modifier_extension_parameter, $.timestamp),
            )),

            prec.right(seq(
                $.priority,
                $._whitespace,
                alias($._detached_modifier_extension_parameter, $.priorities),
            )),
        ),

        detached_modifier_extensions: $ => seq(
            "(",
            $.detached_modifier_extension,
            repeat(
                seq(
                    // NOTE(vhyrro): Yes, this is the only real way to represent this.
                    // It works somehow!
                    optional($._whitespace),
                    optional(newline),
                    optional($._whitespace),
                    "|",
                    optional($._whitespace),
                    optional(newline),
                    optional($._whitespace),
                    $.detached_modifier_extension,
                ),
            ),
            ")",
        ),

        attached_modifier: $ => choice(
            $.bold,
            $.italic,
            $.strikethrough,
            $.underline,
        ),

        bold: $ => prec.dynamic(1, prec.left(attached_mod($, "*"))),
        italic: $ => prec.dynamic(1, prec.left(attached_mod($, "/"))),
        strikethrough: $ => prec.dynamic(1, prec.left(attached_mod($, "-"))),
        underline: $ => prec.dynamic(1, prec.left(attached_mod($, "_"))),

        _markup_conflict: $ => token(choice(
            "*",
            "/",
            "-",
            "_",
        )),

        attribute_identifier: $ => seq(
            alias($._word, $.attribute_name),
            repeat(
                seq(
                    ":",
                    alias($._word, $.attribute_name),
                ),
            ),
        ),

        attached_modifier_extension: $ => seq(
            "(",
            $.attribute_identifier,
            repeat(
                seq(
                    // NOTE(vhyrro): Yes, this is the only real way to represent this.
                    // It works somehow!
                    optional($._whitespace),
                    optional(newline),
                    optional($._whitespace),
                    "|",
                    optional($._whitespace),
                    optional(newline),
                    optional($._whitespace),
                    $.attribute_identifier,
                ),
            ),
            ")",
        ),

        tag: $ => choice(
            $.ranged_verbatim_tag,
        ),

        tag_name: $ => seq(
            alias($._word, $.word),
            repeat(
                seq(
                    ".",
                    alias($._word, $.word),
                ),
            ),
        ),

        tag_parameter: $ => prec.right(repeat1(
            choice(
                $._word,
                $.escape_sequence,
            ),
        )),

        tag_parameters: $ => prec.right(seq(
            $.tag_parameter,
            repeat(
                seq(
                    $._whitespace,
                    $.tag_parameter,
                ),
            ),
        )),

        ranged_verbatim_tag: $ => prec.right(seq(
            ...tag($, "@"),
            alias(repeat(
                choice(
                    $._word,
                    $._whitespace,
                    newline,
                ),
            ), $.ranged_verbatim_content),
            seq(
                token("@end"),
                newline,
            ),
        )),
    },
});

function heading($, level) {
    // TODO: re-use nestable_detached_mod (?)
    return prec.right(seq(
        nestable_detached_mod_prefix($, "*", level),

        $._whitespace,

        optional(
            seq(
                $.detached_modifier_extensions,
                $._whitespace,
            ),
        ),

        field("title", $.paragraph_segment),

        newline,

        repeat(
            choice(
                $.non_structural,
                ...lower_level_items($, "heading", level),
            ),
        ),

        optional($.weak_delimiting_modifier),
    ));
}

function nestable_detached_mod($, type, chr, level) {
    return prec.right(
        seq(
            nestable_detached_mod_prefix($, chr, level),

            $._whitespace,

            optional(
                seq(
                    $.detached_modifier_extensions,
                    $._whitespace,
                ),
            ),

            field("content", $.paragraph),

            repeat(
                choice(
                    ...lower_level_items($, type, level),
                ),
            ),
        ),
    );
}

function nestable_detached_mod_prefix($, chr, level) {
    return alias(token(prec(1, chr.repeat(level))), $.prefix);
}

function rangeable_single_detached_mod($, chr) {
    return prec.right(
        seq(
            chr,

            $._whitespace,

            optional(
                seq(
                    $.detached_modifier_extensions,
                    $._whitespace,
                ),
            ),

            field("title", $.paragraph_segment),

            newline,

            field("content",
                choice(
                    $.paragraph,
                ),
            ),
        ),
    );
}

function rangeable_multi_detached_mod($, chr) {
    return prec.right(
        seq(
            chr,

            $._whitespace,

            optional(
                seq(
                    $.detached_modifier_extensions,
                    $._whitespace,
                ),
            ),

            field("title", $.paragraph_segment),

            newline,

            field("content",
                repeat1(
                    prec.left(
                        choice(
                            $.paragraph,
                            newline,
                            $.list,
                            $.quote,
                            $.horizontal_rule,
                            $.tag,
                        ),
                    ),
                ),
            ),

            seq(
                newline,

                optional($._whitespace),

                token(
                    seq(
                        chr,
                        newline,
                    ),
                ),
            ),
        ),
    );
}

function lower_level_items($, type, level) {
    let lower_level = []
    for (let i = level + 1; i <= 6; i++) {
        lower_level.push($[type + i]);
    }
    return lower_level;
}

function attached_mod($, char) {
    const anyobject = choice(
        $._word,
        $.attached_modifier,
        $._markup_conflict,
    );

    return seq(
        char,
        anyobject,
        optional(
            seq(
                repeat(
                    prec.right(choice(
                        anyobject,
                        $._whitespace,
                    )),
                ),
                anyobject,
            ),
        ),
        char,
        optional($.attached_modifier_extension),
    );
}

function tag($, char) {
    return [
        "@",
        $.tag_name,
        choice(
            seq(
                optional($._whitespace),
                newline,
            ),
            seq($._whitespace, $.tag_parameters, optional($._whitespace), newline),
        )
    ];
}
