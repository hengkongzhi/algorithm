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
    void getNext(int* next, string& s)
    {
        int j = -1;
        next[0] = j;
        for (int i = 1; i < s.size(); i++)
        {
            while (j >= 0 && s[i] != s[j + 1])
            {
                j = next[j];
            }
            if (s[i] == s[j + 1])
            {
                j++;
            }
            next[i] = j;
        }
    }
    int strStr1(string haystack, string needle)
    {
        const int sz = needle.size();
        if (sz == 0)
        {
            return 0;
        }
        int next[sz] = {0};
        getNext(next, needle);
        int j = -1;
        for (int i = 0; i < haystack.size(); i++)
        {
            while (j >= 0 && haystack[i] != needle[j + 1])
            {
                j = next[j];
            }
            if (haystack[i] == needle[j + 1])
            {
                j++;
            }
            if (j == needle.size() - 1)
            {
                return (i - needle.size() + 1);
            }
        }
        return -1;
    }
    void getNext1(int* next, string& s)
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
    int strStr2(string haystack, string needle)
    {
        const int sz = needle.size();
        if (sz == 0)
        {
            return 0;
        }
        int next[sz] = {0};
        getNext1(next, needle);
        int j = 0;
        for (int i = 0; i < haystack.size(); i++)
        {
            while (j > 0 && haystack[i] != needle[j])
            {
                j = next[j - 1];
            }
            if (haystack[i] == needle[j])
            {
                j++;
            }
            if (j == needle.size())
            {
                return (i - needle.size() + 1);
            }
        }
        return -1;
    }
};
int main()
{
    string s1 = "aabaa";
    string s2 = "baa";
    Solution solve;
    cout << solve.strStr2(s1, s2) << endl;
    return 0;
}