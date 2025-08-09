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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        map<int, int> mp;
        for(int i = 0; i < inorder.size(); i++) mp[inorder[i]] = i;
        return build(postorder, 0, postorder.size()-1, 0, inorder.size()-1, mp);
    }

private:
    TreeNode* build(vector<int>& post, int postl, int postr, int inl, int inr, map<int, int>& mp){
        if(postl > postr || inl > inr) return nullptr;
        TreeNode* t = new TreeNode(post[postr]);
        int inroot = mp[post[postr]], l = inroot - inl;
        t->left = build(post, postl, postl + l - 1, inl, inroot - 1, mp);
        t->right = build(post, postl + l, postr - 1, inroot + 1, inr, mp);
        return t;
    }
};