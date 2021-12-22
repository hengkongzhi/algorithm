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
int findContentChildren(vector<int>& g, vector<int>& s)
{
    sort(g.begin(), g.end());
    sort(s.begin(), s.end());
    int i = 0;
    int j = 0;
    for (; i < g.size() && j < s.size(); j++)
    {
        if (g[i] <= s[j])
        {
            i++;
        }
    }
    return i;
}

};
int main()
{
    Solution sol;
    vector<int> g{1, 2, 3};
    vector<int> s{1, 1};
    cout << sol.findContentChildren(g, s) << endl;
    return 0;
}