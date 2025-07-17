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
    ListNode* oddEvenList(ListNode* head) {
        ListNode *oh, *ot, *eh, *et, *curr = head;
        ot = oh = new ListNode(), et = eh = new ListNode();
        bool flg = 1;
        while(curr){
            ListNode* t = new ListNode(curr->val);
            if(flg) ot->next = t, ot = t;
            else et->next = t, et = t;
            curr = curr->next, flg = !flg;
        }
        ot->next = eh->next;
        return oh->next;
    }
};