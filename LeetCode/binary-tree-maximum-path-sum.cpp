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
    int maxPathSum(TreeNode* root) {
        if(!root) return 0;
        int ans = INT_MIN;
        value(root, ans);
        return ans;
    }

private:
    int value(TreeNode* root, int& ans){
        if(!root) return 0;
        int l = max(0, value(root->left, ans)), r = max(0, value(root->right, ans));
        ans = max(ans, root->val + l + r);
        return max(l, r) + root->val;
    }
};