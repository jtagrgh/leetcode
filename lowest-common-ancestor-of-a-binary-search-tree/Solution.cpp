// https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-search-tree

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    int find(TreeNode *root, TreeNode *s, vector<TreeNode *> &trace) {
        trace.push_back(root);
        if (root == s) {
            return 1;
        }
        if (s->val > root->val) {
            return find(root->right, s, trace);
        }
        else if (s->val < root->val) {
            return find(root->left, s, trace);
        }
        else { return -1; }
    }
    
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<TreeNode *> t1;
        vector<TreeNode *> t2;
        find(root, p, t1);
        find(root, q, t2);
        
        int m = min(t1.size(), t2.size());
        
        for (int i = 0; i < m; i++) {
            if (t1[i] != t2[i]) return t1[i-1];
        }
        
        return t1[m-1];
    }
};