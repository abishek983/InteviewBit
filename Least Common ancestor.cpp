// https://www.interviewbit.com/problems/least-common-ancestor/

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

 TreeNode* lcaHelper(TreeNode* root,int x,int y,int &count){
    if(root==NULL)
        return NULL;
    TreeNode* left = lcaHelper(root->left,x,y,count);
    TreeNode* right = lcaHelper(root->right,x,y,count);
    if(root->val == x || root->val == y){
        count++;
        return root;
    }
    if(left && right)
        return root;
    if(left==NULL)
        return right;
    if(right==NULL)
        return left;
 }
 
int Solution::lca(TreeNode* A, int B, int C) {  
    int count = 0;
    TreeNode* ans = lcaHelper(A,B,C,count);
    //cout << count << endl;
    if(ans==NULL)
        return -1;
    if(B==C)
        return ans->val;
    if(count==2)
        return ans->val;
    
    return -1;
}
