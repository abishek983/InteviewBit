//https://www.interviewbit.com/problems/zigzag-level-order-traversal-bt/

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
vector<vector<int> > Solution::zigzagLevelOrder(TreeNode* A) {
    stack<TreeNode*> l ;
    stack<TreeNode*> r;
    int turn = 0; // turn of the stack
    vector<vector<int>> ans;
    if(A==NULL)
        return ans;
    l.push(A);
    while(!l.empty() || !r.empty()){
        vector<int> temp;
        if(turn){
            while(!r.empty()){
                TreeNode* curr = r.top(); r.pop();
                if(curr->right)
                    l.push(curr->right);
                if(curr->left)
                    l.push(curr->left);
                temp.push_back(curr->val);
            }
        }
        else{
            while(!l.empty()){
                TreeNode* curr = l.top(); l.pop();
                if(curr->left)
                    r.push(curr->left);
                if(curr->right)
                    r.push(curr->right);
                temp.push_back(curr->val);
            }
        }
        turn = abs(turn-1);
        ans.push_back(temp);
    }
    return ans;
}
