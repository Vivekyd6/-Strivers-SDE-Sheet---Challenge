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
int solve(TreeNode<int> *root,int& maxi){

    if(root==NULL)return 0;
    int left=solve(root->left,maxi);
    int right=solve(root->right,maxi);
    maxi=max(maxi,left+right);

   return max(left,right)+1;
}

int diameterOfBinaryTree(TreeNode<int> *root)
{
	// Write Your Code Here.
    if(!root) return 0;
    int maxi = 0;
    solve(root , maxi);
    return maxi;
}
