class Trie {

struct Node {
    Node* children [26];
    bool isWord;

    Node() {
        for(int i = 0; i < 26; i++) {
            children[i] = nullptr;
        }
        isWord = false;
    }
};

Node* root;

public:
    Trie() {
        root = new Node();        
    }
    
    void insert(string word) {
        int n = word.length();
        Node* curr = root;
        for(int i = 0; i < n; i++) {
            int index = word[i] - 'a';
            if(curr == nullptr || curr->children[index] == nullptr) {
                curr->children[index] = new Node();
            }
            curr = curr->children[index];
        }
        curr->isWord = true;
    }
    
    bool search(string word, bool prefix = false) {
        int n = word.length();
        Node* curr = root;
        for(int i = 0; i < n; i++) {
            int index = word[i] - 'a';
            if(curr->children[index] == nullptr) {
                return false;
            }
            curr = curr->children[index];
        }
        return (prefix || curr->isWord);
    }
    
    bool startsWith(string prefix) {
        return search(prefix, true);
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */