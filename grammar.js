let newline = choice("\n", "\r", "\r\n");
let newline_or_eof = choice("\n", "\r", "\r\n", "\0");

module.exports = grammar({
    name: "norg",

    // Tell treesitter we want to handle whitespace ourselves
    extras: $ => [$._preceding_whitespace],
    externals: $ => [
        $._preceding_whitespace,
        $._weak_delimiting_modifier,

        $._bold_open,
        $._bold_close,
        $._italic_open,
        $._italic_close,
        $._strikethrough_open,
        $._strikethrough_close,
        $._underline_open,
        $._underline_close,
        $._spoiler_open,
        $._spoiler_close,
        $._verbatim_open,
        $._verbatim_close,
        $._superscript_open,
        $._superscript_close,
        $._subscript_open,
        $._subscript_close,
        $._inline_comment_open,
        $._inline_comment_close,
        $._inline_math_open,
        $._inline_math_close,
        $._inline_macro_open,
        $._inline_macro_close,
    ],

    conflicts: $ => [
        [$.bold, $._attached_modifier_conflict],
        [$.italic, $._attached_modifier_conflict],
        [$.strikethrough, $._attached_modifier_conflict],
        [$.underline, $._attached_modifier_conflict],
        [$.spoiler, $._attached_modifier_conflict],
        [$.verbatim, $._attached_modifier_conflict],
        [$.superscript, $._attached_modifier_conflict],
        [$.subscript, $._attached_modifier_conflict],
        [$.inline_comment, $._attached_modifier_conflict],
        [$.inline_math, $._attached_modifier_conflict],
        [$.inline_macro, $._attached_modifier_conflict],
    ],

    precedences: $ => [
    ],

    inlines: $ => [
    ],

    supertypes: $ => [
        $.non_structural,
        $.heading,
        $.attached_modifier,
        $.tag,
        $._attached_modifier_conflict,
        $.linkable,
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

        // TODO: Fix `hello ,*world*` failing`
        // TODO: Fix `:*hello*` not printing any bold
        // perhaps do something like `alias(":", $._word)`?
        paragraph_segment: $ => seq(
            choice(
                $._word,
                $.escape_sequence,
                $.linkable,
                $._inline_link_target_conflict_open,
                seq(
                    optional(
                        seq(
                            $._word,
                            $.link_modifier,
                        ),
                    ),
                    prec.dynamic(1, $.attached_modifier),
                    optional(
                        seq(
                            $.link_modifier,
                            $._word,
                        ),
                    ),
                ),
            ),
            repeat(
                choice(
                    seq(
                        $._whitespace,
                        choice(
                            $._word,
                            $._whitespace,
                            $.escape_sequence,
                            prec.dynamic(1, $.attached_modifier),
                            $._attached_modifier_conflict,
                            $.linkable,
                            $._inline_link_target_conflict_open,
                            seq(
                                optional(
                                    seq(
                                        $._word,
                                        $.link_modifier,
                                    ),
                                ),
                                prec.dynamic(1, $.attached_modifier),
                                optional(
                                    seq(
                                        $.link_modifier,
                                        $._word,
                                    ),
                                ),
                            ),
                        ),
                    ),
                    choice(
                        $._word,
                        $.escape_sequence,
                        $._attached_modifier_conflict,
                        $._inline_link_target_conflict_open,
                    ),
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
            newline_or_eof,
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

        weak_delimiting_modifier: $ => seq(
            $._weak_delimiting_modifier,
            newline_or_eof,
        ),

        strong_delimiting_modifier: $ => seq(
            "==",
            repeat("="),
            newline_or_eof,
        ),

        horizontal_rule: $ => seq(
            "__",
            repeat("_"),
            newline_or_eof,
        ),

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
            $.spoiler,
            $.verbatim,
            $.superscript,
            $.subscript,
            $.inline_comment,
            $.inline_math,
            $.inline_macro,
        ),

        bold: $ => prec.dynamic(1, attached_mod($, "bold", false)),
        italic: $ => prec.dynamic(1, attached_mod($, "italic", false)),
        strikethrough: $ => prec.dynamic(1, attached_mod($, "strikethrough", false)),
        underline: $ => prec.dynamic(1, attached_mod($, "underline", false)),
        spoiler: $ => prec.dynamic(1, attached_mod($, "spoiler", false)),
        verbatim: $ => prec.dynamic(1, attached_mod($, "verbatim", true)),
        superscript: $ => prec.dynamic(1, attached_mod($, "superscript", false)),
        subscript: $ => prec.dynamic(1, attached_mod($, "subscript", false)),
        inline_comment: $ => prec.dynamic(1, attached_mod($, "inline_comment", false)),
        inline_math: $ => prec.dynamic(1, attached_mod($, "inline_math", true)),
        inline_macro: $ => prec.dynamic(1, attached_mod($, "inline_macro", true)),

        _attached_modifier_conflict: $ => choice(
            $._bold_open,
            $._italic_open,
            $._strikethrough_open,
            $._underline_open,
            $._spoiler_open,
            $._superscript_open,
            $._subscript_open,
            $._inline_comment_open,
            $._inline_math_open,
            $._inline_macro_open,
        ),

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

        link_modifier: _ => ":",

        tag: $ => choice(
            $.ranged_verbatim_tag,
            $.infirm_tag,
            $.standard_ranged_tag,
            $.strong_carryover_tag,
            $.weak_carryover_tag,
            $.macro_tag,
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
                newline_or_eof,
            ),
        )),

        infirm_tag: $ => seq(
            ...tag($, ".")
        ),

        standard_ranged_tag: $ => seq(
            ...tag($, "|"),
            alias(repeat(
                choice(
                    $.heading,
                    $.strong_delimiting_modifier,
                    $.non_structural,
                ),
            ), $.ranged_tag_content),
            seq(
                token("|end"),
                newline_or_eof,
            ),
        ),

        macro_tag: $ => seq(
            ...tag($, "="),
            alias(repeat(
                choice(
                    $.heading,
                    $.strong_delimiting_modifier,
                    $.non_structural,
                ),
            ), $.ranged_tag_content),
            seq(
                token("=end"),
                newline_or_eof,
            ),
        ),

        strong_carryover_tag: $ => prec.right(seq(
            ...tag($, "#"),
            repeat(prec(1, newline)),
        )),

        weak_carryover_tag: $ => prec.right(seq(
            ...tag($, "+"),
            repeat(prec(1, newline)),
        )),

        linkable: $ => choice(
            $.inline_link_target,
            $.link,
            $.anchor_declaration,
            $.anchor_definition,
        ),

        _inline_link_target_conflict_open: $ => seq("<", newline_or_eof),

        inline_link_target: $ => seq(
            "<",
            /[^\n\r>]/,
            // TODO: Try to convert this to just an array of paragraph segments like in the
            // link description node?
            repeat(
                choice(
                    /[^\s\n\r>]/,
                    newline,
                    $._whitespace,
                    $.escape_sequence,
                    prec.dynamic(1, $.attached_modifier),
                    $._attached_modifier_conflict,
                    seq(
                        optional(
                            seq(
                                /[^\s\n\r>]/,
                                $.link_modifier,
                            ),
                        ),
                        prec.dynamic(1, $.attached_modifier),
                        optional(
                            seq(
                                $.link_modifier,
                                /[^\s\n\r>]/,
                            ),
                        ),
                    ),
                ),
            ),
            ">",
        ),

        weak_paragraph: $ => seq(
            $.paragraph_segment,
            repeat(
                seq(
                    newline,
                    $.paragraph_segment,
                ),
            ),
        ),

        _link_target: $ => choice(
            link_target($, /\*+/, "heading"),
            link_target($, "?", "wiki"),
            link_target($, "#", "generic"),
            link_target($, "/", "external_file"),
            link_target($, "@", "timestamp"),
            link_target($, "$", "definition"),
            link_target($, "^", "footnote"),
            field("target", alias(token(prec(-1, /[^}]+/)), $.url)),
            field("target", alias(/\d+/, $.line_number)),
        ),

        link_location: $ => seq(
            "{",
            choice(
                seq(
                    ":",
                    alias(/[^\n\r:]+/, $.filepath),
                    ":",
                    optional($._link_target),
                ),
                $._link_target,
            ),
            "}",
        ),

        link_description: $ => seq(
            "[",
            $.weak_paragraph,
            "]",
        ),

        link: $ => seq(
            $.link_location,
            optional($.link_description),
            optional($.attached_modifier_extension)
        ),

        anchor_declaration: $ => seq(
            $.link_description,
            optional($.link_description),
            optional($.attached_modifier_extension)
        ),

        anchor_definition: $ => seq(
            $.link_description,
            $.link_location,
            optional($.attached_modifier_extension)
        ),
    },
});

function heading($, level) {
    return prec.right(
        seq(
            nestable_detached_mod_prefix($, "*", level),

            $._whitespace,

            optional(
                seq(
                    $.detached_modifier_extensions,
                    $._whitespace,
                ),
            ),

            field("title", $.paragraph_segment),

            newline_or_eof,

            repeat(
                choice(
                    $.non_structural,
                    ...lower_level_items($, "heading", level),
                ),
            ),

            optional($.weak_delimiting_modifier),
        )
    );
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
    return alias(chr.repeat(level), $.prefix);
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
    return seq(
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

            field("content", repeat1($.non_structural)),

            chr,
            newline_or_eof,
    );
}

function lower_level_items($, type, level) {
    let lower_level = []
    for (let i = level + 1; i <= 6; i++) {
        lower_level.push($[type + i]);
    }
    return lower_level;
}

// TODO: Handle the following case: `/hello /`
function attached_mod($, name, verbatim) {
    if (verbatim) {
        return seq(
            $["_" + name + "_open"],
            repeat1(
                choice(
                    $._word,
                    $._whitespace,
                    $.escape_sequence,
                    $._attached_modifier_conflict,
                ),
            ),
            $["_" + name + "_close"],
            optional($.attached_modifier_extension),
        );
    }

    return seq(
        $["_" + name + "_open"],
        choice(
            $._word,
            $.escape_sequence,
            prec.dynamic(1, $.attached_modifier),
            $._attached_modifier_conflict,
        ),
        repeat(
            choice(
                $._word,
                $._whitespace,
                $.escape_sequence,
                prec.dynamic(1, $.attached_modifier),
                $._attached_modifier_conflict,
            ),
        ),
        $["_" + name + "_close"],
        optional($.attached_modifier_extension),
    );
}

function tag($, char) {
    return [
        char,
        $.tag_name,
        choice(
            seq(
                optional($._whitespace),
                newline_or_eof,
            ),
            seq($._whitespace, $.tag_parameters, optional($._whitespace), newline_or_eof),
        )
    ];
}

function link_target($, identifier, name) {
    return seq(
        field("target", alias(identifier, $[name])),
        $._whitespace,
        $.weak_paragraph,
    );
}
