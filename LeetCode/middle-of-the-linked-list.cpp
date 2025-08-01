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
        ListNode* middleNode(ListNode* head) {
            int length = 1;
            ListNode* nxt = head->next;
            while(nxt != nullptr){
                length++;
                nxt = nxt->next;
            }
            int cnt = length/2;
            nxt = head;
            while(cnt--) nxt = nxt->next;
            return nxt;
        }
    };
//brute force

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
    ListNode* middleNode(ListNode* head) {
        ListNode* slow = head, *fast = head;
        while(fast && fast->next) slow = slow->next, fast = fast->next->next;
        return slow;
    }
};
//tortoise hare method