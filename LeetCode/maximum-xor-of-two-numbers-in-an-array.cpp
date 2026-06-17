class Solution {

struct Node {
    Node* c [2];

    Node() {
        c[0] = c[1] = nullptr;
    }
};

Node* root;

public:
    void insert(int x) {
        bitset<32> b(x);
        Node* curr = root;
        //Insertion starting with MSB, needed when want to iterate starting from MSB
        for(int i = 31; i >= 0; i--) {
            if(curr->c[b[i]] == nullptr) {
                curr->c[b[i]] = new Node();
            }
            curr = curr->c[b[i]];
        }
    }

    int search(int x) {
        //Stores the XOR value
        int val = 0;
        Node* curr = root;
        //b stores bitset of ~x instead of x, as we want to maximise value of xor, thus looking for numbers that differ at most/higher bits from x
        bitset<32> b(~x);
        for(int i = 31; i >= 0; i--) {
            if(curr->c[b[i]] == nullptr) {
                curr = curr->c[!b[i]];
            }
            else {
                //If bit at ith index differs from x, then ith bit of xor value should be set
                val += (1 << i);
                curr = curr->c[b[i]];
            }
            if(curr == nullptr)
                break;
        }
        return val;
    }

    int findMaximumXOR(vector<int>& nums) {
        root = new Node();
        int n = nums.size(), ans = 0;

        for(int i = 0; i < n; i++) {
            insert(nums[i]);
        }

        for(int i = 0; i < n; i++) {
            ans = max(ans, search(nums[i]));
        }
        return ans;
    }
};

/*
Xor of two numbers will be maximum when the numbers differ at bits at posn closer to msb.
So iterate reversingly, if there exists a number where the bit at ith index differs, choose that and add 1 << i to the val as it stores the xor of the two numbers.
*/