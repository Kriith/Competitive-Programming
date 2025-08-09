/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode*, TreeNode*> p;
        p[root] = nullptr;
        parents(root, p);
        vector<int> ans;
        unordered_map<TreeNode*, bool> vis;
        dfs(target, ans, p, vis, k);
        return ans;
    }

private:
    void parents(TreeNode* t, unordered_map<TreeNode*, TreeNode*>& p){
        if(!t) return;
        if(t->left){
            p[t->left] = t;
            parents(t->left, p);
        }
        if(t->right){
            p[t->right] = t;
            parents(t->right, p);
        }
    }

    void dfs(TreeNode* t, vector<int>& ans, unordered_map<TreeNode*, TreeNode*>& p, unordered_map<TreeNode*, bool>& vis, int k){
        if(!t || vis[t]) return;
        vis[t] = 1;
        if(k == 0) ans.push_back(t->val);
        else{
            dfs(t->left, ans, p, vis, k - 1);
            dfs(t->right, ans, p, vis, k - 1);
            dfs(p[t], ans, p, vis, k - 1);
        }
    }
};