//
// Created by alexis on 05/12/2021.
//

#include "../header.hpp"

void day02Part1() {
    std::vector<std::pair<std::string, int>> input = readFileTextNumber("../input");
    int horizontal = 0;
    int depth = 0;
    for (auto &i : input) {
        std::cout << i.first << ": " << i.second << std::endl;
        if (i.first == "forward") {
            horizontal += i.second;
        } else if (i.first == "down") {
            depth += i.second;
        } else if (i.first == "up") {
            depth -= i.second;
        }
    }
    std::cout << "horizontal " << horizontal << " depth " << horizontal<< " res " << horizontal * depth << std::endl;
}

void day02Part2() {
    std::vector<std::pair<std::string, int>> input = readFileTextNumber("../input");
    int horizontal = 0;
    int aim = 0;
    int depth = 0;
    for (auto &i : input) {
        if (i.first == "forward") {
            horizontal += i.second;
            depth += i.second * aim;
        } else if (i.first == "down") {
            aim += i.second;
        } else if (i.first == "up") {
            aim -= i.second;
        }
    }
    std::cout << "PART 02: horizontal " << horizontal << " depth " << horizontal<< " res " << horizontal * depth << std::endl;
}