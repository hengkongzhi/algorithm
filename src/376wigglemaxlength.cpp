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
    int wiggleMaxLength(vector<int>& nums)
    {
        vector<int> newVec;
        for (int i = 0; i < nums.size(); i++)
        {
            if (i + 1 < nums.size())
            {
                newVec.push_back(nums[i + 1] - nums[i]);
            }
        }
        if (newVec.size() == 0)
        {
            return nums.size();
        }
        bool positive = false;
        int j = 0;
        while (j < newVec.size())
        {
            if (newVec[j] < 0)
            {
                positive = false;
                break;
            }
            else if (newVec[j] > 0)
            {
                positive = true;
                break;
            }
            else
            {
                j++;
            }
        }
        int count = 0;
        int sum = 0;
        for (int i = j; i < newVec.size(); i++)
        {
            sum += newVec[i];
            if ((positive && sum > 0) || (positive && newVec[i] > 0))
            {
                count++;
                positive = false;
                sum = 0;
                continue;
            }
            if ((positive == false && sum < 0) || (positive == false && newVec[i] < 0))
            {
                count++;
                positive = true;
                sum = 0;
                continue;
            }
        }
        return count + 1;
    }
};
int main()
{
    Solution sol;
    vector<int> g{33,53,12,64,50,41,45,21,97,35,47,92,39,0,93,55,40,46,69,42,6,95,51,68,72,9,32,84,34,64,6,2,26,98,3,43,30,60,3,68,82,9,97,19,27,98,99,4,30,96,37,9,78,43,64,4,65,30,84,90,87,64,18,50,60,1,40,32,48,50,76,100,57,29,63,53,46,57,93,98,42,80,82,9,41,55,69,84,82,79,30,79,18,97,67,23,52,38,74,15};
    cout << sol.wiggleMaxLength(g) << endl;
    return 0;
}