// https://www.interviewbit.com/problems/root-to-leaf-paths-with-sum/

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 
void pathSumUtil(TreeNode* root,int sum,vector<int> &nodes,vector<vector<int>> &ans){
    if(root==NULL){
        return;
    }
    nodes.push_back(root->val);
    if(root->left ==NULL && root->right ==NULL && sum == root->val){
        ans.push_back(nodes);
    }
    if(root->left)
        pathSumUtil(root->left,sum-root->val,nodes,ans);
    if(root->right)
        pathSumUtil(root->right,sum-root->val,nodes,ans);
    nodes.pop_back();
}
 
vector<vector<int> > Solution::pathSum(TreeNode* A, int B) {
    vector<vector<int>> ans;
    if(A==NULL)
        return ans;
    vector<int> nodes;
    pathSumUtil(A,B,nodes,ans);
    return ans;
}

