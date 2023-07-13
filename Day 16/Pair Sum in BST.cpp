#include <bits/stdc++.h> 
/**********************************************************

    Following is the Binary Tree Node structure:

    template <typename T>
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
            if (left)
                delete left;
            if (right)
                delete right;
        }
    };
***********************************************************/
bool solve(BinaryTreeNode<int>* root , int &k, unordered_set<int>&st){
    if(root==NULL) return false;
   
    if(st.find(k-root->data)!=st.end()) return true;
    st.insert(root->data);

    return (solve(root->right , k , st))  ||  (solve(root->left , k , st)) ;
}

bool pairSumBst(BinaryTreeNode<int> *root, int k)
{
    // Write your code here
    unordered_set<int>st;
    return solve(root , k , st);
}