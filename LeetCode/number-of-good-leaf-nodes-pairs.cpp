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
    int countPairs(TreeNode* root, int distance) {
        return postOrder(root, distance)[distance + 1];
    }

    vector<int> postOrder(TreeNode* curr, int dist) {
        vector<int> paths(dist + 2, 0);

        if(!curr) return paths;
        paths[0] = 1;

        if(!(curr->left || curr->right)) return paths;

        paths[0] = 0;
        vector<int> l(dist + 2), r(dist + 2);
        l = postOrder(curr->left, dist);
        r = postOrder(curr->right, dist);

        for(int i = 0; i < dist; i++) {
            paths[i + 1] = l[i] + r[i]; //dist increases by one for child nodes
        }

        paths[dist + 1] += l[dist + 1] + r[dist + 1];
        for(int i = 0; i <= dist; i++) {
            for(int j = 0; j <= dist; j++) {
                if(2 + i + j <= dist) {
                    paths[dist + 1] += l[i] * r[j];
                }
            }
        }
        return paths;
    }
};