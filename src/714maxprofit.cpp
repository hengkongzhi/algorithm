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
    int maxProfit(vector<int>& prices, int fee)
    {
        if (prices.empty())
        {
            return 0;
        }
        int minN = prices[0];
        int maxN = prices[0];
        int sum = 0;
        int oneSum = 0;
        int preProfile = 0;
        int curProfile = 0;
        for (int i = 1; i < prices.size(); i++)
        {
            if (prices[i] < minN)
            {
                minN = prices[i];
                maxN = prices[i];
            }
            if (prices[i] > maxN)
            {
                maxN = prices[i];
            }
            curProfile = prices[i] - prices[i - 1];
            if (curProfile < 0)
            {
                if (preProfile >= 0)
                {
                    if (oneSum - fee < 0)
                    {
                        sum -= oneSum;
                        oneSum = 0;
                        preProfile = curProfile;
                        continue;
                    }
                    sum -= fee;
                    sum = max(sum, maxN - minN - fee);
                    sum = max(sum, 0);
                    oneSum = 0;
                }
            }
            else
            {
                sum += curProfile;
                oneSum += curProfile;
            }
            preProfile = curProfile;
        }
        if (preProfile > 0)
        {
            sum -= fee;
            sum = max(sum, maxN - minN - fee);
            sum = max(sum, 0);

        }
        return sum;
    }
    int getSum(vector<int>& rets)
    {
        int sum = 0;
        for (auto val : rets)
        {
            sum += val;
        }
        return sum;
    }
};
int main()
{
    Solution sol;
    vector<int> price = {4,5,2,4,3,3,1,2,5,4};
    cout << sol.maxProfit(price, 1) << endl;
    return 0;
}