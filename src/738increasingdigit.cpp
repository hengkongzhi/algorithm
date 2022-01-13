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
#include <list>
using namespace std;

class Solution
{
public:
    bool isIncreasing(int x)
    {
        vector<int> myV;
        int sum = x;
        while (sum)
        {
            myV.push_back(sum % 10);
            sum /= 10;
        }
        for (int i = 1; i < myV.size(); i++)
        {
            if (myV[i] > myV[i - 1])
            {
                return false;
            }
        }
        return true;
    }
    int monotoneIncreasingDigits(int n)
    {
        for (int i = n; i >= 0; i--)
        {
            if (isIncreasing(i))
            {
                return i;
            }
        }
        return 0;
    }
    int monotoneIncreasingDigits1(int n)
    {
        vector<int> myV;
        int sum = n;
        while (sum)
        {
            myV.push_back(sum % 10);
            sum /= 10;
        }
        for (int i = 0; i < myV.size(); i++)
        {
            if (i + 1 < myV.size() && myV[i] < myV[i + 1])
            {
                for (int j = 0; j <= i; j++)
                {
                    myV[j] = 9;
                }
                myV[i + 1] -= 1;
            }
        }
        int base = 10;
        sum = 0;
        for (int i = 0; i < myV.size(); i++)
        {
            sum += pow(base, i) * myV[i];
        }
        return sum;
    }
    void printVec(const vector<vector<int>>& real)
    {
        for (auto val : real)
        {
            for (auto num : val)
            {
                cout << num << " ";
            }
            cout << endl;
        }
    }
};
int main()
{
    Solution sol;
    cout << sol.monotoneIncreasingDigits1(603253281) << endl;
    return 0;
}