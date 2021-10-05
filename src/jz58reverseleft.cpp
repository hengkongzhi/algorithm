#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
class Solution {
public:
    string reverseLeftWords(string s, int n) 
    {
        int len = s.size();
        reverse(s.begin(), s.end());
        reverse(s.begin(), s.begin() + len - n);
        reverse(s.begin() + len - n, s.end());
        return s;
    }
    string reverseLeftWords1(string s, int n) 
    {
        reverse(s.begin(), s.begin() + n);
        reverse(s.begin() + n, s.end());
        reverse(s.begin(), s.end());
        return s;
    }
};
int main()
{
    string s = "lrloseumgh";
    Solution solve;
    cout << solve.reverseLeftWords1(s, 6) << endl;
    return 0;
}