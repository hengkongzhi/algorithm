#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;
class Solution {
public:
    void constructMap(unordered_map<char, int>& myMap, string& str)
    {
        int lenS = str.size();
        for (int i = 0; i < lenS; i++)
        {
            auto iter = myMap.find(str[i]);
            if (iter == myMap.end())
            {
                myMap.insert(pair<char, int>(str[i], 1));
            }
            else
            {
                iter->second++;
            }
        }
    }
    bool judgeSame(unordered_map<char, int>& myMap1, unordered_map<char, int>& myMap2)
    {
        for (auto iter = myMap1.begin(); iter != myMap1.end(); iter++)
        {
            auto neter = myMap2.find(iter->first);
            if (neter != myMap2.end())
            {
                if (neter->second != iter->second)
                {
                    return false;
                }
            }
            else
            {
                return false;
            }
        }
        return true;
    }
    bool isAnagram(string s, string t) 
    {
        unordered_map<char, int> sMap;
        unordered_map<char, int> tMap;
        constructMap(sMap, s);
        constructMap(tMap, t);
        if (judgeSame(sMap, tMap) && judgeSame(tMap, sMap))
        {
            return true;
        }
        return false;
    }
    bool isAnagram1(string s, string t) 
    {
        int alpha[26] = {0};
        for (int i = 0; i < s.size(); i++)
        {
            alpha[s[i] - 'a']++;
        }
        for (int i = 0; i < t.size(); i++)
        {
            alpha[t[i] - 'a']--;
        }
        for (int i = 0; i < 26; i++)
        {
            if (alpha[i] != 0)
            {
                return false;
            }
        }
        return true;
    }
};
int main()
{
    string str1 = "hello";
    string str2 = "llohea";
    Solution solve;
    cout << (solve.isAnagram1(str1, str2) ? "TRUE" : "FALSE") << endl;
    return 0;
}