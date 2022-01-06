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
#include <list>
using namespace std;

class Solution
{
public:
    struct Cmp
    {
        bool operator() (vector<int>& it, vector<int>& ia)
        {
            if (it[0] > ia[0])
            {
                return true;
            }
            else if (it[0] < ia[0])
            {
                return false;
            }
            else
            {
                return it[1] < ia[1];
            }
        }
    };
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people)
    {
        sort(people.begin(), people.end(), Cmp());
        list<vector<int>> myList;
        for (int i = 0; i < people.size(); i++)
        {
            int pos = people[i][1];
            auto iter = myList.begin();
            while (pos--)
            {
                iter++;
            }
            list<vector<int>>::const_iterator iter1 = iter;
            myList.insert(iter1, people[i]);
        }
        return vector<vector<int>>(myList.begin(), myList.end());

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