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

Node* findIntersection(Node *firstHead, Node *secondHead)
{
    
    
    // edge case - no element in both linked list.
    if(firstHead==NULL and secondHead==NULL)
      return NULL;

    auto  ptr1= firstHead;
    auto  ptr2= secondHead;
  
    while(ptr1!=ptr2){
         ptr1=ptr1==NULL?firstHead:ptr1->next;
         ptr2=ptr2==NULL?secondHead:ptr2->next;
    }

    return ptr1;
}