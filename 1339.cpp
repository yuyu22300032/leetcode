/*
1339. Maximum Product of Splitted Binary Tree


Description:

Given the root of a binary tree, split the binary tree into two subtrees by removing one edge such that the product of the sums of the subtrees is maximized.

Return the maximum product of the sums of the two subtrees. Since the answer may be too large, return it modulo 109 + 7.

Note that you need to maximize the answer before taking the mod and not after taking it.

 

Example 1:

Input: root = [1,2,3,4,5,6]
Output: 110
Explanation: Remove the red edge and get 2 binary trees with sum 11 and 10. Their product is 110 (11*10)

Example 2:

Input: root = [1,null,2,3,4,null,null,5,6]
Output: 90
Explanation: Remove the red edge and get 2 binary trees with sum 15 and 6.Their product is 90 (15*6)

 

Constraints:

    The number of nodes in the tree is in the range [2, 5 * 104].
    1 <= Node.val <= 104

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
    void updateValToSum(TreeNode* root) {
        if (root->left) {
            updateValToSum(root->left);
            root->val += root->left->val;
        }
        if (root->right) {
            updateValToSum(root->right);
            root->val += root->right->val;
        }
    }
public:
    int maxProduct(TreeNode* root) {
        updateValToSum(root);
        int total = root->val;
        int min_diff = INT_MAX;
        int min_diff_sum_val = 0;;
        queue<TreeNode*> search;
        search.push(root);
        while (! search.empty()) {
            TreeNode* cur = search.front();
            search.pop();
            if (cur->left) {
                search.push(cur->left);
            }
            if (cur->right) {
                search.push(cur->right);
            }
            int cur_diff = abs(total - cur->val - cur->val);
            if (cur_diff < min_diff) {
                min_diff = cur_diff;
                min_diff_sum_val = cur->val;
            }
        }
        return (long long)(total - min_diff_sum_val) * min_diff_sum_val % 1000000007;
    }
};

