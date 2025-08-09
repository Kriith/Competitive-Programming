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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        unordered_map<int, vector<pair<int, int>>> mp;
        int mn = 0, mx = 0;
        dfs(root, mp, mn, mx, 0, 0);
        vector<vector<int>> ans(mx - mn + 1);
        for(int i = mn; i <= mx; i++){
            sort(mp[i].begin(), mp[i].end());
            for(auto j: mp[i]) ans[i - mn].push_back(j.second);
        }
        return ans;
    }

private:
    void dfs(TreeNode* root, unordered_map<int, vector<pair<int, int>>>& mp, int& mn, int& mx, int dist, int level){
        if(!root) return;
        mp[dist].push_back({level, root->val});
        mn = min(dist, mn), mx = max(dist, mx);
        dfs(root->left, mp, mn, mx, dist - 1, level+1);
        dfs(root->right, mp, mn, mx, dist + 1, level+1);
    }
};
//dfs approach, needed to make map<int, vector<pair<int, int>> to sort by value when same row and same column
//can also be done with bfs, similar approach