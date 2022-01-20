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
    int uniquePaths(int m, int n)
    {
        vector<vector<int>> myVec(m, vector<int>(n));
        myVec[0][0] = 1;
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (i == 0 && j == 0)
                {
                    continue;
                }
                if (i - 1 < 0)
                {
                    myVec[i][j] = myVec[i][j - 1];
                    continue;
                }
                if (j - 1 < 0)
                {
                    myVec[i][j] = myVec[i - 1][j];
                    continue;
                }
                myVec[i][j] = myVec[i][j - 1] + myVec[i - 1][j];
            }
        }
        return myVec[m - 1][n - 1];
    }
};
int main()
{
    Solution sol;
    cout << sol.uniquePaths(3, 7) << endl;
    return 0;
}