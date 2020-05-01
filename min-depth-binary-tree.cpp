//https://www.interviewbit.com/problems/min-depth-of-binary-tree/
/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
int Solution::minDepth(TreeNode* A) {
    if(A==NULL)
        return 0;
    
    int left = minDepth(A->left);
    int right = minDepth(A->right);
    
    if(left!=0&&right!=0)
        return min(left,right)+1;
    
    if(left==0)
        return right+1;
    
    if(right==0)
        return left+1;
    
}
