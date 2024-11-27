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
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
// class Solution {
// public:
//     TreeNode* helper(vector<int>& nums, int low, int high) {
//         if (low > high)
//             return NULL;
//         int mid = (low + high) / 2;
//         TreeNode* root = new TreeNode(nums[mid]);
//         root->left = helper(nums, low, mid - 1);
//         root->right = helper(nums, mid + 1, high);
//         return root;
//     }
//     TreeNode* sortedListToBST(ListNode* head) {
//         vector<int> nums;
//         int i = 0;
//         while (head != NULL) {
//             nums.push_back(head->val);
//             head = head->next;
//             i++;
//         }
//         return helper(nums, 0, nums.size() - 1);
//     }
// };


class Solution {
public:
    vector<TreeNode*> treeVec;   // val to TreeNode

    TreeNode* helper(int left, int right) {
        if (left > right)
            return nullptr;

        int mid = (left + right) / 2;
        TreeNode* curr = treeVec[mid];

        if (left == right)
            return curr;

        curr->left = helper(left, mid-1);
        curr->right = helper(mid+1, right);

        return curr;
    }
    
    TreeNode* sortedListToBST(ListNode* head) {
        if (!head)
            return nullptr;
        ListNode* curr = head;
        while (curr) {
            TreeNode* newNode = new TreeNode(curr->val);
            treeVec.push_back(newNode);
            curr = curr->next;
        }
        return helper(0,treeVec.size()-1);
    }
};