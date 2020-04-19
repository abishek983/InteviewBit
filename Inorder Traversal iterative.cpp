//interviewbit.com/problems/inorder-traversal/

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
vector<int> Solution::inorderTraversal(TreeNode* A) {
    vector<int> ans;
    stack<TreeNode*> st;
    TreeNode* curr = A;
    while(curr!=NULL || !st.empty()){
        while(curr){
            st.push(curr);
            curr = curr->left;
        }
        TreeNode* temp = st.top();
        st.pop();
        ans.push_back(temp->val);
        curr = temp->right;
    }
    return ans;
}
