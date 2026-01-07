/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    long M = 1e9+7;
    long totalSum = 0, maxP = 0;
    
    int FindSum(TreeNode* root){
        if (root==NULL){
            return 0;
        }
        int sum=0;
        sum=root->val+FindSum(root->left)+FindSum(root->right);
        maxP = max(maxP, (totalSum - sum) * sum);
        return sum;
    }

    int maxProduct(TreeNode* root) {
        if(root==NULL){
            return 0;
        }

        totalSum=FindSum(root);
        FindSum(root);
        
        return maxP%M;

        
    }
};