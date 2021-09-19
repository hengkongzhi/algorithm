#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>
using namespace std;
class Solution {
public:
    int n2(int n)
    {
        int sum = 0;
        while (n)
        {
            sum += (n % 10) * (n % 10);
            n /= 10;
        }
        return sum;
    }
    bool isHappy(int n)
    {
        unordered_set<int> noHappy;
        while (n != 1)
        {
            if (noHappy.find(n) != noHappy.end())
            {
                return false;
            }
            else
            {
                noHappy.insert(n);
            }
            n = n2(n);
        }
        return true;
    }
};
int main()
{
    Solution solve;
    cout << (solve.isHappy(2) ? "TRUE" : "FALSE") << endl;
    return 0;
}