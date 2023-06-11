#include <bits/stdc++.h> 
/************************************************************
    Following is the Binary Search Tree node structure
    
    template <typename T>
    class TreeNode {
        public :
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }

        ~TreeNode() {
            if(left)
                delete left;
            if(right)
                delete right;
        }
    };

************************************************************/

TreeNode<int>* LCAinaBST(TreeNode<int>* root, TreeNode<int>* p, TreeNode<int>*q)
{
	if(root==NULL)return NULL;
    if((root->data>p->data&&root->data<q->data)||(root->data>q->data&&root->data<p->data))return root;
    else if(root->data==p->data)return p;
    else if(root->data==q->data)return q;
    if(root->data>p->data) LCAinaBST(root->left,p,q);
    else LCAinaBST(root->right,p,q);
}
