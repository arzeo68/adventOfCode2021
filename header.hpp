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

void day03Part1();
void day03Part2();

void day04Part1();
void day04Part2();

void day05Part1();
void day05Part2();

void day06Part1();
void day06Part2();

void day07Part1();
void day07Part2();


std::vector<int> readNumberInputFile(std::string fileName);
std::vector<std::string> readFile(std::string fileName);
std::vector<std::pair<std::string, int>> readFileTextNumber(std::string fileName);
int binaryToDecimal(std::string binary);
std::vector<int> stringToIntArray(std::string str, char separator);


#endif //ADVENTOFCODE_HEADER_HPP
