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
        bool operator() (vector<int>& it, vector<int>& ia)
        {
            if (it[1] < ia[1])
            {
                return true;
            }
            else if (it[1] > ia[1])
            {
                return false;
            }
            else
            {
                return it[0] < ia[0];
            }
        }
    };
    int check(deque<vector<int>>& myQ1, vector<int>& myV)
    {
        // 0 success
        // > 0 more
        // < 0 less
        if (myQ1.empty())
        {
            myQ1.push_back(myV);
            return 0;
        }
        int count = 0;
        for (auto& val : myQ1)
        {
            if (val[0] >= myV[0])
            {
                count++;
            }
        }
        if (count == myV[1])
        {
            myQ1.push_back(myV);
        }
        return count - myV[1];
    }
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people)
    {
        sort(people.begin(), people.end(), Cmp());
        deque<vector<int>> myQ1;
        deque<vector<int>> myQ2;
        for (int i = 0; i < people.size(); i++)
        {
            int count = check(myQ1, people[i]);
            if (count < 0)
            {
                while (count++ && !myQ2.empty())
                {
                    if (!myQ2.empty())
                    {
                        myQ1.push_back(myQ2.front());
                        myQ2.pop_front();
                    }
                    
                }
                if (count < 0)
                {
                    myQ2.push_back(people[i]);
                }
                else
                {
                    myQ1.push_back(people[i]);
                }
            }
            else if (count > 0)
            {
                while (count--)
                {
                    myQ2.push_front(myQ1.back());
                    myQ1.pop_back();
                }
                myQ1.push_back(people[i]);
            }
        }
        while (!myQ2.empty())
        {
            myQ1.push_back(myQ2.front());
            myQ2.pop_front();
        }
        return vector<vector<int>>(myQ1.begin(), myQ1.end());
    }
    void printVec(const vector<vector<int>>& real)
    {
        for (auto val : real)
        {
            for (auto num : val)
            {
                cout << num << " ";
            }
            cout << endl;
        }
    }
};
int main()
{
    Solution sol;
    vector<vector<int>> cost{{9,0},{7,0},{1,9},{3,0},{2,7},{5,3},{6,0},{3,4},{6,2},{5,2}};
    sol.printVec(sol.reconstructQueue(cost));
    return 0;
}