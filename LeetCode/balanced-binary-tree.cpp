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
    bool isBalanced(TreeNode* root) {
        return height(root) >= 0;
    }

private:
    int height(TreeNode* root){
        if(!root) return 0;
        int l = height(root->left), r = height(root->right);
        if(l < 0 || r < 0 || abs(l - r) > 1) return -1;
        return max(l, r) + 1;
    }
};