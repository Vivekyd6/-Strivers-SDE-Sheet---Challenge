#include <bits/stdc++.h> 
/************************************************************

    Following is the TreeNode class structure:

    class BinaryTreeNode {
    public:
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;
        
        BinaryTreeNode(T data) {
            this->data = data;
            left = NULL;
            right = NULL;
        }
        
        ~BinaryTreeNode() {
            if (left) {
              delete left;
            }
            if (right) {
              delete right;
            }
        }
    };

************************************************************/

int findCeil(BinaryTreeNode<int> *node, int x){
    // Write your code here.
    int ans = -1;
    auto curr = node;
    while(curr){
        if(curr->data == x) {
            ans = curr->data;
            return ans;
        }
        if(curr->data <x){
            curr = curr->right;
        }
        else {
            ans = curr->data;
            curr = curr->left;
        }
    }

    return ans;
}