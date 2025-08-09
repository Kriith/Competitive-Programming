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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int nA = 1, nB = 1;
        ListNode* tA = headA, *tB = headB;
        while(tA->next) tA = tA->next, nA++;
        while(tB->next) tB = tB->next, nB++;
        if(tA != tB) return nullptr;
        tA = headA, tB = headB;
        while(nA > nB) tA = tA->next, nA--;
        while(nA < nB) tB = tB->next, nB--;
        while(tA != tB) tA = tA->next, tB = tB->next;
        return tA;
    }
};