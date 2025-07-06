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
    ListNode* reverseLinklist(ListNode*& head) {
        ListNode* prev = NULL;
        ListNode* forward = NULL;
        ListNode* curr = head;
        while (curr != NULL) {
            forward = curr->next;
            curr->next = prev;
            prev = curr;
            curr = forward;
        }
        return prev;
    }
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        head = reverseLinklist(head);
        ListNode* temp = head;
        if (n == 1) {
            ListNode* newNode = head->next;
            delete head;
            return reverseLinklist(newNode);
        }
        for (int i = 1; i < n - 1 && temp != NULL; i++) {
            temp = temp->next;
        }
        if (temp != NULL && temp->next != NULL) {
            ListNode* nodeToDelete = temp->next;
            temp->next = temp->next->next;
            delete nodeToDelete;
        }
        return reverseLinklist(head);
    }
};