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
    vector<int> partitionLabels(string s)
    {
        vector<int> myV;
        map<char, int> myMap;
        for (int i = 0; i < s.size(); i++)
        {
            myMap[s[i]] = i;
        }
        int j = 0;
        while (j < s.size())
        {
            int max = myMap[s[j]];
            for (int i = j; i <= max; i++)
            {
                if (myMap[s[i]] > max)
                {
                    max = myMap[s[i]];
                }
            }
            myV.push_back(max - j + 1);
            j = max + 1;
        }
        return myV;
    }
    void printVec(const vector<int>& real)
    {
            for (auto num : real)
            {
                cout << num << " ";
            }
            cout << endl;
    }
};
int main()
{
    Solution sol;
    string str = "ababcbacadefegdehijhklij";
    sol.printVec(sol.partitionLabels(str));
    return 0;
}