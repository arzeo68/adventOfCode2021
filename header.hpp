//
// Created by alexis on 05/12/2021.
//

#ifndef ADVENTOFCODE_HEADER_HPP
#define ADVENTOFCODE_HEADER_HPP

#include <vector>
#include <string>
#include <iostream>

void day02Part1();
void day02Part2();
std::vector<int> readNumberInputFile(std::string fileName);
std::vector<std::string> readFile(std::string fileName);
std::vector<std::pair<std::string, int>> readFileTextNumber(std::string fileName);

#endif //ADVENTOFCODE_HEADER_HPP
