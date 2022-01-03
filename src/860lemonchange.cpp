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
    bool lemonadeChange(vector<int>& bills)
    {
        map<int, int> myMap;
        for (int i = 0; i < bills.size(); i++)
        {
            if (bills[i] == 5)
            {
                myMap[5]++;
            }
            else if (bills[i] == 10)
            {
                myMap[10]++;
                myMap[5]--;
                if (myMap[5] < 0)
                {
                    return false;
                }
            }
            else
            {
                myMap[20]++;
                int a = myMap[5];
                int c = myMap[5];
                int d = myMap[10];
                a -= 3;
                c -= 1;
                d -= 1;
                if (a < 0 && (c < 0 || d < 0))
                {
                    return false;
                }
                if (c >= 0 && d >= 0)
                {
                    myMap[5] = c;
                    myMap[10] = d;
                    continue;
                }
                if (a >= 0)
                {
                    myMap[5] = a;
                }
            }
        }
        return true;
    }
};
int main()
{
    Solution sol;
    vector<int> cost{5,5,10,10,20};
    cout << sol.lemonadeChange(cost) << endl;
    return 0;
}