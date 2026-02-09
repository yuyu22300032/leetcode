/*
1382. Balance a Binary Search Tree


Description:

Given the root of a binary search tree, return a balanced binary search tree with the same node values. If there is more than one answer, return any of them.

A binary search tree is balanced if the depth of the two subtrees of every node never differs by more than 1.

 

Example 1:

Input: root = [1,null,2,null,3,null,4,null,null]
Output: [2,1,3,null,null,null,4]
Explanation: This is not the only correct answer, [3,1,4,null,2] is also correct.

Example 2:

Input: root = [2,1,3]
Output: [2,1,3]

 

Constraints:

    The number of nodes in the tree is in the range [1, 104].
    1 <= Node.val <= 105


*/

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
    static bool compareNodeValues(const TreeNode* a, const TreeNode* b) {
        return a->val < b->val;
    }
    TreeNode* constructBST(const vector<TreeNode*>& nodes, const int strIdx, const int endIdx) {
        int mid = (strIdx + endIdx) / 2;
        TreeNode* cur = nodes[mid];
        if (strIdx < mid) {
            cur->left = constructBST(nodes, strIdx, mid - 1);
        } else {
            cur->left = nullptr;
        }
        if (endIdx > mid) {
            cur->right = constructBST(nodes, mid + 1, endIdx);
        } else {
            cur->right = nullptr;
        }
        return cur;
    }
public:
    TreeNode* balanceBST(TreeNode* root) {
        vector<TreeNode*> nodes;
        queue<TreeNode*> search;
        search.push(root);
        while (!search.empty()) {
            TreeNode* cur = search.front();
            search.pop();
            nodes.push_back(cur);
            if (cur->left) {
                search.push(cur->left);
            }
            if (cur->right) {
                search.push(cur->right);
            }
        }
        sort(nodes.begin(), nodes.end(), compareNodeValues);
        return constructBST(nodes, 0, nodes.size() - 1);
    }
};
