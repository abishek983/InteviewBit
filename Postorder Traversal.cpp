// The solution that gets accepted in the interviewbit platform is actually using an extra N space alogrithm
// Here we find the reverse of the post order and reverse the array before printing.


vector<int> Solution::postorderTraversal(TreeNode* A) {
    stack<TreeNode*> st;
    vector<int> ans;
    TreeNode* curr = A;
    while(curr || !st.empty()){
        while(curr){
            ans.push_back(curr->val);
            st.push(curr);
            curr = curr->right;
        }
        TreeNode* temp = st.top(); st.pop();
        curr = temp->left;
    }
    
    reverse(ans.begin(),ans.end());
    /*while(curr && !st.empty()){
        if(curr){
            if(curr->right)
                st.push(curr->right);
            st.push(curr);
            curr = curr->left;
        }
        else{
            TreeNode* temp = st.top();
            st.pop();
            if(temp->right == st.top()){
                st.pop();
                st.push(temp);
                curr = temp->right;
            }
            else{
                ans.push_back(temp->val);
            }
        }
    }*/
    return ans;
}
