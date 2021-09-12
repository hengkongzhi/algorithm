#include <iostream>
using namespace std;

class MyLinkedList
{
private:
    MyLinkedList* head;
    int sizeIndex;
    MyLinkedList(int num) : val(num), next(nullptr)  
    {

    }
public:
    /** Initialize your data structure here. */
    int val;
    MyLinkedList* next;
    MyLinkedList() {
        val = -1;
        next = nullptr;
        head = this;
        sizeIndex = -1;
    }
    
    /** Get the value of the index-th node in the linked list. If the index is invalid, return -1. */
    int get(int index) {
        if (sizeIndex < 0)
        {
            return -1;
        }
        else
        {
            if (index < 0)
            {
                return -1;
            }
            else if (index > sizeIndex)
            {
                return -1;
            }
            else
            {
                int i = 0;
                MyLinkedList* cur = head;
                while (cur)
                {
                    if (i == index)
                    {
                        return cur->val;
                    }
                    cur = cur->next;
                    i++;
                }
            }
        }
    }
    
    /** Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list. */
    void addAtHead(int val) {
        MyLinkedList* cur = head;
        if (cur->val != -1)
        {
            MyLinkedList* node = new MyLinkedList(val);
            node->next = cur;
            head = node;
        }
        else
        {
            cur->val = val;
        }
        sizeIndex++;
    }
    
    /** Append a node of value val to the last element of the linked list. */
    void addAtTail(int val) {
        MyLinkedList* cur = head;
        if (cur->val != -1)
        {
            MyLinkedList* node = new MyLinkedList(val);
            while (cur->next)
            {
                cur = cur->next;
            }
            cur->next = node;
        }
        else
        {
            cur->val = val;
        }
        sizeIndex++;
    }
    
    /** Add a node of value val before the index-th node in the linked list. If index equals to the length of linked list, the node will be appended to the end of linked list. If index is greater than the length, the node will not be inserted. */
    void addAtIndex(int index, int val) {

        if (index < 0)
        {
            addAtHead(val);
        }
        else if (index == sizeIndex + 1)
        {
            addAtTail(val);
        }
        else if (index > sizeIndex + 1)
        {
            return;
        }
        else
        {
            int i = 0;
            MyLinkedList* cur = head;
            MyLinkedList* pre = nullptr;
            while (cur)
            {
                if (index == i)
                {
                    MyLinkedList* node = new MyLinkedList(val);
                    if (pre)
                    {
                        pre->next = node;
                        node->next = cur;
                    }
                    else
                    {
                        node->next = cur;
                        head = node;
                    }
                    sizeIndex++;
                    return;
                }
                pre = cur;
                cur = cur->next;
                i++;
            }
        }

    }
    
    /** Delete the index-th node in the linked list, if the index is valid. */
    void deleteAtIndex(int index) {
        if (sizeIndex < 0)
        {
            return;
        }
        else
        {
            if (index < 0)
            {
                return;
            }
            else if (index > sizeIndex)
            {
                return;
            }
            else
            {
                int i = 0;
                MyLinkedList* cur = head;
                MyLinkedList* pre = nullptr;
                while (cur)
                {
                    if (i == index)
                    {
                        if (pre)
                        {
                            pre->next = cur->next;
                        }
                        else
                        {
                            head = cur->next;
                        }
                        sizeIndex--;
                        return;
                    }
                    pre = cur;
                    cur = cur->next;
                    i++;
                }
            }
        }
    }

    MyLinkedList* getHead() 
    {
        return head;
    }
};
void printList(MyLinkedList* head)
{
    while (head)
    {
        cout << head->val << endl;
        head = head->next;
    }
    cout << "------------------" << endl;
}
int main()
{
    MyLinkedList linkedList;
    linkedList.addAtHead(7);
    linkedList.addAtTail(7);
    linkedList.addAtHead(9);
    linkedList.addAtTail(8);
    linkedList.addAtHead(6);
    linkedList.addAtHead(0);
    cout << linkedList.get(5) << endl; 
    linkedList.addAtHead(0);
    cout << linkedList.get(2) << endl; 
    cout << linkedList.get(5) << endl;
    linkedList.addAtTail(4);
    printList(linkedList.getHead());

    return 0;
}