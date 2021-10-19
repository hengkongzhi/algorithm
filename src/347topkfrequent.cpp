#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <queue>
#include <deque>
#include <algorithm>
#include <map>
#include <stdlib.h>
using namespace std;
class Solution 
{
public:
    class MyFunc
    {
    public:
        bool operator()(pair<int, int>& a, pair<int, int>& b)
        {
            return a.second > b.second;
        }

    };
    vector<int> topKFrequent(vector<int>& nums, int k) 
    {
        vector<int> myV;
        map<int, int> myMap;
        vector<pair<int, int>> myPV;
        for (int i = 0; i < nums.size(); i++)
        {
            myMap[nums[i]]++;
        }
        
        for (auto iter = myMap.begin(); iter != myMap.end(); iter++)
        {
            myPV.push_back(*iter);
        }

        sort(myPV.begin(), myPV.end(), [](pair<int, int>& p1, pair<int, int>& p2){return p1.second > p2.second;});
        for (int i = 0; i < k; i++)
        {
            myV.push_back(myPV[i].first);
        }
        return myV;

    }
    vector<int> topKFrequent1(vector<int>& nums, int k) 
    {
        vector<int> myV(k);
        map<int, int> myMap;
        int idx = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            myMap[nums[i]]++;
        }
        priority_queue<pair<int, int>, vector<pair<int, int>>, MyFunc> myPri;
        for (auto iter = myMap.begin(); iter != myMap.end(); iter++)
        {
            myPri.push(*iter);
            idx++;
            if (idx > k)
            {
                myPri.pop();
                idx--;
            }
        }
        for (int i = k - 1; i >= 0; i--)
        {
            myV[i] = myPri.top().first;
            myPri.pop();
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
    sol.printVec(sol.topKFrequent1(nums, 2));
    return 0;
}