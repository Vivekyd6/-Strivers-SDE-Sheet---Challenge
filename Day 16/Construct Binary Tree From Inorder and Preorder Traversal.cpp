#include <bits/stdc++.h> 
/************************************************************

    Following is the TreeNode class structure

    template <typename T>
    class TreeNode {
       public:
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T data) {
            this->data = data;
            left = NULL;
            right = NULL;
        }
    };

************************************************************/
TreeNode<int>* solve(vector<int>&inorder , int l , int r , vector<int>&preorder , int s , int e , unordered_map<int , int>&mp){
     if(l>r || s>e) return NULL;
     TreeNode<int>*root = new TreeNode<int>(preorder[s]);
     int curridx = mp[root->data];
     int idx = curridx-l;

     root->left = solve(inorder , l , curridx-1 , preorder , s+1 , e+idx , mp);
     root->right = solve(inorder , curridx+1 , r , preorder , s+idx+1 , e, mp);
     return root;
}
TreeNode<int> *buildBinaryTree(vector<int> &inorder, vector<int> &preorder)
{
	//    Write your code here
    unordered_map<int , int>mp;
    int n = inorder.size();
    for(int i=0;i<n;i++) mp[inorder[i]]=i;
    return solve(inorder , 0 , n-1 , preorder , 0 , n-1 , mp);
}