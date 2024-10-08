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
    int height(TreeNode* node) {
        if (node == nullptr)
            return 0;
        return 1 + max(height(node->left), height(node->right));
    }
 int diameterOfBinaryTree(TreeNode* root) {
    if (root == nullptr)
        return 0;
    int lheight = height(root->left);
    int rheight = height(root->right);

    int ldiameter = diameterOfBinaryTree(root->left);
    int rdiameter = diameterOfBinaryTree(root->right);

    return max({lheight + rheight, ldiameter, rdiameter});
}
}
;