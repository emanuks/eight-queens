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

int is_valid_eight_queens(std::string file_name) {
    std::ifstream file;
    bool board[8][8] = {false};
    file.open(file_name);

    if (file.is_open()) {
        std::string line;
        while (file) {
            std::getline(file, line);
            if (line.length() != 8) return -1;
        }
    } else {
        return -1;
    }

    file.close();
    return 0;
}
