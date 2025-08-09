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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        if(!root) return ans;
        if(root->left) ans = inorderTraversal(root->left);
        ans.push_back(root->val);
        vector<int> right;
        if(root->right) right = inorderTraversal(root->right);
        for(auto i: right) ans.push_back(i);
        return ans;
    }
};

//iterative, morris optimal O(1) mc
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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        if(!root) return ans;
        while(root){
            if(!root->left){
                ans.push_back(root->val);
                root = root->right;
            }
            else{
                TreeNode* nx = root->left;
                while(nx->right && nx->right != root) nx = nx->right;
                if(!nx->right){
                    nx->right = root;
                    root = root->left;
                }
                else{
                    nx->right = nullptr;
                    ans.push_back(root->val);
                    root = root->right;
                }
            }
        }
        return ans;
    }
};