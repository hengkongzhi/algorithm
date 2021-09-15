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
    ListNode* removeNthFromEnd(ListNode* head, int n)
    {
        if (head == nullptr)
        {
            return head;
        }
        vector<ListNode*> vec;
        ListNode* cur = head;
        while (cur)
        {
            vec.push_back(cur);
            cur = cur->next;
        }
        int pos = vec.size() - n;
        if (pos < 0)
        {
            return head;
        }
        else if (pos == 0)
        {
            if (vec.size() > 1)
            {
                return vec[1];
            }
            else
            {
                return nullptr;
            }
        }
        else
        {
            if (vec.size() > pos + 1)
            {
                vec[pos - 1]->next = vec[pos + 1];
            }
            else
            {
                vec[pos - 1]->next = nullptr;
            }
        }
        return head;
    }
    ListNode* removeNthFromEnd1(ListNode* head, int n)
    {
        if (head == nullptr)
        {
            return head;
        }
        ListNode* dump = new ListNode(0);
        dump->next = head;
        ListNode* cur = head;
        int len = 0;
        int index = 0;
        while (cur)
        {
            len++;
            cur = cur->next;
        }
        int pos = len - n;
        if (pos < 0)
        {
            head = dump->next;
            delete dump;
            return head;
        }
        cur = head;
        ListNode* pre = dump;
        while (cur)
        {
            if (pos == index)
            {
                pre->next = cur->next;
                delete cur;
                break;
            }
            pre = cur;
            cur = cur->next;
            index++;
        }
        head = dump->next;
        delete dump;
        return head;
    }
    ListNode* removeNthFromEnd2(ListNode* head, int n)
    {
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* qk = dummy;
        ListNode* sl = dummy;
        while (n-- && qk)
        {
            qk = qk->next;
        }
        if (qk == nullptr)
        {
            delete dummy;
            return head;
        }
        qk = qk->next;
        while (qk)
        {
            sl = sl->next;
            qk = qk->next;
        }
        ListNode* tmp = sl->next;
        sl->next = sl->next->next;
        delete tmp;
        head = dummy->next;
        delete dummy;
        return head;
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
    m.printList(head);
    m.printList(m.removeNthFromEnd2(head, 6));
    return 0;
}