#include <bits/stdc++.h>

/****************************************************************

    Following is the class structure of the Node class:

        class Node
        {
        public:
	        int data;
	        Node *next;
	        Node(int data)
	        {
		        this->data = data;
		        this->next = NULL;
	        }
        };

*****************************************************************/
Node* reverse(Node* head, int n, int b[], int i){

    while(b[i]==0 && i<n) i++;
    if(!head || !head->next || i == n) return head;
    int count = b[i];

   // reversering single list node
    Node* prev=NULL, *curr=head, *next;
    while(curr!=NULL && count--){
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    head->next = reverse(curr, n, b, i+1);
    return prev;

}
Node *getListAfterReverseOperation(Node *head, int n, int b[]){
	// Write your code here.
	if(head==NULL) return head;
	return reverse(head , n , b , 0);
}