// https://leetcode.com/problems/validate-binary-search-tree

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
    bool isValidBST(TreeNode* root, long int l = -2147483648-1, long int r = 2147483648) {
        if (!root->left && !root->right) {
            cout << l << " " << root->val << " " << r << endl;
            if ((root->val < r) && (root->val > l)) return true;
            else return false;
        }
        
        bool tree = true;
        
        tree = tree && ((root->val < r) && (root->val > l));
        if (root->left) {
            tree = (tree && isValidBST(root->left, l, root->val));
        }
        if (root->right) { 
            tree = (tree && isValidBST(root->right, root->val, r));
        }
        
        return tree;
    }
};