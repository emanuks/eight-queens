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

std::string format_collision(int x, int y, int i, int j) {
    return std::to_string(x) + "," +
        std::to_string(y) + " " +
        std::to_string(i) + "," +
        std::to_string(j) + "\n";
}

std::string check_if_threathens_other_queen(int x, int y, bool board[8][8]) {
    std::string collisions = "";
    for (int i = x + 1; i < 8; i++) {
        if (board[i][y])
            collisions += format_collision(x, y, i, y);
    }

    for (int j = y + 1; j < 8; j++) {
        if (board[x][j])
            collisions += format_collision(x, y, x, j);
    }

    for (int i = x + 1, j = y + 1; i < 8 && j < 8; i++, j++) {
        if (board[i][j])
            collisions += format_collision(x, y, i, j);
    }

    for (int i = x + 1, j = y - 1; i < 8 && j >= 0; i++, j--) {
        if (board[i][j])
            collisions += format_collision(x, y, i, j);
    }

    return collisions;
}

int is_valid_eight_queens(std::string file_name) {
    std::ifstream file;
    bool board[8][8] = {false};
    int row_count = 0;
    int queen_count = 0;
    std::string attacks = "";

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
            std::string currenct_attacks =
                check_if_threathens_other_queen(i, j, board);
            if (board[i][j] && currenct_attacks.length() > 0)
                attacks += currenct_attacks;
        }
    }

    if (attacks.length() > 0) {
        std::ofstream attacks_file ("attacks.txt");
        attacks_file << attacks;
        attacks_file.close();
        return 0;
    }

    return 1;
}
