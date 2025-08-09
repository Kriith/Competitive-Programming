/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(!head) return head;
        Node* t = head;
        while(t){
            Node* tt = new Node(t->val);
            tt->next = t->next;
            t->next = tt;
            t = tt->next;
        }
        t = head;
        while(t){
            if(t->random) t->next->random = t->random->next;
            t = t->next->next;
        }
        t = head;
        Node* ans = head->next;
        while(t){
            Node *tt = t->next;
            t->next = tt->next;
            if(tt->next) tt->next = tt->next->next;
            t = t->next, tt = tt->next;
        }
        return ans;
    }
};
//optimal soln
//basically making copy nodes that initially are between original nodes
//i.e 1->2->3 will have copy nodes 1->1*->2->2*->3->3*->null

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(head == nullptr) return head;
        Node *head1 = new Node(head->val), *curr = head, *curr1 = head1;
        unordered_map<Node*, Node*> mp;
        mp[head] = head1;
        curr = curr->next;
        while(curr){
            Node *t = new Node(curr->val);
            mp[curr] = t;
            curr1->next = t;
            curr1 = t;
            curr = curr->next;
        }
        curr = head, curr1 = head1;
        while(curr){
            curr1->random = mp[curr->random];
            curr = curr->next, curr1 = curr1->next;
        }
        return head1;
    }
};
//hashing soln not optimal