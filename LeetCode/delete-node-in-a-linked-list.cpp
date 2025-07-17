/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    void deleteNode(ListNode* node) {
        ListNode* curr = node;
        while(curr->next != NULL){
            curr->val = curr->next->val;
            if(curr->next->next == NULL) curr->next = NULL;
            else curr = curr->next;
        }
    }
};
//this is o(n) soln

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    void deleteNode(ListNode* node) {
        ListNode* nx = node->next;
        node->val = nx->val;
        node->next = nx->next;
    }
};
//this is o(1)