module.exports = grammar({
    name: "norg",

    rules: {
        document: $ => repeat(
            choice(
                $.word,
                $.whitespace,
            ),
        ),

        word: _ => /[^\s]+/,
        whitespace: _ => /[\t                　]+/,
    },
});
