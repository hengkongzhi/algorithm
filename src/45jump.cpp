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
    int jump(vector<int>& nums)
    {
        int lDistance = nums.size() - 1;
        int cover = 0;
        int count = 0;
        for (int i = 0; i <= cover; i++)
        {
            if (cover < i + nums[i])
            {
                cover = i + nums[i];
                count++;
            }
            if (cover >= lDistance)
            {
                break;
            }
        }
        return count;
    }
};
int main()
{
    Solution sol;
    vector<int> nums{8,2,4,4,4,9,5,2,5,8,8,0,8,6,9,1,1,6,3,5,1,2,6,6,0,4,8,6,0,3,2,8,7,6,5,1,7,0,3,4,8,3,5,9,0,4,0,1,0,5,9,2,0,7,0,2,1,0,8,2,5,1,2,3,9,7,4,7,0,0,1,8,5,6,7,5,1,9,9,3,5,0,7,5};
    cout << sol.canJump2(nums) << endl;
    return 0;
}