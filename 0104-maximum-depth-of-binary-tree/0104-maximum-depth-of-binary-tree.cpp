// class Solution {
// public:
//     int maxDepth(TreeNode* root) {
//         if(root==NULL)
//         {
//             return 0;
//         }
//         queue <TreeNode*> q;
//         q.push(root);
//         int height=0;
//         while(!q.empty())
//         {
//             int size = q.size();
//             vector<int>level;
//             for(int i=0;i<size;i++)
//             {
//                 TreeNode *node=q.front();
//                 q.pop();
//                 level.push_back(node->val);
//                 if(node->right!=NULL)q.push(node->right);
//                 if(node->left!=NULL)q.push(node->left);
//             }
//             height++;
//         }
//         return height;
//     }
// };

class Solution {
public:
    int maxDepth(TreeNode* root) {
        if (root == NULL)
            return 0;
        int left = maxDepth(root->left);
        int right = maxDepth(root->right);
        return 1 + max(left, right);
    }
};