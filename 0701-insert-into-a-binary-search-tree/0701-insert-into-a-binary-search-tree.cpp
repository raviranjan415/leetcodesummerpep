class Solution {
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        // Fix: Create and return a new node when an empty spot is found
        if (root == NULL) {
            return new TreeNode(val);
        }
        
        if (val < root->val) {
            root->left = insertIntoBST(root->left, val);
        } else {
            root->right = insertIntoBST(root->right, val);
        }
        
        return root;
    }
};
