#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <queue>
#include <deque>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>
#include <map>
#include <stdlib.h>
#include <math.h>
#include <sstream>
using namespace std;

class Solution
{
public:
    vector<pair<int, int>> pos;
    vector<pair<int, int>>::iterator iter = pos.begin();
    map<pair<int, int>, vector<pair<int, int>>> mapVec;
    void constructMap()
    {
        for (int i = 0; i < 9; i++)
        {
            for (int j = 0; j < 9; j++)
            {
                pair<int, int> p(i, j);
                int klow = -1;
                int khigh = -1;
                int llow = -1;
                int lhigh = -1;
                if (i >= 0 && i < 3)
                {
                    klow = 0;
                    khigh = 2;
                }
                if (i >= 3 && i < 6)
                {
                    klow = 3;
                    khigh = 5;                    
                }
                if (i >= 6 && i < 9)
                {
                    klow = 6;
                    khigh = 8;
                }
                if (j >= 0 && j < 3)
                {
                    llow = 0;
                    lhigh = 2;
                }
                if (j >= 3 && j < 6)
                {
                    llow = 3;
                    lhigh = 5;                    
                }
                if (j >= 6 && j < 9)
                {
                    llow = 6;
                    lhigh = 8;
                }
                vector<pair<int, int>> tmp;
                for (int a = klow; a <= khigh; a++)
                {
                    for (int b = llow; b <= lhigh; b++)
                    {
                        if (a == i && b == j)
                        {
                            continue;
                        }
                        pair<int, int> tp(a, b);
                        tmp.push_back(tp);
                    }
                }
                pair<pair<int, int>, vector<pair<int, int>>> lastP(p, tmp);
                mapVec.insert(lastP);
            }
        }
    }
    bool judge(int row, int col, int val, vector<vector<char>>& board)
    {
        for (int i = 0; i < 9; i++)
        {
            if (i != col)
            {
                if (val + '0' == board[row][i])
                {
                    return false;
                }
            }
        }
        for (int i = 0; i < 9; i++)
        {
            if (i != row)
            {
                if (val + '0' == board[i][col])
                {
                    return false;
                }                
            }
        }

        auto iter = mapVec.find(pair<int, int>(row, col));
        for (auto v : iter->second)
        {
            if (val + '0' == board[v.first][v.second])
            {
                return false;
            }
        }
        return true;
    }
    bool back(vector<pair<int, int>>::iterator it, vector<vector<char>>& board)
    {
        if (it == pos.end())
        {
            return true;
        }
        for (int i = 1; i <= 9; i++)
        {
            if (judge(it->first, it->second, i, board))
            {
                board[it->first][it->second] = i + '0';
                it++;
                if (back(it, board))
                {
                    return true;
                }
                it--;
                board[it->first][it->second] = '.';
            }
            else
            {
                continue;
            }
        }
        return false;
    }
    void constructPos(vector<vector<char>>& board)
    {
        for (int i = 0; i < 9; i++)
        {
            for (int j = 0; j < 9; j++)
            {
                if (board[i][j] == '.')
                {
                    pos.push_back(pair<int, int>(i, j));
                }
            }
        }
    }
    void solveSudoku(vector<vector<char>>& board)
    {
        constructPos(board);
        constructMap();
        auto iter = pos.begin();
        back(iter, board);
    }
    void vecPrint(const vector<vector<char>>& board)
    {
        for (auto vec : board)
        {
            for (auto p : vec)
            {
                cout << p << " ";
            }
            cout << endl;
        }
    }

};
int main()
{
    Solution sol;
    vector<vector<char>> board = {{'5','3','.','.','7','.','.','.','.'},{'6','.','.','1','9','5','.','.','.'},{'.','9','8','.','.','.','.','6','.'},{'8','.','.','.','6','.','.','.','3'},{'4','.','.','8','.','3','.','.','1'},{'7','.','.','.','2','.','.','.','6'},{'.','6','.','.','.','.','2','8','.'},{'.','.','.','4','1','9','.','.','5'},{'.','.','.','.','8','.','.','7','9'}};
    sol.solveSudoku(board);
    sol.vecPrint(board);
    return 0;
}