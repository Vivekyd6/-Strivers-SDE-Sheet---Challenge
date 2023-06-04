#include <bits/stdc++.h>

/****************************************************************

    Following is the class structure of the LinkedListNode class:

    template <typename T>
    class LinkedListNode
    {
    public:
        T data;
        LinkedListNode<T> *next;
        LinkedListNode(T data)
        {
            this->data = data;
            this->next = NULL;
        }
    };

*****************************************************************/

LinkedListNode<int> *reverseLinkedList(LinkedListNode<int> *head) 
{
    // Write your code here
    // Approach 1 - 3 pointer approach 

    LinkedListNode<int>* prev = NULL;
    LinkedListNode<int>* next;
    LinkedListNode<int>* curr = head;

    while(curr){
        next = curr->next;
        curr->next = prev;
        prev = curr; 
        curr = next;
    }
    return prev;

    // Approach 2 - Recursive approach - 

    if(head==NULL|| head->next==NULL)
       return head;
    auto next=reverseLinkedList(head->next);
    head->next->next=head;
    head->next=NULL;
    return next;
}