//https://www.interviewbit.com/problems/flatten-binary-tree-to-linked-list/

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
void flatten_util(TreeNode* root){
     if(root==NULL)
        return ;
    if(root->left!=NULL){
        TreeNode* temp = root->right;
        flatten_util(root->left);
        root->right = root->left;
        root->left = NULL;
        while(root->right!=NULL)
            root = root->right;
        root->right = temp;
    }
    flatten_util(root->right);
}
 
TreeNode* Solution::flatten(TreeNode* A) {
    if(A==NULL)
        return A;
    flatten_util(A);
    return A;
}
