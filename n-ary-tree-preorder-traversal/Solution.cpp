// https://leetcode.com/problems/n-ary-tree-preorder-traversal

/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<int> preorder(Node* root) {
        vector<int> pre;
        if (root == NULL) return pre;
        
        stack<Node *> node_stack;
        node_stack.push(root);
        while (!node_stack.empty()) {
            Node *next = node_stack.top();
            node_stack.pop();
            pre.push_back(next->val);
            for (auto i = next->children.rbegin(); i != next->children.rend(); i++) {
                node_stack.push(*i);
            }
        }
                
        return pre;
    }
};