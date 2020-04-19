// https://www.interviewbit.com/problems/preorder-traversal/

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
vector<int> Solution::preorderTraversal(TreeNode* A) {
    vector<int> ans;
    stack<TreeNode*> st;
    TreeNode* curr = A;
    while(!st.empty() || curr){
        while(curr){
            ans.push_back(curr->val);
            st.push(curr);
            curr = curr->left;
        }
        TreeNode* temp = st.top();
        st.pop();
        curr = temp->right;
    }
    return ans;
}
