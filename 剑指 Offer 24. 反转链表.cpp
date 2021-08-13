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
    ListNode* reverseList(ListNode* head) {
        ListNode *prev=nullptr,*cur=head,*temp;
        while(cur){
            temp=cur;
            cur=cur->next;
            temp->next=prev;
            prev=temp;
        }
        return prev;
    }
};