#include <bits/stdc++.h> 
/************************************************************

    Following is the Binary Tree node structure
    
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
class node{
    public:
    int maxi;
    int mini;
    bool isBst;
    int size;
};

node solve(TreeNode<int>* root , int &res){
    if(root==NULL) return {INT_MIN, INT_MAX, 1 , 0};
    node left = solve(root->left , res);
    node right = solve(root->right , res);

    node curr;
    curr.size = left.size + right.size +1;
    curr.maxi = max(root->data , right.maxi);
    curr.mini = min(root->data , left.mini);


    if(left.isBst && right.isBst && root->data>left.maxi && root->data<right.mini){
        curr.isBst = true;
    }
    else curr.isBst = false;


    if(curr.isBst) res = max(res , curr.size);
    return curr;
}
int largestBST(TreeNode<int>* root) 
{
    // Write your code here.
    int res  =0;
    node tmp = solve(root , res);
    return res;
}
