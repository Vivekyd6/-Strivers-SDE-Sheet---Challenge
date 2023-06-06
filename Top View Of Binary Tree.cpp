#include <bits/stdc++.h> 
/************************************************************

    Following is the TreeNode class structure:

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

vector<int> getTopView(TreeNode<int> *root) {
    // Write your code here.
    if(root==NULL)return {};
    vector<int> ans;
    queue<pair<TreeNode<int>*,int>> q;
    map<int,int> m;
    q.push({root,0});
    while(!q.empty()){
        auto it=q.front();
        q.pop();
        auto temp=it.first;
        int distance=it.second;
        if(m.find(distance)== m.end()) m[distance] = temp->val;
        if(temp->left){
            q.push({temp->left,distance-1});
        }
        if(temp->right){
            q.push({temp->right,distance+1});
        }
    }
    for(auto it:m) ans.push_back(it.second);
    return ans;
}