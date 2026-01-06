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
class Solution {
public:
    int maxLevelSum(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        int ans=1;
        int maxsum=INT_MIN;
        int level=0;
        while (!q.empty()) {
            level++;
            int sum=0;
            int size = q.size();
            for (int i = 0; i < size; i++) {
                TreeNode* temp = q.front();
                if (temp->left != NULL)
                    q.push(temp->left);
                if (temp->right != NULL)
                q.push(temp->right);
                sum=sum+temp->val;
                q.pop();
            }
            if(sum>maxsum)
            {
                maxsum=sum;
                ans=level;
            }
        }
        return ans;
    }
};
