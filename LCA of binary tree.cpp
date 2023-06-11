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

int lowestCommonAncestor(TreeNode<int> *root, int x, int y)
{
	if(!root) return -1;
    if(root->data == x || root->data == y)
       return root-> data;


    int leftside = lowestCommonAncestor(root->left , x , y);
    int rightside = lowestCommonAncestor(root->right , x, y);

    if(leftside!=-1 && rightside!=-1) return root->data;
    else if(leftside!=-1 && rightside == -1) return leftside;
    else if(leftside==-1 && rightside != -1) return rightside;
    else return -1;
}