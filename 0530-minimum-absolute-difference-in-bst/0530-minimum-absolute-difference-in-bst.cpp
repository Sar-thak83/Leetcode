class Solution {
public:
    void inorder(TreeNode* root, vector<int>& result) {
        if (!root)
            return;
        inorder(root->left, result);
        result.push_back(root->val);
        inorder(root->right, result);
    }
    int getMinimumDifference(TreeNode* root) {
        int mini=INT_MAX;
        vector<int> result;
        inorder(root, result);
        int n=result.size();
        sort(result.begin(),result.end());
        for(int i=1;i<n;i++){
            int diff=result[i]-result[i-1];
            mini=min(diff,mini);
        }
        return mini;
    }
};