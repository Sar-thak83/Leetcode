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
    ListNode* swapNodes(ListNode* head, int k) {
        vector<int>arr;
        ListNode* temp=head;
        while(temp!=NULL){
            int value=temp->val;
            arr.push_back(value);
            temp=temp->next;
        }
        int len= arr.size();
        swap(arr[k-1],arr[len-k]);
        ListNode* curr=head;
        for(int i=0;i<len;i++){
            curr->val=arr[i];
            curr=curr->next;
        }
        return head;
    }
};