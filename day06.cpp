//
// Created by alexis on 07/12/2021.
//

#include <cmath>
#include "header.hpp"

long long int computeNumberOfFish(std::vector<long long int> current)
{
    long long int nbFish = 0;
    for (int i = 0; i < current.size(); i++)
    {
        nbFish += current[i];
    }
    return nbFish;
}

int test(std::vector<int> start, int day) {
    std::vector<long long int> current(9);
    for (int i = 0; i < start.size(); i++) {
        current[start[i]]++;
    }
    for (int i = 0; i < current.size(); i++) std::cout << current[i] << " ";
    std::cout << std::endl;

    for (int i = 0; i < day; i++) {
        long long int save = current[0];
        std::rotate(current.begin(), current.begin() + 1, current.end());
        current[6] += save;
        std::cout << "Day " << i + 1 << ": " << computeNumberOfFish(current) << std::endl;
    }

}

void day06Part1()
{
    std::vector<std::string> input = readFile("../input");
    std::vector<int> start = stringToIntArray(input[0], ',');
    test(start, 80);

}

void day06Part2()
{
    std::vector<std::string> input = readFile("../input");
    std::vector<int> start = stringToIntArray(input[0], ',');
    test(start, 256);
}