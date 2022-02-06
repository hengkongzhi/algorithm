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
    vector<int> initSort(vector<int>& myV)
    {
        if (myV.size() == 1)
        {
            return myV;
        }
        int len = myV.size() / 2;
        vector<int> leftVec(myV.begin(), myV.begin() + len);
        vector<int> left;
        left = initSort(leftVec);
        vector<int> rightVec(myV.begin() + len, myV.end());
        vector<int> right;
        right = initSort(rightVec);
        int i = 0, j = 0;
        vector<int> ret;
        while (i < left.size() && j < right.size())
        {
            if (left[i] <= right[j])
            {
                ret.push_back(left[i]);
                i++;
            }
            else
            {
                ret.push_back(right[j]);
                j++;
            }
        }
        while (i < left.size())
        {
            ret.push_back(left[i]);
            i++;
        }
        while (j < right.size())
        {
            ret.push_back(right[j]);
            j++;
        }
        return ret;
    }
    void andSort(vector<int>& myV)
    {
        vector<int> ret;
        ret = initSort(myV);
        myV.assign(ret.begin(), ret.end());
    }
    void vecPrint(vector<int>& myV)
    {
        for (auto val : myV)
        {
            cout << val << " ";
        }
        cout << endl;
    }
};
int main()
{
    Solution sol;
    vector<int> myV{200, 123, -100, 1, 175, 18, 23, -20, 100};
    sol.vecPrint(myV);
    sol.andSort(myV);
    sol.vecPrint(myV);
    return 0;
}