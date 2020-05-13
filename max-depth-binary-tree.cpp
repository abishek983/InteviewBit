/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 //https://www.interviewbit.com/problems/max-depth-of-binary-tree/
 
 int maxDepthUtil(TreeNode* root){
    if(root==NULL)
        return 0;
    int left = maxDepthUtil(root->left) + 1;
    int right = maxDepthUtil(root->right) + 1;
    return max(left,right);
 }
 
int Solution::maxDepth(TreeNode* A) {
    int ans = maxDepthUtil(A);
    return ans;
}
