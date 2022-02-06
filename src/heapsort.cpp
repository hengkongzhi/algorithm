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
    void adjustHeap(vector<int>& myV, int index, int length)
    {
        int val = myV[index];
        for (int i = index * 2 + 1; i < length; i = i * 2 + 1)
        {
            if (i + 1 < length && myV[i] < myV[i + 1])
            {
                i++;
            }
            if (myV[i] > val)
            {
                myV[index] = myV[i];
                index = i;
            }
            else
            {
                break;
            }
        }
        myV[index] = val;
    }
    void heapSort(vector<int>& myV)
    {
        int len = myV.size();
        int begin = len - 1;
        if (len % 2 == 0)
        {
            begin = (len - 1 - 1) / 2;
        }
        else
        {
            begin = (len - 1) / 2 - 1;
        }
        for (; begin >= 0; begin--)
        {
            adjustHeap(myV, begin, len);
        }
        vecPrint(myV);
        for (int i = len - 1; i >= 0; i--)
        {
            swap(myV[0], myV[i]);
            adjustHeap(myV, 0, i);
        }
    }
    void vecPrint(vector<int>& myV)
    {
        for (auto val : myV)
        {
            cout << val << " ";
        }
        cout << endl;
    }
};
int main()
{
    Solution sol;
    vector<int> myV{200, 123, -100, 1, 2, 18, 23, -20, 100, 201};
    sol.vecPrint(myV);
    sol.heapSort(myV);
    sol.vecPrint(myV);
    return 0;
}