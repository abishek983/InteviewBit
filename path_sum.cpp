//https://www.interviewbit.com/problems/path-sum/

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
int hasPathSumUtil(TreeNode* root,int sum,int l_sum){
        if(root==NULL)
            return 0;
        if(sum==l_sum){
            if(root->left == NULL && root->right==NULL)
                return 1;
        }
    
        int left = 0 , right = 0;
        if(root->left)
            left = hasPathSumUtil(root->left,sum,l_sum+root->left->val);
        if(root->right)
            right = hasPathSumUtil(root->right,sum,l_sum+root->right->val);
    
        return (left|right);
} 
 
 
int Solution::hasPathSum(TreeNode* A, int B) {
    if(A==NULL){
        return 0;
    }
    int ans = hasPathSumUtil(A,B,A->val);
    return ans;
}
