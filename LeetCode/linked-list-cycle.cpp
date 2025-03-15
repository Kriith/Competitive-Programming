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
        bool hasCycle(ListNode *head) {
            ListNode* t = head;
            set<ListNode*> s;
            while(t != nullptr){
                if(s.find(t) != s.end()) return true;
                else s.insert(t);
                t = t->next;
            }
            return false;
        }
    };