/**
 * Definition for singly-linked list.
 * class Node {
 * public:
 *     int data;
 *     Node *next;
 *     Node() : data(0), next(nullptr) {}
 *     Node(int x) : data(x), next(nullptr) {}
 *     Node(int x, Node *next) : data(x), next(next) {}
 * };
 */

Node *rotate(Node *head, int k) {
     // Write your code here.

     if(!head || !head->next || k == 0) return head;

     auto curr  = head;
     int l = 1;
     while(curr->next!=NULL){
          curr = curr->next;
          l++;
     } 

     curr->next= head;
     k = k%l;
     k = l-k;

     while(k--) curr = curr->next;
     head = curr->next;
     curr->next = NULL;
     return head;
}