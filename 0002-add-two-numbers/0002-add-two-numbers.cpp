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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* dummy = new ListNode();
        ListNode* temp = dummy;
        int carry = 0;
        while (l1 != NULL || l2 != NULL || carry) {
            int sum = 0;
            if (l1 != NULL) {
                sum += l1->val;
                l1 = l1->next;
            }
            if (l2 != NULL) {
                sum += l2->val;
                l2 = l2->next;
            }
            sum += carry;
            carry = sum / 10;
            ListNode* newnode = new ListNode(sum % 10);
            temp->next = newnode;
            temp = temp->next;
        }
        return dummy->next;
    }
};

// class Solution {
// public:
//     ListNode* add(ListNode* l1, ListNode* l2) {
//         ListNode* dummy = new ListNode(0); 
//         ListNode* curr = dummy;
//         int carry = 0;

//         while (l1 != NULL || l2 != NULL || carry != 0) {
//             int x = (l1 != NULL) ? l1->val : 0; 
//             int y = (l2 != NULL) ? l2->val : 0; 
//             int sum =x+y+carry;
//             carry=sum/10;
//             curr->next=new ListNode(sum%10);
//             curr=curr->next;
//             if(l1!=NULL) l1=l1->next;
//             if(l2!=NULL) l2=l2->next;
//         }
//         return dummy->next;
//     }
//     ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
//         ListNode* ans = add(l1, l2);
//         return ans;
//     }
// };