/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ans;
        stack<TreeNode*> s;
        if(root == NULL)
        return ans;
        s.push(root);
        while(!s.empty()){
            TreeNode* top=s.top();
            s.pop();
            ans.push_back(top->val);
            if(top->right != NULL){
                s.push(top->right);
            }
            if(top->left != NULL){
                s.push(top->left);
            } 
        }
        return ans;
    }
};
