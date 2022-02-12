#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <unistd.h>
using namespace std;
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target)
    {
        for (int i = 0; i < nums.size(); i++)
        {
            for (int j = i + 1; j < nums.size(); j++)
            {
                if (nums[i] + nums[j] == target)
                {
                    return {i, j};
                }
            }
        }
        return {};
    }
    void funcTest1()
    {
        srand(0);
        char sz[3] = {'a', 'b', 'c'};
        for (int i = 0; i < 100000000; i++)
        {
            int a = rand() % 3;
            int b = rand() % 3;
            int c = rand() % 3;
            string tmp = "" + sz[a] + sz[b] + sz[c];
        }
    }
    void funcTest2()
    {
        srand(0);
        char sz[4] = {'a', 'b', 'c', 'd'};
        for (int i = 0; i < 100000000; i++)
        {
            int a = rand() % 4;
            int b = rand() % 4;
            int c = rand() % 4;
            int d = rand() % 4;
            string tmp = "" + sz[a] + sz[b] + sz[c] + sz[d];
        }
    }
    vector<int> twoSum1(vector<int>& nums, int target)
    {
        unordered_map<int, int> myMap;
        funcTest1();
        funcTest2();
        for (int i = 0; i < nums.size(); i++)
        {
            auto iter = myMap.find(target - nums[i]);
            if (iter != myMap.end())
            {
                return {iter->second, i};
            }
            else
            {
                myMap.insert(pair<int, int>(nums[i], i));
            }
        }

        return {};
    }
    void printVec(const vector<int>& nums1)
    {
        for (int i = 0; i < nums1.size(); i++)
        {
            cout << nums1[i] << " ";
        }
        cout << endl;
    }
};
int main(int argc, char** argv)
{
    vector<int> nums1{2,7,11,15};
    vector<int> nums2{3,3};
    Solution solve;
    if (argc < 2)
    {
        cout << "argc is less 2" << endl;
        cout << "eg: ./1arrtwonumand 1" << endl;
        cout << "or eg: ./1arrtwonumand 2" << endl;
        return 0;
    }
    int index = atoi(argv[1]);
    if (index == 1)
    {
        solve.printVec(solve.twoSum1(nums2, 6));
    }
    else
    {
        solve.printVec(solve.twoSum(nums2, 6));
    }
    return 0;
}