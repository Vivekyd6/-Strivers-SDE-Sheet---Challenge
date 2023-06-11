/*****************************************************

    Following is the Binary Tree node structure:
    
    class BinaryTreeNode {
        public : 
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }
        
        ~BinaryTreeNode() {
            if(left) 
                delete left;
            if(right) 
                delete right;
        }
    };

******************************************************/

bool solve(BinaryTreeNode<int>* root1 , BinaryTreeNode<int>* root2){
   if(root1==NULL || root2==NULL)
        return root1==root2;
   return (root1->data == root2->data) && solve(root1->left,root2->right) & solve(root1->right,root2->left);
}

bool isSymmetric(BinaryTreeNode<int>* root)
{
    if(!root)   return -1;
    return solve(root->left , root->right); 
}