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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int, int> mp;
        for(int i = 0; i < inorder.size(); i++) mp[inorder[i]] = i;
        return build(preorder, 0, preorder.size()-1, 0, inorder.size()-1, mp);
    }

private:
    TreeNode* build(vector<int>& pre, int pstart, int pend, int instart, int inend, unordered_map<int, int>& mp){
        if(pstart > pend || instart > inend) return nullptr;
        TreeNode* root = new TreeNode(pre[pstart]);
        int inroot = mp[pre[pstart]], pleft = inroot - instart;
        root->left = build(pre, pstart+1, pstart + pleft, instart, inroot-1, mp);
        root->right = build(pre, pstart + pleft + 1, pend, inroot+1, inend, mp);
        return root;
    }
};