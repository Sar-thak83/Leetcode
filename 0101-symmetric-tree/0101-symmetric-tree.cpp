//--------Using BFS---------

// class Solution {
// public:
//     bool isSymmetric(TreeNode* root) {
//         if (!root) return true;
//         queue<TreeNode*> q;
//         q.push(root->left);
//         q.push(root->right);
//         while (!q.empty()) {
//             TreeNode* left = q.front(); q.pop();
//             TreeNode* right = q.front(); q.pop();
//             if (!left && !right) continue;
//             if (!left || !right) return false;
//             if (left->val != right->val) return false;
//             q.push(left->left);
//             q.push(right->right);
//             q.push(left->right);
//             q.push(right->left);
//         }
//         return true;
//     }
// };

// ----------Using recursive approach----------

class Solution {
public:
    bool Symmetric(TreeNode* rootA, TreeNode* rootB) {
        if (!rootA && !rootB)
            return true;
        if (!rootA || !rootB)
            return false;
        return (rootA->val == rootB->val) &&
               Symmetric(rootA->left, rootB->right) &&
               Symmetric(rootB->left, rootA->right);
    }
    bool isSymmetric(TreeNode* root) {
        if (root == NULL) {
            return true;
        }
        return Symmetric(root->left, root->right);
    }
};