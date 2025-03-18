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
    
        struct cmp{
            bool operator()(ListNode* n1, ListNode* n2){
                return n1->val > n2->val;
            }
        };
    
        ListNode* mergeKLists(vector<ListNode*>& lists) {
            int n = lists.size();
            priority_queue<ListNode*, vector<ListNode*>, cmp> pq;
            for(int i = 0; i < n; i++){
                ListNode* t = lists[i];
                while(t != nullptr){
                    pq.push(t);
                    t = t->next;
                }
            }
            ListNode* head = new ListNode(-10001, nullptr);
            ListNode* curr = head;
            while(!pq.empty()){
                curr->next = pq.top();
                pq.pop();
                curr = curr->next;
            }
            curr->next = nullptr;
            return head->next;
        }
    };