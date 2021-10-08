#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
class Solution {
public:
    void getNext(int* next, string& s)
    {
        int j = 0;
        next[0] = j;
        for (int i = 1; i < s.size(); i++)
        {
            while (j > 0 && s[i] != s[j])
            {
                j = next[j - 1];
            }
            if (s[i] == s[j])
            {
                j++;
            }
            next[i] = j;
        }
    }
    bool repeatedSubstringPattern(string s)
    {
        const int sz = s.size();
        int next[sz] = {0};
        getNext(next, s);
        int reptValue = 0;
        int start = 0;
        for (int i = sz - 1; i >= 0; i--)
        {
            if (next[i] == 0)
            {
                reptValue = i + 1;
                start = i + 1;
                break;
            }
        }
        int re = 1;
        for (int i = start; i < sz; i++)
        {
            if (re != next[i])
            {
                return false;
            }
            re++;
        }
        if (next[sz - 1] % reptValue != 0 || next[sz - 1] == 0)
        {
            return false;
        }
        return true;
    }
};
int main()
{
    string s1 = "a";
    Solution solve;
    cout << (solve.repeatedSubstringPattern(s1) ? "TRUE" : "FALSE") << endl;
    return 0;
}