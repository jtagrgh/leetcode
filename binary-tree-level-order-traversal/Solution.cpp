// https://leetcode.com/problems/binary-tree-level-order-traversal

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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> out;
        if (root == NULL) return out;
        queue<TreeNode *> q;
        q.push(root);
        
        vector<int> set;
        int cou = 0;
        int div = 1;
        while (!q.empty()) {
            TreeNode *node = q.front();
            q.pop();
            cou++;
            if (node != NULL) {
                set.push_back(node->val);
                q.push(node->left);
                q.push(node->right); 
            }
            if (cou == div) {
                if (!set.empty()) {
                    out.push_back(set);
                    div = set.size() * 2;
                    set.clear();
                }
                cou = 0;
            }
        }
        
        return out;
    }
};