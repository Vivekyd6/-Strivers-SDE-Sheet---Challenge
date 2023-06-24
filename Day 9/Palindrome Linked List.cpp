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
LinkedListNode<int>* reverse(LinkedListNode<int>* ptr) {

    LinkedListNode<int>* prev = NULL , *next = NULL;
    while(ptr!=NULL) {
        next = ptr->next;
        ptr->next = prev;
        prev=ptr;
        ptr=next;
    }

    return prev;

}
bool isPalindrome(LinkedListNode<int> *head) {
    // Write your code here.

    if(!head || !head->next) return true;
    LinkedListNode<int> *slow = head, *fast = head;
    while(fast->next !=NULL && fast->next->next != NULL){
        slow = slow->next;
        fast = fast->next->next;
    }
    slow->next = reverse(slow->next);
    slow = slow->next;

    // comparing for palindrome
    LinkedListNode<int> *curr = head;
    while(slow!=NULL){
      if(curr->data!=slow->data) return false;
      curr= curr->next;
      slow = slow->next;
    }

    return true;

}