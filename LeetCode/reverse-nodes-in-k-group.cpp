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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* ans = nullptr, *prev = nullptr, *curh = head, *curt = head, *prevt = nullptr;
        for(int i = 1; i < k && curt; i++) curt = curt->next;
        while(curt && curh){
            ListNode* curr = curh;
            int kk = k;
            while(curr && kk--){
                ListNode* t = curr->next;
                curr->next = prev;
                prev = curr;
                curr = t;
            }
            assert(prev == curt);
            if(!ans) ans = curt;
            else prevt->next = curt;
            prevt = curh, curh = curt = curr, prev = nullptr;
            for(int i = 1; i < k && curt; i++) curt = curt->next;
        }
        prevt->next = curh;
        return ans;
    }
};

//better soln done in lab:(
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
    ListNode* reverseKGroup(ListNode* head, int k) {
        int length = 0;
        ListNode *t = head;
        while(t != nullptr){ length++; t = t->next; }
        if(length < k) return head;
        t = head;
        int kk = k;
        while(kk--) t = t->next;
        ListNode *tt = new ListNode(head->val);
        tt->next = reverseKGroup(t, k);
        t = head->next;
        kk = k - 1;
        while(kk--){
            ListNode *ttt = new ListNode(t->val);
            ttt->next = tt;
            tt = ttt;
            t = t->next;
        }
        return tt;
    }
};