/*
110. Balanced Binary Tree


Description:

Given a binary tree, determine if it is .

 

Example 1:

Input: root = [3,9,20,null,null,15,7]
Output: true

Example 2:

Input: root = [1,2,2,3,3,null,null,4,4]
Output: false

Example 3:

Input: root = []
Output: true

 

Constraints:

    The number of nodes in the tree is in the range [0, 5000].
    -104 <= Node.val <= 104


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
    int checkBalancedAndGetHeight(TreeNode* root) {
        // return -1 for unbalanced
        if (root == nullptr) {
            return 0;
        }
        int leftHeight = checkBalancedAndGetHeight(root->left);
        if (leftHeight == -1) {
            return -1;
        }
        int rightHeight = checkBalancedAndGetHeight(root->right);
        if (rightHeight == -1) {
            return -1;
        }
        if (abs(leftHeight - rightHeight) > 1) {
            return -1;
        }
        return max(leftHeight, rightHeight) + 1;
    }
public:
    bool isBalanced(TreeNode* root) {
        return (checkBalancedAndGetHeight(root) == -1) ? false : true;
    }
};
