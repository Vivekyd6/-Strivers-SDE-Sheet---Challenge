#include <bits/stdc++.h> 
/*************************************************************
 
    Following is the Binary Tree node structure

    class BinaryTreeNode 
    {
    public : 
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }
    };

*************************************************************/
 int depth(BinaryTreeNode<int>*  root){
        if(root==NULL) return 0;
        return 1 + max(depth(root->left),depth(root->right));
    }

    
bool isBalancedBT(BinaryTreeNode<int>* root) {
      queue<BinaryTreeNode<int>*>q;
      q.push(root);
      while(!q.empty()){
        auto tmp = q.front();
       
        int lh = depth(tmp->left);
        int rh = depth(tmp->right);
        if(abs(lh-rh)>1)
          return 0;
        if(tmp->left) q.push(tmp->left);
        if(tmp->right) q.push(tmp->right);
         q.pop();
      }
      return 1;
}