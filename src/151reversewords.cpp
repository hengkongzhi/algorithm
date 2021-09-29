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
};
int main()
{
    string s = "  Bob    Loves  Alice   ";
    Solution solve;
    cout << solve.reverseWords(s) << endl;
    return 0;
}