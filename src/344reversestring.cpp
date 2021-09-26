#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
class Solution {
public:
    void reverseString(vector<char>& s) 
    {
        int len = s.size();
        int subLen = s.size() / 2;
        for (int i = 0; i < subLen; i++)
        {
            int j = len - i - 1;
            char tmp = s[i];
            s[i] = s[j];
            s[j] = tmp;
        }
    } 
    void reverseString1(vector<char>& s)
    {
        for (int i = 0, j = s.size() - 1; i < s.size() / 2; i++, j--)
        {
            swap(s[i], s[j]);
        }
    }
    void reverseString2(vector<char>& s)
    {
        reverse(s.begin(), s.end());
    }
    void printVecChar(const vector<char>& myVec)
    {
        for (auto var : myVec)
        {
            cout << var << " ";
        }
        cout << endl;
    }
};
int main()
{
    vector<char> s{'h','e','l','l','o','1','2','3'};
    Solution solve;
    solve.reverseString2(s);
    solve.printVecChar(s);
    return 0;
}