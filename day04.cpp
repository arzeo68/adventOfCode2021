//
// Created by alexis on 06/12/2021.
//

#include <sstream>
#include "header.hpp"

int computeResult(std::vector<std::vector<int>> board, int lastNumber) {
    int result = 0;
    for (int i = 0; i < board.size(); i++) {
        for (int j = 0; j < board[i].size(); j++) {
            if (board[i][j] != -1) {
                result += board[i][j];
            }
        }
    }
    return result * lastNumber;
}

int checkWinnerBoard(std::vector<std::vector<std::vector<int>>> boards) {
    for (int i = 0; i < boards.size(); i++) {
        // line
        bool boardValid = true;

        for (int line = 0; line < 5; line++) {
            for (int collumn = 0; collumn < 5; collumn++) {
                if (boards[i][line][collumn] != -1) boardValid = false;
            }
            if (boardValid) return i;
        }




        // column
    }
    return -1;
}

void printBoard(std::vector<std::vector<int>> board) {
    for (int i = 0; i < board.size(); i++) {
        for (int j = 0; j < board[i].size(); j++) {
            std::cout << board[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

void updateBoard(std::vector<std::vector<std::vector<int>>> &boards, int newNumber) {
    for (int i = 0; i < boards.size(); i++) {
        for (int j = 0; j < boards[i].size(); j++) {
            for (int k = 0; k < boards[i][j].size(); k++) {
                if (boards[i][j][k] == newNumber) {
                    boards[i][j][k] = -1;
                }
            }
        }
    }
}

std::vector<int> computeBoardLine(std::string text) {
    std::vector<int> numbers;
    for (int i = 0; i < text.size(); i++) {
        while (text[i] == ' ' && i < text.size()) {
            i++;
        }
        std::string number = "";
        while (text[i] != ' ' && i < text.size()) {
            number += text[i];
            i++;
        }
        numbers.push_back(std::stoi(number));
    }
    return numbers;
}

std::vector<std::vector<std::vector<int>>> computeGameBoard(std::vector<std::string> input) {
    std::vector<std::vector<std::vector<int>>> result;
    for (int i = 2; i < input.size(); i++) {
        std::vector<std::vector<int>> board;
        for (int line = 0; line < 5; line ++, i++) {
            board.emplace_back(computeBoardLine(input[i]));
        }
        result.push_back(board);
    }

    return result;
}

void day04Part1()
{
    std::cout << "day 4 part 1" << std::endl;
    std::vector<std::string> input = readFile("../input");
    std::vector<int> numbers = stringToIntArray(input[0], ',');
    std::vector<std::vector<std::vector<int>>> boards = computeGameBoard(input);
    for (int i = 0; i < numbers.size(); i++) {
        updateBoard(boards, numbers[i]);
        if (checkWinnerBoard(boards) != -1) {
            std::cout << "winner is " << checkWinnerBoard(boards) << std::endl;
            std::cout << "winner score = " << computeResult(boards[checkWinnerBoard(boards)], numbers[i]) << std::endl;
            return;
        }
    }
    for (int i = 0; i < boards.size(); i++) {
        std::cout << "BOARD#" << i << std::endl;
        printBoard(boards[i]);
        std::cout << std::endl;
    }
}


void day04Part2()
{

}
