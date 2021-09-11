#include <iostream>
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
    ListNode* removeElements(ListNode* head, int val)
    {
        ListNode* pNode = head;
        ListNode* pPre = nullptr;
        ListNode* pCur = nullptr;
        ListNode* pRet = head;
        while (pNode)
        {
            pCur = pNode;
            if (pNode->val == val)
            {
                if (pPre)
                { 
                    pPre->next = pNode->next;
                    pNode = pNode->next;
                }
                else
                {
                    pRet = pNode->next;
                    pNode = pNode->next;
                    pPre = nullptr;
                }
                pCur->next = nullptr;
                delete pCur;
                pCur = nullptr;
                continue;
            }
            pNode = pNode->next;
            pPre = pCur;
        }
        return pRet;
    }
    ListNode* removeElements1(ListNode* head, int val)
    {
        ListNode* pCur = head;
        while (pCur && pCur->val == val)
        {
            ListNode* tmp = pCur;
            pCur = pCur->next;
            head = pCur;
            delete tmp;
        }
        while (pCur && pCur->next)
        {
            if (pCur->next->val == val)
            {
                ListNode* tmp = pCur->next;
                pCur->next = pCur->next->next;
                delete tmp;
            }
            else
            {
                pCur = pCur->next;
            }
        }
        return head;
    }
    ListNode* removeElements2(ListNode* head, int val)
    {
        ListNode* virHead = new ListNode(0);
        ListNode* pCur = virHead;
        pCur->next = head;
        while (pCur->next)
        {
            if (pCur->next->val == val)
            {
                ListNode* tmp = pCur->next;
                pCur->next = pCur->next->next;
                delete tmp;
            }
            else
            {
                pCur = pCur->next;
            }
        }
        head = virHead->next;
        delete virHead;
        return head;
    }
};
int main()
{
    Solution m;
    ListNode* head = new ListNode(6);
    ListNode* node1 = new ListNode(6);
    ListNode* node2 = new ListNode(6);
    ListNode* node3 = new ListNode(6);
    ListNode* node4 = new ListNode(6);
    ListNode* node5 = new ListNode(5);
    ListNode* node6 = new ListNode(6);
    head->next = node1;
    node1->next = node2;
    node2->next = node3;
    node3->next = node4;
    node4->next = node5;
    node5->next = node6;
    int target = 6;
    ListNode* pNode = m.removeElements2(head, target);
    while (pNode)
    {
        cout << pNode->val << endl;
        pNode = pNode->next;
    }

    return 0;
}