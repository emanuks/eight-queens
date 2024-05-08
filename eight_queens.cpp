/*******************************************************
* Copyright (C) 2024 emanuks <emanuels313@gmail.com>
*
* This file is part of eight-queens.
*
* eight-queens can not be copied and/or distributed without the express
* permission of emanuks
*******************************************************/

#include <iostream>
#include <fstream>
#include <string>

#include "./eight_queens.hpp"

bool check_if_threathens_other_queen(int x, int y, bool board[8][8]) {
    for (int i = x + 1; i < 8; i++) {
        if (board[i][y]) return true;
    }

    for (int j = y + 1; j < 8; j++) {
        if (board[x][j]) return true;
    }

    for (int i = x + 1, j = y + 1; i < 8 && j < 8; i++, j++) {
        if (board[i][j]) return true;
    }

    for (int i = x + 1, j = y - 1; i < 8 && j >= 0; i++, j--) {
        if (board[i][j]) return true;
    }

    return false;
}

int is_valid_eight_queens(std::string file_name) {
    std::ifstream file;
    bool board[8][8] = {false};
    int row_count = 0;
    int queen_count = 0;
    file.open(file_name);

    if (file.is_open()) {
        std::string line;
        while (file) {
            if (file.eof()) break;

            if (row_count == 8)
                return -1;

            std::getline(file, line);

            if (line.length() != 8) return -1;

            for (int i = 0; i < 8; i++) {
                if (line[i] == '1') {
                    board[row_count][i] = true;
                    queen_count++;
                }
            }

            row_count++;
        }
    } else {
        return -1;
    }

    if (row_count != 8 || queen_count != 8) return -1;

    file.close();

    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            if (board[i][j] && check_if_threathens_other_queen(i, j, board))
                return 0;
        }
    }

    return 1;
}
