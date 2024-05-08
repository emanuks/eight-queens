# Eight Queens

Eight Queens problem solution checker, developed using Test Driven Development.

This function reads a file with a 0s ans 1s, where 0s represents empty squares and 1s represent squares with queens.

You must have eight queens placed on the board, if you don't the function will fail and return -1.

If you provide an invalid board the function will fail and return -1.

If you provided a valid board but an invalid solution for the problem, i.e. at least one queen threaten another, the function will return 0.

If you provided a valid board and a valid solution, the function will return 1.

### How to Run

1. Clone the repository.
2. Run `make` on your terminal to run all tests.

You can also use the converter as a library for other projects, by compiling eight_queens.o with your project and including eight_queens.hpp when necessary.
