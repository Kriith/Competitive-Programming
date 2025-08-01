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
    ListNode* deleteMiddle(ListNode* head) {
        ListNode* slow = head, *fast = head, *prev = nullptr;
        while(fast && fast->next) prev = slow, slow = slow->next, fast = fast->next->next;
        if(!prev) return head->next;
        prev->next = slow->next;
        return head;
    }
};