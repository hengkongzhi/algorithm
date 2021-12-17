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
    struct Compare
    {
        bool operator ()(vector<string>& it, vector<string>& at)
        {
            for (int i = 0; i < it.size(); i++)
            {
                if (it[i] < at[i])
                {
                    return true;
                }
                else if (it[i] == at[i])
                {
                    continue;
                }
                else
                {
                    return false;
                }
            }
            return true;
        }
    };
    vector<string> path;
    int count = 0;

    bool back(string findStr, vector<vector<string>>& tickets, vector<bool>& use)
    {
        if (count == use.size())
        {
            return true;
        }
        for (int i = 0; i < tickets.size(); i++)
        {
            if (use[i])
            {
                continue;
            }
            if (tickets[i][0] == findStr)
            {
                use[i] = true;
                count++;
                if (count == use.size())
                {
                    path.push_back(findStr);
                    path.push_back(tickets[i][1]);
                }
                else
                {
                    path.push_back(findStr);
                }
                if (back(tickets[i][1], tickets, use))
                {
                    return true;
                }
                else
                {
                    path.pop_back();
                }
                use[i] = false;
                count--;
            }
            return false;
        }
    }
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        sort(tickets.begin(), tickets.end(), Compare());
        vector<bool> use(tickets.size(), false);
        back("JFK", tickets, use);
        return path;
    }

    unordered_map<string, map<string, int>> tickets;
    bool goBack(int size)
    {
       if (count == size)
       {
           return true;
       } 
       for (auto& val : tickets[path.back()])
       {
           if (val.second > 0)
           {
               path.push_back(val.first);
               val.second--;
               count++;
               if (goBack(size))
               {
                   return true;
               }
               count--;
               val.second++;
               path.pop_back();
           }
       }
       return false;
    }
    vector<string> findItinerary1(vector<vector<string>>& tic)
    {
        for (auto vec : tic)
        {
            tickets[vec[0]][vec[1]]++;
        }
        path.push_back("JFK");
        goBack(tic.size());
        return path;
    }

    void vecPrint()
    {
        for (auto vec : path)
        {
            cout << vec << " ";
        }
        cout << endl;
    }

};
int main()
{
    Solution sol;
    vector<vector<string>> tickets = {{"JFK","SFO"},{"JFK","ATL"},{"SFO","ATL"},{"ATL","JFK"},{"ATL","SFO"}};
    sol.findItinerary1(tickets);
    sol.vecPrint();
    return 0;
}