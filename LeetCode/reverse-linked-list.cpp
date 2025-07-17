/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
    public:
        ListNode* reverseList(ListNode* head) {
            ListNode* curr = head, *nxt, *prv = nullptr;
            while(curr != nullptr){
                nxt = curr->next;
                curr->next = prv;
                prv = curr;
                curr = nxt;
            }
            return prv;
        }
    };

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if(!head || !head->next) return head;
        ListNode* nx = reverseList(head->next);
        head->next->next = head;
        head->next = NULL;
        return nx;
    }
};
//recursive
//make each subproblem with head pointing to null