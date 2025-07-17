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
    ListNode *detectCycle(ListNode *head) {
        ListNode *slow = head, *fast = head;
        while(fast && fast->next){
            slow = slow->next, fast = fast->next->next;
            if(slow == fast){
                slow = head;
                while(slow != fast) slow = slow->next, fast = fast->next;
                return slow;
            }
        }
        return nullptr;
    }
};

/*
Why does the above approach lead us to the start of the cycle? We derive this from the fact that:

    The distance from the list's head to the cycle's entrance is denoted as x.
    The distance from the cycle's entrance to the first meeting point is y.
    The remaining distance from the meeting point back to the entrance is z.

Using these variables, we know that when fast and slow meet, fast has traveled x + y + n * (y + z) which is the distance to the meeting point plus n laps of the cycle.

Since fast travels at twice the speed of slow, the distance slow has traveled (x + y) is half that of fast, leading us to the equation 2(x + y) = x + y + n * (y + z). Simplifying this, we find x = (n - 1)(y + z) + z.
*/