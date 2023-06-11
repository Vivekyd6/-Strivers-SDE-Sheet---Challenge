#include <bits/stdc++.h> 
/************************************************************

    Following is the TreeNode class structure

    template <typename T>
    class TreeNode {
       public:
        T val;
        TreeNode<T> *left;
        TreeNode<T> *right;
        
        TreeNode(T val) {
            this->val = val;
            left = NULL;
            right = NULL;
        }
    };

************************************************************/
TreeNode<int>* solve(vector<int>&arr , int l , int h){
    if(l>h) return NULL;
    int mid = l+(h-l)/2;
    TreeNode<int>* root = new TreeNode<int>(arr[mid]);
    root->left = solve(arr , l , mid-1);
    root->right = solve(arr , mid+1 , h);
    return root;
    
}
TreeNode<int>* sortedArrToBST(vector<int> &arr, int n)
{
    // Write your code here.
    return solve(arr , 0 , n-1);
}