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
        TreeNode* insertIntoBST(TreeNode* root, int val) {
            TreeNode* curr = root, *ans = new TreeNode(val);
            if(curr == nullptr){ root = ans; return root; }
            while(curr->right != nullptr || curr->left != nullptr){
                if(val > curr->val){
                    if(curr->right != nullptr) curr = curr->right;
                    else{
                        curr->right = ans;
                        return root;
                    }
                }
                else {
                    if(curr->left != nullptr) curr = curr->left;
                    else{
                        curr->left = ans;
                        return root;
                    }
                }
            }
            if(val > curr->val) curr->right = ans;
            else curr->left = ans;
            return root;
        }
    };