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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int N = 0;
        for(ListNode* i = head; i; i = i->next) N++;
        N -= n;
        ListNode *curr = head, *prev = nullptr;
        while(N--) prev = curr, curr = curr->next;
        if(!curr) return NULL;
        if(!prev) return head->next;
        prev->next = curr->next;
        return head;
    }
};
//two pass

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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* slow = head, *fast = head, *prev = nullptr;
        while(n--) fast = fast->next;
        while(fast) fast = fast->next, prev = slow, slow = slow->next;
        if(!prev) return head->next;
        prev->next = slow->next;
        return head;
    }
};
//one pass