
// class Solution {
//     ListNode* getkNode(ListNode*& temp, int k) {
//         k -= 1;
//         while (temp != NULL && k > 0) {
//             k--;
//             temp = temp->next;
//         }
//         return temp;
//     }

// public:
//     ListNode* reverse_Linklist(ListNode*& head) {
//         ListNode* forward = NULL;
//         ListNode* curr = head;
//         ListNode* prev = NULL;
//         while (curr != NULL) {
//             forward = curr->next;
//             curr->next = prev;
//             prev = curr;
//             curr = forward;
//         }
//         return prev;
//     }
//     ListNode* reverseKGroup(ListNode* head, int k) {
//         if (head == NULL) {
//             return NULL;
//         }
//         ListNode* temp = head;
//         ListNode* prev = NULL;
//         ListNode* forward = NULL;
//         while (temp != NULL) {
//             ListNode* kthNode = getkNode(temp, k);
//             if (kthNode == NULL) {
//                 if (prev) {
//                     prev->next = temp;
//                 }
//                 break;
//             }
//             forward = kthNode->next;
//             kthNode->next = NULL;
//             reverse_Linklist(temp);
//             if (temp == head) {
//                 head = kthNode;
//             } else {
//                 prev->next = kthNode;
//             }
//             prev = temp;
//             temp = forward;
//         }

//         return head;
//     }
// };

// Move to the next group

// Return the head of the
// modified linked list

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
    ListNode* reverseKGroup(ListNode* head, int k) {
        // Base case: if head is NULL, return NULL
        if(head == NULL) {
            return NULL;
        }

        // Check if there are at least k nodes to reverse
        ListNode* check = head;
        for (int i = 0; i < k; ++i) {
            if (!check) return head; 
            check = check->next;
        }

        // Reverse the k-group
        ListNode* next = NULL;
        ListNode* curr = head;
        ListNode* prev = NULL;
        int cnt = 0;

        while(curr != NULL && cnt < k) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
            cnt++;
        }

        // Recursively reverse the next groups and attach them
        if(next != NULL) {
            head->next = reverseKGroup(next, k);
        }

        // Return the new head of the reversed list
        return prev;
    }
};