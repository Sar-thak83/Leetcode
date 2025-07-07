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

// -----------------------Approach-1----------------------------

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* curr = head ;
        if (head == NULL) { return head; }
        while (curr != NULL) {
            if ((curr->next != NULL) && curr->val == curr->next->val) {
                ListNode* nodeTodelete=curr->next;
                // curr->next->val=curr->val;
                curr->next=curr->next->next;
                delete nodeTodelete;
            } else {
                curr=curr->next;
            }
        }
        return head;
    }
};