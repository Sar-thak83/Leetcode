class Solution {
public:
    ListNode* reverse(ListNode* head) {
        ListNode* prev = NULL;
        ListNode* curr = head;
        ListNode* forward = NULL;

        while (curr != NULL) {
            forward = curr->next;
            curr->next = prev;
            prev = curr;
            curr = forward;
        }
        return prev;
    }

    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if (!head) return nullptr;

        head = reverse(head);

        ListNode* dummy = new ListNode(0, head);
        ListNode* prev = dummy;
        ListNode* curr = head;
        int count = 1;

        while (curr && count < n) {
            prev = curr;
            curr = curr->next;
            count++;
        }

        if (curr) {
            prev->next = curr->next;
            delete curr;
        }

        head = reverse(dummy->next);
        delete dummy;
        return head;
    }
};
