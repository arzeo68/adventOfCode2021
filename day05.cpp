//
// Created by alexis on 07/12/2021.
//

#include "header.hpp"

int checkValueOver1(std::vector<std::vector<int>> grid) {
    int count = 0;
    for (int i = 0; i < grid.size(); i++) {
        for (int j = 0; j < grid[i].size(); j++) {
            if (grid[i][j] > 1) {
                count++;
            }
        }
    }
    return count;
}

void printGrid(std::vector<std::vector<int>> grid) {
    for (int i = 0; i < grid.size(); i++) {
        for (int j = 0; j < grid[i].size(); j++) {
            std::cout << grid[i][j] << "  ";
        }
        std::cout << std::endl;
    }
}

std::pair<int, int> findMax(std::vector<std::pair<std::pair<int,int>, std::pair<int,int>>> data) {
    int maxX = 0;
    int maxY = 0;
    for (auto &p : data) {
        if (p.first.first > maxX) {
            maxX = p.first.first;
        }
        if (p.first.second > maxY) {
            maxY = p.first.second;
        }
        if (p.second.first > maxX) {
            maxX = p.second.first;
        }
        if (p.second.second > maxY) {
            maxY = p.second.second;
        }
    }

    return std::make_pair(maxX, maxY);
}

std::vector<std::pair<std::pair<int,int>, std::pair<int,int>>> parseInput(std::vector<std::string> input) {
    const std::string middleSeparator = " -> ";
    std::vector<std::pair<std::pair<int,int>, std::pair<int,int>>> result;

    for (int i = 0; i < input.size(); i++) {
        std::string line = input[i];
        int x1,y1, x2, y2;
        int separator = line.find(',');
        x1 = std::stoi(line.substr(0, separator));
        line = line.substr(separator + 1);
        separator = line.find(middleSeparator);
        y1 = std::stoi(line.substr(0, separator));
        line = line.substr(separator + middleSeparator.size());
        x2 = std::stoi(line.substr(0, line.find(',')));
        line = line.substr(line.find(',') + 1);
        y2 = std::stoi(line);
        result.push_back(std::make_pair(std::make_pair(x1,y1), std::make_pair(x2,y2)));
    }


    return result;
}

void drawDiagonal(std::vector<std::vector<int>> &grid, std::pair<int, int> start, std::pair<int, int> end) {
    if (abs(start.first - end.first) != abs(start.second - end.second)) {
        std::cout << "Error: diagonal not aligned" << std::endl;
        return;
    }
    bool right = start.first < end.first;
    bool down = start.second < end.second;
    int x = start.first;
    int y = start.second;
    while (x != end.first || y != end.second) {
        grid[y][x]++;
        if (right) {
            x++;
        } else {
            x--;
        }
        if (down) {
            y++;
        } else {
            y--;
        }
    }
    grid[y][x]++;
}

void day05Part1() {
    std::vector<std::string> input = readFile("../input");
    std::vector<std::pair<std::pair<int,int>, std::pair<int,int>>>value = parseInput(input);
    std::pair<int, int> max = findMax(value);
    std::vector<std::vector<int>> grid(max.second + 1, std::vector<int>(max.first + 1, 0));
    std::cout << "GRID: height: " << grid.size() << " width: " << grid[0].size() << std::endl;
    for (auto &p : value) {
        if (p.first.first != p.second.first && p.first.second != p.second.second) {
            drawDiagonal(grid, p.first, p.second);
            continue;
        }
        std::cout << "apply " << p.first.first << " " << p.first.second << " -> " << p.second.first << " " << p.second.second << std::endl;
        if (p.first.first != p.second.first)
        { // if x different
            if (p.first.first < p.second.first) {
                for (int i = p.first.first; i <= p.second.first; i++) {
                    grid[p.first.second][i]++;
                }
            } else {
                for (int i = p.second.first; i <= p.first.first; i++) {
                    grid[p.first.second][i]++;
                }
            }
        }

        if (p.first.second != p.second.second)
        { // if x different
            if (p.first.second < p.second.second) {
                for (int i = p.first.second; i <= p.second.second; i++) {
                    grid[i][p.first.first]++;
                }
            } else {
                for (int i = p.second.second; i <= p.first.second; i++) {
                    grid[i][p.first.first]++;
                }
            }
        }
    }
    printGrid(grid);

    std::cout << "Over 1: " << checkValueOver1(grid) << std::endl;

}
//  18418 too low
void day05Part2() {

}