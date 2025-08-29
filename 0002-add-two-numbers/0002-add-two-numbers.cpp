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
        ListNode* temp=new ListNode(0);
        ListNode* Curr=temp;
        int carry=0;
        while(l1!=NULL || l2!=NULL ||carry){
            int sum =0;
            if(l1!=NULL){
                sum=sum+l1->val;
                l1=l1->next;
            }
            if(l2!=NULL){
                sum=sum+l2->val;
                l2=l2->next;
            }
            sum=sum+carry;
            carry=sum/10;
            ListNode *newNode= new ListNode(sum%10);
            Curr->next=newNode;
            Curr=Curr->next;
        }
        return temp->next;
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