#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
class Solution {
public:
    string reverseStr(string s, int k)
    {
        int len = s.size();
        int times = len / (2 * k);
        int yu = len % (2 * k);
        int count = 0;
        while (times--)
        {
            int i = 0 + count * 2 * k;
            int j = k - 1 + count * 2 * k;
            while (i < j)
            {
                swap(s[i], s[j]);
                i++;
                j--;
            }
            count++;
        }
        if (yu < 2 * k && yu >= k)
        {
            int i = 0 + count * 2 * k;
            int j = k - 1 + count * 2 * k;
            while (i < j)
            {
                swap(s[i], s[j]);
                i++;
                j--;
            }
        }
        if (yu < k)
        {
            int i = 0 + count * 2 * k;
            int j = yu - 1 + count * 2 * k;
            while (i < j)
            {
                swap(s[i], s[j]);
                i++;
                j--;
            }
        }
        return s;
    }
    string reverseStr1(string s, int k)
    {
        for (int i = 0; i < s.size(); i += (2 * k))
        {
            if (i + 2 * k < s.size())
            {
                reverse(s.begin() + i, s.begin() + i + k);
            }
            else if (i + k < s.size())
            {
                reverse(s.begin() + i, s.begin() + i + k);
            }
            else
            {
                reverse(s.begin() + i, s.end());
            }
        }
        return s;
    }
};
int main()
{
    string s = "hello123";
    Solution solve;
    cout << solve.reverseStr1(s, 2) << endl;
    return 0;
}