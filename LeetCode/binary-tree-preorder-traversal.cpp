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
        if(!root) return {};
        vector<int> ans;
        ans.push_back(root->val);
        if(!(root->left || root->right)) return ans;
        if(root->left){
            vector<int> l = preorderTraversal(root->left);
            ans.insert(ans.end(), l.begin(), l.end());
        }
        if(root->right){
            vector<int> l = preorderTraversal(root->right);
            ans.insert(ans.end(), l.begin(), l.end());
        }
        return ans;
    }
};
//recursive

