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
    ListNode* deleteDuplicates(ListNode* head) {
        unordered_map<int,int>count;
        ListNode* temp=head;
        while(temp!=NULL){
            count[temp->val]++;
            temp=temp->next;
        }
        ListNode* dummy = new ListNode(0);
        ListNode* curr = dummy;
        temp=head;
        while (temp != NULL) {
            if (count[temp->val] == 1) { 
                curr->next = new ListNode(temp->val);
                curr = curr->next;
            }
            temp = temp->next;
        }
        return dummy->next;
    }
};