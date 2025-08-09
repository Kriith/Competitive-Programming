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
    using ll = long long;
    int widthOfBinaryTree(TreeNode* root) {
        queue<pair<TreeNode*, ll>> q;
        q.push({root, 0});
        int ans = 0;
        while(!q.empty()){
            ll sz = q.size(), posn = q.front().second, l = 0, r = 0;
            for(int i = 0; i < sz; i++){
                ll curr = q.front().second - posn;
                TreeNode* t = q.front().first;
                q.pop();
                if(i == sz-1) r = curr;
                if(t->left) q.push({t->left, curr*2 + 1});
                if(t->right) q.push({t->right, curr*2 + 2});
            }
            ans = max(ans, int(r - l + 1));
        }
        return ans;
    }
};