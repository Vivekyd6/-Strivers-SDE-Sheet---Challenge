/****************************************************************

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


*****************************************************************/

Node *firstNode(Node *head)
{

// extension of fast and slow approach - 
   if(head == NULL || head->next == NULL) return NULL;
   Node* slow = head , *fast = head;
   while(fast && fast->next){
       slow = slow->next;
       fast = fast->next->next;
       if(slow == fast){
           Node* start = head;
           while(start!=slow){
               start = start->next;
               slow = slow->next;
           }
           return start;
       }
   }
   return NULL;
}