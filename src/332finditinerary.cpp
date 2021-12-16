#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <queue>
#include <deque>
#include <algorithm>
#include <unordered_set>
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

    void back(string findStr, vector<vector<string>>& tickets, vector<bool>& use)
    {
        if (count == use.size())
        {
            return;
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
                back(tickets[i][1], tickets, use);
                if (count == use.size())
                {
                    return;
                }
                else
                {
                    path.pop_back();
                }
                use[i] = false;
                count--;
            }
        }
    }
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        sort(tickets.begin(), tickets.end(), Compare());
        vector<bool> use(tickets.size(), false);
        back("JFK", tickets, use);
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
    vector<vector<string>> tickets = {{"AUA","EZE"},{"JFK","AUA"},{"EZE","ANU"},{"AXA","JFK"},{"AUA","JFK"},{"ADL","TIA"},{"AUA","AXA"},{"ADL","AUA"},{"AUA","AXA"},{"AXA","TIA"},{"EZE","AXA"},{"AXA","AUA"},{"ANU","JFK"},{"ADL","EZE"},{"ADL","ANU"},{"EZE","ADL"},{"AXA","AUA"},{"JFK","EZE"},{"AUA","JFK"},{"AUA","JFK"},{"AXA","JFK"},{"ADL","EZE"},{"AUA","EZE"},{"AUA","JFK"},{"AUA","JFK"},{"JFK","AXA"},{"TIA","AXA"},{"JFK","ADL"},{"ADL","AXA"},{"AXA","AUA"},{"AUA","AXA"},{"JFK","AXA"},{"TIA","JFK"},{"ANU","AXA"},{"JFK","AXA"},{"EZE","AXA"},{"AXA","EZE"},{"JFK","ADL"},{"EZE","AXA"},{"ANU","AXA"},{"AXA","JFK"},{"JFK","AUA"},{"AXA","EZE"},{"ADL","AXA"},{"AUA","ADL"},{"AUA","ADL"},{"AXA","AUA"},{"ADL","ANU"},{"ANU","AUA"},{"ADL","ANU"},{"JFK","ADL"},{"TIA","AUA"},{"EZE","AXA"},{"ANU","TIA"},{"AXA","ADL"},{"JFK","ANU"},{"ADL","ANU"},{"TIA","AUA"},{"ADL","ANU"},{"AUA","EZE"},{"JFK","ANU"},{"AUA","ANU"},{"ADL","AUA"},{"JFK","ADL"},{"TIA","JFK"},{"AXA","ANU"},{"AXA","ANU"},{"JFK","AXA"},{"AXA","JFK"},{"ANU","AXA"},{"ADL","EZE"},{"JFK","ANU"},{"JFK","AUA"},{"AXA","ANU"},{"JFK","TIA"},{"ANU","AXA"},{"JFK","AUA"},{"AXA","AUA"},{"ADL","EZE"},{"ADL","AXA"},{"JFK","TIA"},{"EZE","AUA"},{"AUA","ADL"},{"JFK","ADL"},{"EZE","TIA"},{"TIA","AXA"},{"AUA","ADL"},{"JFK","AUA"},{"JFK","AUA"},{"AUA","ANU"},{"JFK","ADL"},{"AXA","AUA"},{"EZE","JFK"},{"ANU","ADL"},{"ADL","EZE"},{"ANU","JFK"},{"EZE","ANU"},{"AUA","ANU"},{"JFK","EZE"},{"EZE","JFK"},{"AXA","AUA"},{"ANU","AUA"},{"TIA","JFK"},{"ANU","AXA"},{"TIA","ANU"},{"AUA","ADL"},{"ANU","AXA"},{"AXA","ADL"},{"AUA","AXA"},{"ADL","ANU"},{"EZE","AXA"},{"EZE","ANU"},{"AXA","EZE"},{"AUA","ADL"},{"AUA","ADL"},{"TIA","JFK"},{"JFK","AUA"},{"ADL","AUA"},{"AXA","TIA"},{"AXA","TIA"},{"AXA","ANU"},{"AUA","ADL"},{"AUA","AXA"},{"ADL","AUA"},{"ANU","TIA"},{"AUA","AXA"},{"ANU","TIA"},{"AXA","AUA"},{"EZE","JFK"},{"ADL","AUA"},{"ADL","EZE"},{"AXA","JFK"},{"JFK","TIA"},{"AUA","AXA"},{"AUA","AXA"},{"JFK","TIA"},{"EZE","ADL"},{"AUA","ADL"},{"ANU","AXA"},{"EZE","ADL"},{"ADL","ANU"},{"TIA","EZE"},{"ANU","AUA"},{"AUA","HBA"},{"JFK","AUA"},{"TIA","AUA"},{"TIA","ADL"},{"AXA","ADL"},{"EZE","AUA"},{"EZE","JFK"},{"ANU","TIA"},{"ANU","JFK"},{"EZE","AUA"},{"EZE","AUA"},{"ADL","JFK"},{"ADL","AUA"},{"ADL","AXA"},{"AXA","JFK"},{"AXA","AUA"},{"ANU","AUA"},{"ANU","JFK"},{"TIA","EZE"},{"ANU","AUA"},{"ADL","JFK"},{"JFK","ANU"},{"ADL","JFK"},{"ANU","AUA"},{"JFK","ADL"},{"AXA","ANU"},{"AXA","JFK"},{"JFK","ADL"},{"EZE","JFK"},{"TIA","AUA"},{"ANU","ADL"},{"AUA","AXA"},{"ADL","AXA"},{"AUA","JFK"},{"ADL","AXA"},{"EZE","ANU"},{"TIA","EZE"},{"EZE","JFK"},{"ADL","EZE"},{"ANU","JFK"},{"AUA","JFK"},{"ANU","JFK"},{"EZE","ADL"},{"AUA","ADL"},{"EZE","ANU"},{"AXA","EZE"},{"AXA","ADL"},{"JFK","TIA"},{"AUA","ADL"},{"EZE","TIA"},{"AXA","EZE"},{"EZE","AUA"},{"JFK","TIA"},{"AUA","AXA"},{"TIA","ANU"},{"AXA","JFK"},{"TIA","EZE"},{"EZE","ANU"},{"ANU","EZE"},{"JFK","TIA"},{"JFK","EZE"},{"TIA","AXA"},{"ANU","EZE"},{"AUA","TIA"},{"AXA","EZE"},{"ANU","AUA"},{"AUA","EZE"},{"AUA","EZE"},{"ADL","ANU"},{"AUA","AXA"},{"AXA","ADL"},{"JFK","EZE"}};
    sol.findItinerary(tickets);
    sol.vecPrint();
    return 0;
}