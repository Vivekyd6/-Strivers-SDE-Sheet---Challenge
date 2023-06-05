/*
Following is the class structure of the Node class:

class Node
{
public:
    int data;
    Node *next;
    Node()
    {
        this->data = 0;
        next = NULL;
    }
    Node(int data)
    {
        this->data = data; 
        this->next = NULL;
    }
    Node(int data, Node* next)
    {
        this->data = data;
        this->next = next;
    }
};
*/

Node* removeKthNode(Node* head, int K)
{

    // Multiple approach - 
    // 1. Find the length , and then traverse till n-k+1 node and then delete it .
    // two traversal . 


    // Optimal solution - single traversal.
   Node* curr = head;
   while(K--){
       curr = curr->next;
   }
   Node* newHead = NULL;
   Node* start = head;
   while(curr!=NULL){
       newHead = start;
       curr = curr->next;
       start = start->next;
   }

   if(newHead == NULL) return head->next;
   newHead->next = start->next;
  return head;

}
