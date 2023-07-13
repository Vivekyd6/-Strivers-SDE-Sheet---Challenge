/*
 * Definition for linked list.
 * class Node {
 *  public:
 *		int data;
 *		Node *next;
 * 		Node *child;
 *		Node() : data(0), next(nullptr), child(nullptr){};
 *		Node(int x) : data(x), next(nullptr), child(nullptr) {}
 *		Node(int x, Node *next, Node *child) : data(x), next(next), child(child) {}
 * };
 */

Node* merge(Node* a, Node*b){
	if(a==NULL) {
		b->next = NULL;
		return b;
	}
	if(b==NULL) {
		a->next = NULL;
		return a;
	}

	Node* ans = NULL;
	if(a->data<b->data){
		ans = a;
		a->child = merge(a->child , b);
	}
	else{
		ans = b;
		b->child = merge(a , b->child);
	}

	ans->next = NULL;
	return ans;

}
Node* flattenLinkedList(Node* head) 
{
	// Write your code here
	if(head == NULL || head->next == NULL) return head;
	head->next =flattenLinkedList(head->next);
	head = merge(head , head->next);
	return head;
}
