#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <queue>
#include <deque>
#include <algorithm>
#include <stdlib.h>
using namespace std;
class Solution 
{
public:
    vector<int> topKFrequent(vector<int>& nums, int k) 
    {
        vector<int> myV;
        vector<pair<int, int>> myPV;
        queue<int> myQ;
        sort(nums.begin(), nums.end());
        int count = 0;
        int pre = 0;
        for (auto num : nums)
        {
            if (myQ.empty())
            {
                myQ.push(num);
                pre = num;
                count++;
            }
            else
            {
                if (num == myQ.front())
                {
                    count++;
                }
                else
                {
                    myPV.push_back(pair<int, int>(pre, count));
                    myQ.pop();
                    myQ.push(num);
                    pre = num;
                    count = 1;
                }
            }
        }
        myPV.push_back(pair<int, int>(pre, count));

        sort(myPV.begin(), myPV.end(), [](pair<int, int>& p1, pair<int, int>& p2){return p1.second > p2.second;});
        for (int i = 0; i < k; i++)
        {
            myV.push_back(myPV[i].first);
        }
        return myV;

    }
    void printVec(const vector<int>& myV)
    {
        for (auto num : myV)
        {
            cout << num << ",";
        }
        cout << endl;
    }
};
int main()
{
    Solution sol;
    vector<int> nums{1, 2};
    sol.printVec(sol.topKFrequent(nums, 2));
    return 0;
}