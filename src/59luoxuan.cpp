#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    vector<vector<int>> generateMatrix(int n)
    {
        vector<vector<int>> arr(n, vector<int>(n, 0));
        int i = 0;
        int j = 0;
        int h0 = 0;
        int s0 = 0;
        int hn = n - 1;
        int sn = n - 1;
        bool right = true;
        bool down = false;
        bool left = false;
        bool up = false;
        for (int index = 1; index <= n * n; index++)
        {
            arr[i][j] = index;
            if (index == n * n)
            {
                break;
            }
            if (right)
            {
                if (j + 1 > sn)
                {
                    h0++;
                    right = false;
                    down = true;
                    index--;
                    continue;
                }
                else
                {
                    j++;
                }
            }
            if (down)
            {
                if (i + 1 > hn)
                {
                    sn--;
                    down = false;
                    left = true;
                    index--;
                    continue;
                }
                else
                {
                    i++;
                }
            }
            if (left)
            {
                if (j - 1 < s0)
                {
                    hn--;
                    left = false;
                    up = true;
                    index--;
                    continue;
                }
                else
                {
                    j--;
                }
            }

            if (up)
            {
                if (i - 1 < h0)
                {
                    s0++;
                    up = false;
                    right = true;
                    index--;
                    continue;
                }
                else
                {
                    i--;
                }
            }
        }
        return arr;
    }
    vector<vector<int>> generateMatrix1(int n)
    {
        vector<vector<int>> arr(n, vector<int>(n, 0));
        int loop = n / 2;
        int count = 1;
        int startx = 0, starty = 0;
        int offset = 0;
        while (loop--)
        {
            int i = startx;
            int j = starty;
            for (; j < starty + n - offset - 1; j++)
            {
                arr[i][j] = count++;
            }
            for (; i < startx + n - offset - 1; i++)
            {
                arr[i][j] = count++;
            }
            for (; j > offset - starty; j--)
            {
                arr[i][j] = count++;
            }
            for (; i > offset - startx; i--)
            {
                arr[i][j] = count++;
            }
            startx++;
            starty++;
            offset += 2;
        }
        if (n % 2)
        {
            int pos = n / 2;
            arr[pos][pos] = count;
        }
        return arr;
    }
};
int main()
{
    Solution m;
    int n = 4;
    vector<vector<int>> arr = m.generateMatrix(n);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}