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
    ListNode* sortList(ListNode* head) {
        if(!head || !head->next) return head;
        ListNode *mid = findmid(head), *right = mid->next;
        mid->next = nullptr;
        head = sortList(head); right = sortList(right);
        return mergenodes(head, right);
    }
private:
    ListNode* findmid(ListNode* head){
        ListNode* slow = head, *fast = head->next;
        while(fast && fast->next) slow = slow->next, fast = fast->next->next;
        return slow;
    }

    ListNode* mergenodes(ListNode* l, ListNode* r){
        ListNode* temp = new ListNode(), *tail = temp;
        while(l && r){
            if(l->val < r->val) tail->next = l, l = l->next;
            else tail->next = r, r = r->next;
            tail = tail->next;
        }
        while(l) tail->next = l, l = l->next, tail = tail->next;
        while(r) tail->next = r, r = r->next, tail = tail->next;
        return temp->next;
    }
};