#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>

using namespace std;

bool bingo(vector<int> board)
{
    int sum = 0;
    for(int i=0; i<5; i++)
    { // Check rows
        sum = 0;
        for(int j=0; j<5; j++) sum += board[i*5+j];
        if(sum==-5) return true;
    }
    for(int i=0; i<5; i++)
    { // Check cols
        sum = 0;
        for(int j=0; j<5; j++) sum += board[i+j*5];
        if(sum==-5) return true;
    }
    return false;
}

int sum_unmarked(vector<int> *board)
{
    int sum = 0;
    for(auto num: *board)
    {
        if(num!=-1) sum += num;
    }
    return sum;
}

bool iswinner(vector<int> winners,int m)
{
    for(auto num: winners)
    {
        if(num==m) return true;
    }
    return false;
}

std::pair<vector<vector<int>>,std::vector<int>> buildGame() {
    std::vector<int> nums;
    vector<vector<int>> boards;
    std::vector<int> board;
    ifstream fid("../input");
    string line;
    bool read_nums = false;

    while(getline(fid,line))
    {
        if(line.empty())
        {
            board.clear();
            continue;
        }
        stringstream ss(line);
        string value;
        if(!read_nums)
        {
            // Read up drawn numbers
            while(getline(ss,value,',')) nums.push_back(stoi(value));
            read_nums = true;
        }
        else
        {
            while(ss >> value) board.push_back(stoi(value));
            if(board.size()==25)
            {
                boards.push_back(board);
            }
        }
    }
    return std::make_pair(boards,nums);
}

int day04Part1()
{
    std::pair<vector<vector<int>>,std::vector<int>> res = buildGame();
    vector<vector<int>> boards = res.first;
    std::vector<int> nums = res.second;
    vector<int> winners,*boardp;
    int result1,result2;

    int nb = boards.size();

    for(auto num: nums)
    {
        for(int i=0; i<nb; i++)
        {
            boardp = &boards[i];
            if(iswinner(winners,i)) continue;
            replace(boardp->begin(),boardp->end(),num,-1);
            if(bingo(*boardp))
            {
                if(winners.size()==0) result1 = sum_unmarked(boardp)*num;
                if(winners.size()==nb-1) result2 = sum_unmarked(boardp)*num;
                winners.push_back(i);
            }
        }
    }

    printf("p1: %d\n", result1);
    printf("p2: %d\n", result2);
    return 0;
}

