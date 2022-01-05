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
    bool judge(vector<int>& vec1, vector<int>& vec2)
    {
        if (vec1[0] >= vec2[0])
        {
            return true;
        }
        return false;
    }
    void deleFunc(vector<bool>& del, vector<vector<int>>& myVec2)
    {
        auto iter = myVec2.begin();
        for (int i = del.size() - 1; i >= 0; i--)
        {
            if (del[i])
            {
                myVec2.erase(iter + i);
            }
        }
    }
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people)
    {
        sort(people.begin(), people.end(), Cmp());
        deque<vector<int>> myQ1;
        vector<vector<int>> myVec2;
        for (int i = 0; i < people.size(); i++)
        {
            int count = check(myQ1, people[i]);
            if (count < 0)
            {
                int j = 0;
                vector<bool> myDel(myVec2.size(), false);
                while (j < myVec2.size() && count < 0)
                {
                    if (judge(myVec2[j], people[i]))
                    {
                        myQ1.push_back(myVec2[j]);
                        myDel[j] = true;
                        count++;
                    }
                    j++;
                }
                deleFunc(myDel, myVec2);
                if (count < 0)
                {
                    myVec2.push_back(people[i]);
                }
                else
                {
                    myQ1.push_back(people[i]);
                }
            }
            else if (count > 0)
            {
                deque<vector<int>> tmp;
                while (count--)
                {
                    tmp.push_front(myQ1.back());
                    myQ1.pop_back();
                }
                while (!tmp.empty())
                {
                    myVec2.push_back(tmp.front());
                    tmp.pop_front();
                }
                myQ1.push_back(people[i]);
            }
        }
        while (!myVec2.empty())
        {
            myQ1.push_back(*myVec2.begin());
            auto iter = myVec2.begin();
            myVec2.erase(iter);
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
    vector<vector<int>> cost{{8,2},{4,1},{0,3},{3,2},{8,1},{4,0},{7,0},{6,2},{8,0},{4,7}};
    sol.printVec(sol.reconstructQueue(cost));
    return 0;
}