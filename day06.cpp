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


std::vector<int> nextGeneration(std::vector<int> current)
{
    int toAdd = 0;
    for(int i = 0; i < current.size(); i++)
    {
        if (current[i] == 0) {
            current[i] = 6;
            toAdd++;
        } else {
            current[i]--;
        }

    }
    for (int i = 0; i < toAdd; i++)
    {
        current.push_back(8);
    }

    for (int i = 0; i < current.size(); i++)
    {
        std::cout << current[i] << " ";
    }
    std::cout << std::endl;

    return current;
}

std::vector<int> runSimulation(std::vector<int> start, int day) {
    for (int i = 1; i <= day; i++) {
        start = nextGeneration(start);
        std::cout << "day: " << i << "  number of fish: " << start.size() << std::endl;
    }
    std::cout << "Day " << day << ": " << start.size() << std::endl;
    return start;
}

void day06Part1()
{
    std::vector<std::string> input = readFile("../input");
    std::vector<int> start = stringToIntArray(input[0], ',');
//    runSimulation(start, 20);
    test(start, 256);

}

void day06Part2()
{

}