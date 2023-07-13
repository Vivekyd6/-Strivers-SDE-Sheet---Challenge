#include <bits/stdc++.h>

/*************************************************************

    Following is the LinkedListNode class structure

    template <typename T>   
    class LinkedListNode
    {
        public:
        T data;
        LinkedListNode<T> *next;
        LinkedListNode<T> *random;
        LinkedListNode(T data)
        {
            this->data = data;
            this->next = NULL;
        }
    };

*************************************************************/

LinkedListNode<int> *cloneRandomList(LinkedListNode<int> *head)
{
    // Write your code here.
    unordered_map<LinkedListNode<int>* , LinkedListNode<int>*>mp;
    LinkedListNode<int>* tmp = head;
    while(tmp!=NULL){
        mp[tmp] = new LinkedListNode<int>(tmp->data);
        tmp = tmp->next;
    }

    tmp = head; 
    while(tmp!=NULL){
        mp[tmp]->next = mp[tmp->next];
        mp[tmp]->random = mp[tmp->random];
        tmp = tmp->next;
    }

    return mp[head];

   

 }
