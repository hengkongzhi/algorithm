#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <queue>
#include <deque>
#include <algorithm>
#include <map>
#include <stdlib.h>
#include <math.h>
#include <sstream>
using namespace std;
class Solution 
{
public:
    vector<vector<char>> vecStr;
    void constructVec()
    {
        vector<char> tmp;
        vecStr.push_back(tmp);
        vecStr.push_back(tmp);
        tmp.push_back('a');
        tmp.push_back('b');
        tmp.push_back('c');
        vecStr.push_back(tmp);
        tmp.clear();
        tmp.push_back('d');
        tmp.push_back('e');
        tmp.push_back('f');
        vecStr.push_back(tmp);
        tmp.clear();
        tmp.push_back('g');
        tmp.push_back('h');
        tmp.push_back('i');
        vecStr.push_back(tmp);
        tmp.clear();
        tmp.push_back('j');
        tmp.push_back('k');
        tmp.push_back('l');
        vecStr.push_back(tmp);
        tmp.clear();
        tmp.push_back('m');
        tmp.push_back('n');
        tmp.push_back('o');
        vecStr.push_back(tmp);
        tmp.clear();
        tmp.push_back('p');
        tmp.push_back('q');
        tmp.push_back('r');
        tmp.push_back('s');
        vecStr.push_back(tmp);
        tmp.clear();
        tmp.push_back('t');
        tmp.push_back('u');
        tmp.push_back('v');
        vecStr.push_back(tmp);
        tmp.clear();
        tmp.push_back('w');
        tmp.push_back('x');
        tmp.push_back('y');
        tmp.push_back('z');
        vecStr.push_back(tmp);
        tmp.clear();
    }
    vector<int> nums;
    vector<string> ret;
    void func(int index, string str)
    {
        if (str.size() == nums.size())
        {
            ret.push_back(str);
            return;
        }
        int x = nums[index];
        for (int i = 0; i < vecStr[x].size(); i++)
        {
            func(index + 1, str + vecStr[x][i]);
        }
    }
    void constructNums(string& digits)
    {
        for (int i = 0; i < digits.size(); i++)
        {
            nums.push_back((int)(digits[i] - '0'));
        }
    }
    vector<string> letterCombinations(string digits)
    {
        constructNums(digits);
        if (nums.size() == 0)
        {
            return ret;
        }
        constructVec();
        func(0, "");
        return ret;
    }
    void vecPrint()
    {
        for (auto str : ret)
        {
            cout << str << " ";
        }
        cout << endl;
    }

};
int main()
{
    Solution sol;
    sol.letterCombinations("23");
    sol.vecPrint();
    return 0;
}