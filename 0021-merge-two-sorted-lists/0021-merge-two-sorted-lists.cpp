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
    ListNode* merge(ListNode* headA, ListNode* headB) {
        // if (headA == NULL) {
        //     return headB;
        // }
        // if (headB == NULL) {
        //     return headA;
        // }
        ListNode* ans = new ListNode(-1);
        ListNode* temp = ans;
        while (headA != NULL && headB != NULL) {
            if (headA->val < headB->val) {
                temp->next = headA;
                temp = headA;
                headA = headA->next;
            } else {
                temp->next = headB;
                temp = headB;
                headB = headB->next;
            }
        }
        if (headA != NULL)
            temp->next = headA;
        else
            temp->next = headB;
        ans = ans->next;
        return ans;
    }
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        return merge(list1, list2);
    }
};