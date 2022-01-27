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
    int ret = 0;
    int count = 0;
    int prob = 0;
    int realCount = 0;
    bool back(vector<int>& nums, vector<bool>& numB, int half)
    {
        if (ret == half && count != nums.size())
        {
            return true;
        }
        if (count >= nums.size() - 1)
        {
            return false;
        }
        for (int i = 0; i < nums.size(); i++)
        {
            if (numB[i] == false)
            {
                numB[i] = true;
                ret += nums[i];
                count++;
                bool res = back(nums, numB, half);
                if (res)
                {
                    return true;
                }
                else
                {
                    realCount++;
                    if (realCount > prob)
                    {
                        return false;
                    }
                }
                ret -= nums[i];
                count--;
                numB[i] = false;
            }
            if (i == nums.size() - 1)
            {
                i = 0;
                if (numB[i])
                {
                    ret -= nums[i];
                    count--;
                    numB[i] = false;
                }
            }
        }
        return false;
    }
    bool canPartition(vector<int>& nums)
    {
        int sum = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            sum += nums[i];
        }
        if (sum % 2 == 1)
        {
            return false;
        }
        int half = sum / 2;
        vector<int> dp(half + 1, 0);
        for (int i = 0; i < nums.size(); i++)
        {
            for (int j = half; j >= nums[i]; j--)
            {
                dp[j] = max(dp[j], dp[j - nums[i]] + nums[i]);
            }
        }
        if (dp[half] == half)
        {
            return true;
        }
        return false;
    }
};
int main()
{
    Solution sol;
    vector<int> weight{2, 2, 1, 1};
    cout << sol.canPartition(weight) << endl;
    return 0;
}