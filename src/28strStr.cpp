#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
class Solution {
public:
    int strStr(string haystack, string needle) 
    {
        if (needle == "")
        {
            return 0;
        }
        int k = 0;
        int j = 0;
        for (int i = 0; i < haystack.size(); i++)
        {
            k = i;
            for (j = 0; j < needle.size(); j++)
            {
                if (k < haystack.size() && haystack[k] == needle[j])
                {
                    k++;
                }
                else
                {
                    break;
                }
            }
            if (j == needle.size())
            {
                return i;
            }
        }
        return -1;
    }
};
int main()
{
    string s1 = "aaaaa";
    string s2 = "";
    Solution solve;
    cout << solve.strStr(s1, s2) << endl;
    return 0;
}