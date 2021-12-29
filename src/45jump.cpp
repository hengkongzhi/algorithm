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
    void deal(map<int, pair<int, int>>& myMap, int index, int cover, int& count)
    {
        for (auto iter = myMap.begin(); iter != myMap.end(); iter++)
        {
            if (index <= iter->second.first)
            {
                count = iter->second.second + 1;
                break;
            }
        }
        pair<int, int> myP(cover, count);
        myMap.insert(pair<int, pair<int, int>>(index, myP));
    }
    int jump(vector<int>& nums)
    {
        if (nums.size() == 1)
        {
            return 0;
        }
        map<int, pair<int, int>> myMap;
        int lDistance = nums.size() - 1;
        int cover = 0;
        int count = 1;
        for (int i = 0; i <= cover; i++)
        {
            if (cover < i + nums[i])
            {
                cover = i + nums[i];
                deal(myMap, i, cover, count);
                count++;
            }
            if (cover >= lDistance)
            {
                break;
            }
        }
        return count - 1;
    }
    int jump1(vector<int>& nums)
    {
        if (nums.size() == 1)
        {
            return 0;
        }
        int cur = 0;
        int next = 0;
        int count = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            next = max(next, i + nums[i]);
            if (i == cur)
            {
                if (i == nums.size() - 1)
                {
                    break;
                }
                else
                {
                    count++;
                    cur = next;
                    if (next >= nums.size() - 1)
                    {
                        break;
                    }
                }
            }
        }
        return count;
    }
};
int main()
{
    Solution sol;
    vector<int> nums{3,1,2,3,1,2,3};
    cout << sol.jump1(nums) << endl;
    return 0;
}