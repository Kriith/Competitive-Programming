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
        if(!root) return ans;
        stack<TreeNode*> s;
        s.push(root);
        while(!s.empty()){
            TreeNode* t = s.top();
            s.pop();
            ans.push_back(t->val);
            if(t->right) s.push(t->right);
            if(t->left) s.push(t->left);
        }
        return ans;
    }
};
//iterative using stack O(N) mc

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
        if(!root) return ans;
        while(root){
            ans.push_back(root->val);
            if(!root->left) root = root->right;
            else{
                TreeNode* nx = root->left;
                while(nx->right) nx = nx->right;
                nx->right = root->right;
                root->right = nullptr;
                root = root->left;
            }
        }
        return ans;
    }
};
//morris, o(1)