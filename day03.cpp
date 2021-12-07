//
// Created by alexis on 05/12/2021.
//

#include "header.hpp"

void day03Part1() {
    std::vector<std::string>input = readFile("../input");
    std::string gamma;
    std::string epsilon;
    for (int byteIdx = 0; byteIdx < input[0].size(); byteIdx++) {
        int zero = 0;
        int one = 0;
        for (auto & lineIdx : input) {
            if (lineIdx[byteIdx] == '0') {
                zero++;
            } else {
                one++;
            }
        }
        if (zero > one) {
            gamma.push_back('0');
            epsilon.push_back('1');
        } else {
            gamma.push_back('1');
            epsilon.push_back('0');
        }
    }
    std::cout << "GAMMA: " << gamma << "   decimal:" << binaryToDecimal(gamma)  <<std::endl;
    std::cout << "EPSILON: " << epsilon << "   decimal:" << binaryToDecimal(epsilon)  <<std::endl;
    std::cout << "TOTAL: " << binaryToDecimal(gamma) * binaryToDecimal(epsilon)   <<std::endl;
}



std::vector<std::string> buildRemaining(std::vector<std::string> input, char match, int idx) {
    std::vector<std::string> remaining;
    for (auto & line : input)
    {
        if (line[idx] == match)
        {
            remaining.push_back(line);
        }
    }
    return remaining;
}


int computeOxygenGeneratorRating(std::vector<std::string> input) {
    std::vector<std::string> remaining = input;
    int byteIdx = 0;
    while (remaining.size() != 1 && byteIdx < input[0].size()) {
        int zero = 0;
        int one = 0;
        // compute number of each byte in the current byteIdx
        for (auto & lineIdx : remaining) {
            if (lineIdx[byteIdx] == '0') {
                zero++;
            } else {
                one++;
            }
        }
        if (zero > one) remaining = buildRemaining(remaining, '0', byteIdx);
        else remaining = buildRemaining(remaining, '1', byteIdx);

        byteIdx++;
    }
    std::cout << "oxygen: " << remaining[0] << "  decimal: " << binaryToDecimal(remaining[0]) << std::endl;
    return binaryToDecimal(remaining[0]);
}

int computeC02Rating(std::vector<std::string> input) {
    std::vector<std::string> remaining = input;
    int byteIdx = 0;
    while (remaining.size() != 1 && byteIdx < input[0].size()) {
        int zero = 0;
        int one = 0;
        // compute number of each byte in the current byteIdx
        for (auto & lineIdx : remaining) {
            if (lineIdx[byteIdx] == '0') {
                zero++;
            } else {
                one++;
            }
        }
        if (zero <= one) remaining = buildRemaining(remaining, '0', byteIdx);
        else remaining = buildRemaining(remaining, '1', byteIdx);

        byteIdx++;
    }
    std::cout << "C02: " << remaining[0] << "  decimal: " << binaryToDecimal(remaining[0]) << std::endl;
    return binaryToDecimal(remaining[0]);
}



void day03Part2() {
    std::vector<std::string>input = readFile("../input");
    int oxygenRating = computeOxygenGeneratorRating(input);
    int C02 = computeC02Rating(input);
    std::cout << "final: " << oxygenRating * C02 << std::endl;

}