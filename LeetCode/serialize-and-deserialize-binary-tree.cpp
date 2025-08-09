/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(!root) return "";
        queue<TreeNode*> q;
        q.push(root);
        string s;
        while(!q.empty()){
            TreeNode* t = q.front();
            q.pop();
            if(!t) s += ("#,");
            else{
                s += to_string(t->val) + ',';
                q.push(t->left); q.push(t->right);
            }
        }
        return s;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data.empty()) return nullptr;
        stringstream str(data);
        string s;
        getline(str, s, ',');
        TreeNode* root = new TreeNode(stoi(s));
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            TreeNode* t = q.front(); q.pop();
            getline(str, s, ',');
            if(s != "#"){
                TreeNode* l = new TreeNode(stoi(s));
                t->left = l;
                q.push(l);
            }
            getline(str, s, ',');
            if(s != "#"){
                TreeNode* r = new TreeNode(stoi(s));
                t->right = r;
                q.push(r);
            }
        }
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));