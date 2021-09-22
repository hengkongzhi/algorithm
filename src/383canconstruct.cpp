#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
using namespace std;
class Solution {
public:
    bool canConstruct(string ransomNote, string magazine)
    {
        int arr[26] = {0};
        for (int i = 0; i < magazine.size(); i++)
        {
            arr[magazine[i] - 'a']++;
        }
        for (int i = 0; i < ransomNote.size(); i++)
        {
            arr[ransomNote[i] - 'a']--;
            if (arr[ransomNote[i] - 'a'] < 0)
            {
                return false;
            }
        }
        return true;
    }
};
int main()
{
    string ransomNote = "aa";
    string magazine = "aab";
    Solution solve;
    cout << (solve.canConstruct(ransomNote, magazine) ? "TRUE" : "FALSE") << endl;
    return 0;
}