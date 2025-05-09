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
        TreeNode* deleteNode(TreeNode* root, int key) {
            TreeNode *curr = root, *parent = NULL;
            bool l = 0;
            while(curr){
                if(curr->val == key) break;
                else if(curr->val > key) parent = curr, curr = curr->left, l = 1;
                else parent = curr, curr = curr->right, l = 0;
            }
            if(!curr) return root;
            //zero child
            if(!(curr->right) && !(curr->left)){
                if(!parent) return NULL;
                else{
                    if(l) parent->left = NULL;
                    else parent->right = NULL;
                }
            }
            //only left child
            else if(!(curr->right)){
                if(!parent) return curr->left;
                else{
                    if(l) parent->left = curr->left;
                    else parent->right = curr->left;
                }
            }
            //only right child
            else if(!(curr->left)){
                if(!parent) return curr->right;
                else{
                    if(l) parent->left = curr->right;
                    else parent->right = curr->right;
                }
            }
            //two children
            else{
                TreeNode *child = curr->right, *parent2 = NULL;
                while(child->left) parent2 = child, child = child->left;
                child->left = curr->left;
                if(parent2) parent2->left = child->right, child->right = curr->right;
                if(!parent) return child;
                else{
                    if(l) parent->left = child;
                    else parent->right = child;
                }
            }
            return root;
        }
    };