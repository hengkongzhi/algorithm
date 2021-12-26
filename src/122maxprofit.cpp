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
    int maxProfit(vector<int>& prices)
    {
        int ret = 0;
        for (int i = 0; i < prices.size() - 1; i++)
        {
            int diff = prices[i + 1] - prices[i];
            if (diff > 0)
            {
                ret += diff;
            }
        }
        return ret;
    }
};
int main()
{
    Solution sol;
    vector<int> nums{7,1,5,3,6,4};
    cout << sol.maxProfit(nums) << endl;
    return 0;
}