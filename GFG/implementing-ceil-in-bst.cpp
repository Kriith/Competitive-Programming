// Function to return the ceil of given number in BST.
int findCeil(Node* root, int input) {
    if (root == NULL)
        return -1;

    // Your code here
    int ceil = INT_MAX;
    Node *curr = root;
    while(curr != NULL){
        if(curr->data == input) return input;
        else if(curr->data > input){
            ceil = min(ceil, curr->data);
            curr = curr->left;
        }
        else curr = curr->right;
    }
    if(ceil == INT_MAX) return -1;
    return ceil;
}