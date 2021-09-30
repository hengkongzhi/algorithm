#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
class Solution {
public:
    string reverseWords(string s)
    {
        vector<string> vecStr;
        int i = 0;
        while (s[i++] == ' ');
        int start = i - 1;
        int j = s.size() - 1;
        while (s[j--] == ' ');
        int end = j + 1;
        string tmp;
        j = 0;
        for (int k = start; k <= end; k++)
        {
            
            if (s[k] != ' ')
            {
                tmp.push_back(s[k]);
                j++;
            }
            else
            {
                while (s[k++] == ' ');
                k -= 2;
                j++;
                vecStr.push_back(tmp);
                tmp.clear();
            }
        }
        vecStr.push_back(tmp);
        tmp.clear();
        tmp.resize(j);
        i = 0;
        for (int k = vecStr.size() - 1; k >= 0; k--)
        {
            
            for (int m = 0; m < vecStr[k].size(); m++)
            {
                tmp[i++] = vecStr[k][m];
            }
            if (k != 0)
            {
                tmp[i++] = ' ';
            }
        }
        return tmp;

    }
    string reverseWords1(string s)
    {
        int fast = 0;
        int slow = 0;
        while (s[fast++] == ' ');
        fast -= 1;
        for (; fast < s.size(); fast++)
        {
            if (fast > 0 && s[fast] == s[fast - 1] && s[fast] == ' ')
            {
                continue;
            }
            s[slow++] = s[fast];
        }
        if (s[slow - 1] == ' ')
        {
            s.resize(slow - 1);
        }
        else
        {
            s.resize(slow);
        }
        reverse(s.begin(), s.end());
        int start = 0;
        int end = 0;
        bool on = true;
        for (int i = 0; i < s.size(); i++)
        {
            if (on && s[i] != ' ')
            {
                start = i;
                on = false;
            }
            if (s[i] == ' ')
            {
                end = i;
                reverse(s.begin() + start, s.begin() + end);
                on = true;
            }
            if (i == s.size() - 1)
            {
                end = i + 1;
                reverse(s.begin() + start, s.begin() + end);
            }
        }
        return s;
    }
};
int main()
{
    string s = "  Bob    Loves  Alice   ";
    Solution solve;
    cout << solve.reverseWords1(s) << endl;
    return 0;
}