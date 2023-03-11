# Treesitter parser for [Norg](https://github.com/nvim-neorg/norg-specs)

This repository is an attempt at building on the initial [tree-sitter-norg](https://github.com/nvim-neorg/tree-sitter-norg)
parser in order to both decrease the size and increase the speed of the parser.

Upgrades from the old parser include:
- Grammar-based -- the old parser almost entirely relied on a C++ `scanner.cc`,
  which hindered error handling and parsing efficiency.
- Lightweight - the parser weights 4x less than the first generation parser,
  greatly thanks to a smarter design and a heavier reliance on the grammar.

Thanks to its smaller size, the parser should be embeddable almost anywhere.
