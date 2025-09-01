class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        ListNode* prev = new ListNode(0);
        ListNode* forward = new ListNode(0);
        ListNode* before = prev;
        ListNode* after = forward;
        ListNode* temp = head;

        while (temp != nullptr) {
            if (temp->val < x) {
                before->next = new ListNode(temp->val);
                before = before->next;
            } else {
                after->next = new ListNode(temp->val);
                after = after->next;
            }
            temp = temp->next;
        }

        before->next = forward->next;
        after->next = nullptr;
        ListNode* result = prev->next;
        delete prev;
        delete forward;
        return result;
    }
};
