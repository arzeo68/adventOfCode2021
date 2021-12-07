//
// Created by alexis on 07/12/2021.
//

#include "header.hpp"
#include <bits/stdc++.h>

void day07Part1()
{
    std::vector<std::string> input = readFile("../input");
    std::vector<int> values = stringToIntArray(input[0], ',');
    int min = *std::min_element(values.begin(), values.end());
    int max = *std::max_element(values.begin(), values.end());
    std::vector<int> result;
    while (result.size() < max) {
        std::vector<int> moves;
        for (auto c : values) { moves.push_back(abs(min + result.size() - c)); }
        int distance = 0;
        for (auto& n : moves)
            distance += n;
        result.push_back(distance);
    }
    std::cout << "Day 07, part 1: " << *std::min_element(result.begin(), result.end()) << std::endl;
}

void day07Part2()
{
    std::vector<std::string> input = readFile("../input");
    std::vector<int> values = stringToIntArray(input[0], ',');
    int min = *std::min_element(values.begin(), values.end());
    int max = *std::max_element(values.begin(), values.end());
    std::vector<int> result;
    while (result.size() < max) {
        std::vector<int> moves;
        for (auto c : values) {
            int step = abs(min + result.size() - c);
            int stepToFuel = step * (step + 1) / 2;
            moves.push_back(stepToFuel);
        }
        int distance = 0;
        for (auto& n : moves)
            distance += n;
        result.push_back(distance);
    }
    std::cout << "Day 07, part 2: " << *std::min_element(result.begin(), result.end()) << std::endl;
}