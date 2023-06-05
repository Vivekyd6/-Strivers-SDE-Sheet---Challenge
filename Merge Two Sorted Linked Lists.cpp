#include <bits/stdc++.h>

/************************************************************

    Following is the linked list node structure.
    
    template <typename T>
    class Node {
        public:
        T data;
        Node* next;

        Node(T data) {
            next = NULL;
            this->data = data;
        }

        ~Node() {
            if (next != NULL) {
                delete next;
            }
        }
    };

************************************************************/

Node<int>* sortTwoLists(Node<int>* l1, Node<int>* l2)
{
//       Node<int>* temp(INT_MIN);
//       Node<int>* current=&temp;
      
//       while(l1 and l2)
//       {
//         if(l1->data < l2->data)
//         {current->next=l1;
//         l1=l1->next;}
        
//         else{
//           current->next=l2;
//           l2=l2->next;
//         }
//         current=current->next;
//       
//       current->next=l1?l1:l2;
//       return temp.next;
        
        if(l1 == NULL) return l2;
		if(l2 == NULL) return l1;
		if(l1->data < l2->data){
			l1->next = sortTwoLists(l1->next, l2);
			return l1;
		} else{
			l2->next = sortTwoLists(l1, l2->next);
			return l2;
        
    }
}
