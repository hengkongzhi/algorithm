#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
class Solution {
public:
    string replaceSpace(string s)
    {
        string str;
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] != ' ')
            {
                str.push_back(s[i]);
            }
            else
            {
                str.push_back('%');
                str.push_back('2');
                str.push_back('0');
            }
        }
        return str;
    }
    string replaceSpace1(string s)
    {
        int count = 0;
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == ' ')
            {
                count++;
            }
        }
        int oldInd = s.size() - 1;
        s.resize(s.size() + 2 * count);
        int newInd = s.size() - 1;
        for (int i = oldInd, j = newInd; i >= 0; i--)
        {
            if (s[i] != ' ')
            {
                s[j] = s[i];
                j--;
            }
            else
            {
                s[j] = '0';
                s[j - 1] = '2';
                s[j - 2] = '%';
                j -= 3;
            }
        }
        return s;
    }
};
int main()
{
    string s = "We are happy ";
    Solution solve;
    cout << solve.replaceSpace1(s) << endl;
    return 0;
}