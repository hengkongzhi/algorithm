#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <queue>
#include <deque>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>
#include <map>
#include <stdlib.h>
#include <math.h>
#include <sstream>
#include <list>
using namespace std;

class Solution
{
public:
    int fib(int n)
    {
        if (n == 0)
        {
            return 0;
        }
        vector<int> dp(n + 1, 0);
        dp[0] = 0;
        dp[1] = 1;
        for (int i = 2; i <= n; i++)
        {
            dp[i] = dp[i - 1] + dp[i - 2];
        }
        return dp[n];
    }
    int fib1(int n)
    {
        if (n <= 1)
        {
            return n;
        }
        int a = 0;
        int b = 1;
        int sum = 0;
        for (int i = 2; i <= n; i++)
        {
            sum = a + b;
            a = b;
            b = sum;
        }
        return sum;
    }
    int fib2(int n)
    {
        if (n <= 1)
        {
            return n;
        }
        return fib2(n - 1) + fib2(n - 2);
    }
};
int main()
{
    Solution sol;
    cout << sol.fib(6) << endl;
    cout << sol.fib1(6) << endl;
    cout << sol.fib2(6) << endl;
    return 0;
}