/*
889. Construct Binary Tree from Preorder and Postorder Traversal


Description:

Given two integer arrays, preorder and postorder where preorder is the preorder traversal of a binary tree of distinct values and postorder is the postorder traversal of the same tree, reconstruct and return the binary tree.

If there exist multiple answers, you can return any of them.

 

Example 1:

Input: preorder = [1,2,4,5,3,6,7], postorder = [4,5,2,6,7,3,1]
Output: [1,2,3,4,5,6,7]

Example 2:

Input: preorder = [1], postorder = [1]
Output: [1]

 

Constraints:

    1 <= preorder.length <= 30
    1 <= preorder[i] <= preorder.length
    All the values of preorder are unique.
    postorder.length == preorder.length
    1 <= postorder[i] <= postorder.length
    All the values of postorder are unique.
    It is guaranteed that preorder and postorder are the preorder traversal and postorder traversal of the same binary tree.


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
public:
    TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
        int pre_idx = 0;
        int post_idx = 0;
        TreeNode* out = new TreeNode();
        out->val = preorder[pre_idx];
        pre_idx++;
        vector<TreeNode*> path;
        path.push_back(out);
        while (post_idx < postorder.size())
        {
            while (path.back()->val != postorder[post_idx])
            {
                TreeNode* cur = new TreeNode();
                cur->val = preorder[pre_idx];
                pre_idx++;
                if (path.back()->left == nullptr)
                {
                    path.back()->left = cur;
                }
                else
                {
                    path.back()->right = cur;
                }
                path.push_back(cur);
            }
            path.pop_back();
            post_idx++;
        }
        return out;
    }
};

