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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(!root) return ans;
        queue<pair<TreeNode*, int>> q;
        q.push({root, 0});
        vector<int> curr;
        int curlevel = 0;
        while(!q.empty()){
            auto t = q.front();
            q.pop();
            if(t.second > curlevel){
                ans.push_back(curr);
                curr.clear();
                curlevel++;
            }
            curr.push_back(t.first->val);
            if(t.first->left) q.push({t.first->left, t.second + 1});
            if(t.first->right) q.push({t.first->right, t.second + 1});
        }
        if(!curr.empty()) ans.push_back(curr);
        return ans;
    }
};