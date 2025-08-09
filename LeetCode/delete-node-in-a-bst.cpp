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
        TreeNode* node = root, *parent = nullptr;
        while(node && node->val != key){
            parent = node;
            if(node->val > key) node = node->left;
            else if(node->val < key) node = node->right;
        }
        if(!node) return root;
        if(!node->left && !node->right){
            if(!parent) return parent;
            if(parent->left == node) parent->left = nullptr;
            else parent->right = nullptr;
        }
        else if(!node->right){
            if(!parent) return root->left;
            if(parent->left == node) parent->left = node->left;
            else parent->right = node->left;
        }
        else if(!node->left){
            if(!parent) return root->right;
            if(parent->left == node) parent->left = node->right;
            else parent->right = node->right;
        }
        else{
            TreeNode* t = node->right, *pt = node;
            while(t->left){ pt = t, t = t->left; }
            if(pt == node) pt->right = t->right;
            else pt->left = t->right;
            node->val = t->val;
        }
        return root;
    }
};
//iterative

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
        TreeNode* node = root, *parent = nullptr;
        while(node && node->val != key){
            parent = node;
            if(node->val > key) node = node->left;
            else if(node->val < key) node = node->right;
        }
        if(!node) return root;
        if(!node->left && !node->right){
            if(!parent) return parent;
            if(parent->left == node) parent->left = nullptr;
            else parent->right = nullptr;
        }
        else if(!node->right){
            if(!parent) return root->left;
            if(parent->left == node) parent->left = node->left;
            else parent->right = node->left;
        }
        else if(!node->left){
            if(!parent) return root->right;
            if(parent->left == node) parent->left = node->right;
            else parent->right = node->right;
        }
        else{
            TreeNode* t = node->right;
            while(t->left) t = t->left;
            int value = t->val;
            node = deleteNode(node, value);
            node->val = value;
        }
        return root;
    }
};
//recursive