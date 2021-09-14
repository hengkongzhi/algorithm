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
    ListNode* reverseList(ListNode* head)
    {
        ListNode* cur = head;
        ListNode* pre = nullptr;
        ListNode* nex;
        while (cur)
        {
            nex = cur->next;
            cur->next = pre;
            pre = cur;
            cur = nex;
        }
        return pre;
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
    // ListNode* node1 = new ListNode(5);
    // ListNode* node2 = new ListNode(4);
    // ListNode* node3 = new ListNode(3);
    // ListNode* node4 = new ListNode(2);
    // ListNode* node5 = new ListNode(1);
    // head->next = node1;
    // node1->next = node2;
    // node2->next = node3;
    // node3->next = node4;
    // node4->next = node5;
    m.printList(head);
    m.printList(m.reverseList(head));
    return 0;
}