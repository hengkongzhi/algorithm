#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <queue>
#include <algorithm>
#include <stdlib.h>
using namespace std;
class Solution 
{
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k)
    {
        vector<int> myV;
        for (int i = 0; i <= nums.size() - k; i++)
        {
            int max = nums[i];
            for (int j = i; j < i + k; j++)
            {
                if (nums[j] > max)
                {
                    max = nums[j];
                }
            }
            myV.push_back(max);

        }
        return myV;
    }
    int getMax(queue<int> myQ)
    {
        int max = myQ.front();
        while (!myQ.empty())
        {   
            if (myQ.front() >= max)
            {
                max = myQ.front();
            }
            cout << myQ.front() << endl;
            myQ.pop();
        }
        return max;
    }
    vector<int> maxSlidingWindow1(vector<int>& nums, int k)
    {
        
        vector<int> myV;
        queue<int> myQ;
        int index = 0;
        int max = nums[0];
        for (int i = 0; i < k; i++)
        {
            if (nums[i] > max)
            {
                max = nums[i];
            }
        }
        myV.push_back(max);
        for (int i = 0; i < nums.size(); i++)
        {
            
            if (index < k)
            {
                myQ.push(nums[i]);
                index++;
            }
            else if (index == k)
            {
                if (nums[i] >= max)
                {
                    myQ.pop();
                    myQ.push(nums[i]);
                    max = nums[i];
                }
                else
                {
                    if (myQ.front() == max)
                    {
                        myQ.pop();
                        myQ.push(nums[i]);
                        max = getMax(myQ);
                    }
                    else
                    {
                        myQ.pop();
                        myQ.push(nums[i]);
                    }
                }
                myV.push_back(max);
            }
            
        }
        return myV;
    }
    void queueAdj(queue<int>& myQ)
    {
        while (myQ.front() < myQ.back())
        {
            myQ.pop();
        }
    }
    vector<int> maxSlidingWindow2(vector<int>& nums, int k)
    {
        vector<int> myVec;
        queue<int> myQ;
        int index = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            if (index < k)
            {
                myQ.push(nums[i]);
                queueAdj(myQ);
                if (index == k - 1)
                {
                    myVec.push_back(myQ.front());
                }
                index++;
                continue;
            }
            if (index == k)
            {
                if (nums[i - k] == myQ.front())
                {
                    myQ.pop();
                    if (!myQ.empty())
                    {
                        queueAdj(myQ);
                    }
                }
                myQ.push(nums[i]);
                queueAdj(myQ);
                myVec.push_back(myQ.front());
            }
        }
        return myVec;
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
    vector<int> nums{1,3,-1,-3,5,3,6,7};
    sol.printVec(sol.maxSlidingWindow2(nums, 3));
    return 0;
}