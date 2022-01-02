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
    struct Cmp
    {
        bool operator() (const int& a, const int& b) const
        {
            return a < b;
        }
    };
    int sum(vector<int>& ret)
    {
        int sum = 0;
        for (auto val : ret)
        {
            sum += val;
        }
        return sum;
    }
    int candy(vector<int>& ratings)
    {
        multimap<int, int, Cmp> myMap;
        vector<int> ret;
        for (int i = 0; i < ratings.size(); i++)
        {
            ret.push_back(-1);
            myMap.insert(pair<int, int>(ratings[i], i));
        }
        for (auto iter = myMap.begin(); iter != myMap.end(); iter++)
        {
            int index = iter->second;
            int left = 0;
            int right = 0;
            if (index == ratings.size() - 1)
            {
                if (index - 1 >= 0 && ratings[index] > ratings[index - 1])
                {
                    if (ret[index - 1] == -1)
                    {
                        left = 1;
                    }
                    else
                    {
                        left = ret[index - 1] + 1;
                    }
                }
                if (index - 1 >= 0 && ratings[index] <= ratings[index - 1])
                {
                    left = 1;
                }
                if (index - 1 < 0)
                {
                    left = 1;
                }
            }
            else if (index == 0)
            {
                if (index + 1 <= ratings.size() - 1 && ratings[index] > ratings[index + 1])
                {
                    if (ret[index + 1] == -1)
                    {
                        right = 1;
                    }
                    else
                    {
                        right = ret[index + 1] + 1;
                    }
                }
                if (index + 1 <= ratings.size() - 1 && ratings[index] <= ratings[index + 1])
                {
                    right = 1;
                }
                if (index + 1 == ratings.size())
                {
                    right = 1;
                }
            }
            else
            {
                if (ratings[index] > ratings[index - 1])
                {
                    if (ret[index - 1] == -1)
                    {
                        left = 1;
                    }
                    else
                    {
                        left = ret[index - 1] + 1;
                    }
                }
                else
                {
                    left = 1;
                }
                if (ratings[index] > ratings[index + 1])
                {
                    if (ret[index + 1] == -1)
                    {
                        right = 1;
                    }
                    else
                    {
                        right = ret[index + 1] + 1;
                    }
                }
                else
                {
                    right = 1;
                }
            }
            ret[index] = max(left, right);
        }
        return sum(ret);
    }
};
int main()
{
    Solution sol;
    vector<int> cost{1,2,2};
    cout << sol.candy(cost) << endl;
    return 0;
}