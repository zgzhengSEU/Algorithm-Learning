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
    ListNode* getKthFromEnd(ListNode* head, int k) {
        auto fast=head,slow=head;
        while(k--)fast=fast->next;
        while(fast){
            fast=fast->next;
            slow=slow->next;
        }
        return slow;
    }
};