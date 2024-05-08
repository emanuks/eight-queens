/*******************************************************
* Copyright (C) 2024 emanuks <emanuels313@gmail.com>
*
* This file is part of eight-queens.
*
* eight-queens can not be copied and/or distributed without the express
* permission of emanuks
*******************************************************/

// This tells Catch to provide a main() - only do this in one cpp file
#define CATCH_CONFIG_MAIN
#include "./catch.hpp"
#include "./eight_queens.hpp"

TEST_CASE("Eight Queens - Valid", "[eight_queens]") {
}

TEST_CASE("Eight Queens - Invalid", "[eight_queens]") {
    REQUIRE(is_valid_eight_queens("invalid_board_eight_queens.txt") == -1);
    REQUIRE(is_valid_eight_queens("valid_board_without_eight_queens.txt") == -1);
}
