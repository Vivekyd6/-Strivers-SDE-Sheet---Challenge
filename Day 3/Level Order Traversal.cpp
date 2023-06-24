#include <bits/stdc++.h> 
/************************************************************

    Following is the BinaryTreeNode class structure

    template <typename T>
    class BinaryTreeNode {
       public:
        T val;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T val) {
            this->val = val;
            left = NULL;
            right = NULL;
        }
    };

************************************************************/
vector<int> getLevelOrder(BinaryTreeNode<int> *root)
{
    //  Write your code here.
    if(!root) return {};
    queue<BinaryTreeNode<int>* >q;
    q.push(root);
    vector<int>res;
    while(!q.empty()){
        auto tmp = q.front();
        res.push_back(tmp->val);
        q.pop();
        if(tmp->left) q.push(tmp->left);
        if(tmp->right) q.push(tmp->right);
    }
    return res;
}