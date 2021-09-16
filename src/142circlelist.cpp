#include <iostream>
#include <vector>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
class Solution {
public:
    ListNode* detectCycle(ListNode* head)
    {
        if (head == nullptr)
        {
            return head;
        }
        vector<ListNode*> myVec;
        bool cirle = false;
        myVec.push_back(head);
        ListNode* cur = head->next;
        while (cur)
        {
            if (judgeEqual(myVec, cur))
            {
                return cur;
            }
            myVec.push_back(cur);
            cur = cur->next;
        }
        return nullptr;
    }
    bool judgeEqual(vector<ListNode*>& vec, ListNode* node)
    {
        for (auto tmp : vec)
        {
            if (tmp == node)
            {
                return true;
            }
        }
        return false;
    }
    ListNode* detectCycle1(ListNode* head)
    {
        if (head == nullptr)
        {
            return head;
        }
        ListNode* sl = head;
        ListNode* qk = head;
        ListNode* index1 = head;
        ListNode* index2 = nullptr;
        bool circle = false;
        while (qk && qk->next)
        {

            sl = sl->next;
            qk = qk->next->next;
            if (sl == qk)
            {
                circle = true;
                index2 = qk;
                break;
            }
        }
        if (circle)
        {
            while (index1)
            {
                if (index1 == index2)
                {
                    return index1;
                }
                index1 = index1->next;
                index2 = index2->next;
            }
        }
        return nullptr;
    }
    void printList(ListNode* head)
    {
        while (head)
        {
            cout << head->val << " ";
            head = head->next;
        }
        cout << endl;
    }
};
int main()
{
    Solution m;
    ListNode* head = new ListNode(6);
    ListNode* node1 = new ListNode(5);
    ListNode* node2 = new ListNode(4);
    ListNode* node3 = new ListNode(3);
    ListNode* node4 = new ListNode(2);
    ListNode* node5 = new ListNode(1);
    head->next = node1;
    node1->next = node2;
    node2->next = node3;
    node3->next = node4;
    node4->next = node5;
    node5->next = node3;
    cout << m.detectCycle1(head)->val << endl;
    return 0;
}