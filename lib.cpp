//
// Created by alexis on 05/12/2021.
//

#include <fstream>
#include <sstream>
#include "header.hpp"

std::vector<int> readNumberInputFile(std::string fileName)
{
    std::vector<int> numbers;
    std::ifstream file(fileName);
    std::string line;
    while (std::getline(file, line)) {
        numbers.push_back(std::stoi(line));
    }
    return numbers;
}

std::vector<std::string> readFile(std::string fileName)
{
    std::vector<std::string> lines;
    std::ifstream file(fileName);
    std::string line;
    while (std::getline(file, line)) {
        lines.push_back(line);
    }
    return lines;
}

std::vector<std::pair<std::string, int>> readFileTextNumber(std::string fileName)
{
    std::vector<std::pair<std::string, int>> lines;
    std::ifstream file(fileName);
    std::string line;
    while (std::getline(file, line)) {
        std::stringstream ss(line);
        std::string text;
        int number;
        std::getline(ss, text, ' ');
        std::getline(ss, line, ' ');
        number = std::stoi(line);
        lines.emplace_back(text, number);
    }
    return lines;
}

int binaryToDecimal(std::string binary)
{
    int decimal = 0;
    int base = 1;
    int length = binary.length();
    for (int i = length - 1; i >= 0; i--) {
        if (binary[i] == '1') {
            decimal += base;
        }
        base *= 2;
    }
    return decimal;
}

std::vector<int> stringToIntArray(std::string str, char separator)
{
    std::vector<int> array;
    std::stringstream ss(str);
    std::string token;
    while (std::getline(ss, token, separator)) {
        array.push_back(std::stoi(token));
    }
    return array;
}