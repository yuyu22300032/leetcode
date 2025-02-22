/*
1028. Recover a Tree From Preorder Traversal


Description:

We run a preorder depth-first search (DFS) on the root of a binary tree.

At each node in this traversal, we output D dashes (where D is the depth of this node), then we output the value of this node.  If the depth of a node is D, the depth of its immediate child is D + 1.  The depth of the root node is 0.

If a node has only one child, that child is guaranteed to be the left child.

Given the output traversal of this traversal, recover the tree and return its root.

 

Example 1:

Input: traversal = "1-2--3--4-5--6--7"
Output: [1,2,5,3,4,6,7]

Example 2:

Input: traversal = "1-2--3---4-5--6---7"
Output: [1,2,5,3,null,6,null,4,null,7]

Example 3:

Input: traversal = "1-401--349---90--88"
Output: [1,401,null,349,88,90]

 

Constraints:

    The number of nodes in the original tree is in the range [1, 1000].
    1 <= Node.val <= 109


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
    void parse_string(string& traversal, vector<pair<int, int>>& nodes)
    {
        int cur_depth = 0;
        int i = 0;
        string val_str;
        while (i < traversal.size())
        {
            if (traversal[i] == '-')
            {
                if (! val_str.empty())
                {
                    nodes.push_back(pair<int, int>(cur_depth, stoi(val_str)));
                    val_str.clear();
                    cur_depth = 0;
                }
                cur_depth++;
            }
            else
            {
                val_str.push_back(traversal[i]);
            }
            i++;
        }
        nodes.push_back(pair<int, int>(cur_depth, stoi(val_str)));
    }
    TreeNode* recoverFromPreorder(string traversal) {
        vector<pair<int, int>> nodes;
        parse_string(traversal, nodes);
        for (int i = 0; i < nodes.size(); ++i)
        {
            cout << nodes[i].first << ", " << nodes[i].second << endl;
        }
        TreeNode* out = new TreeNode();
        out->val = nodes[0].second;
        vector<TreeNode*> path;
        path.push_back(out);
        int cur_depth = 0;
        for (int i = 1; i < nodes.size(); ++i)
        {
            while (cur_depth >= nodes[i].first)
            {
                path.pop_back();
                cur_depth--;
            }
            TreeNode* cur = new TreeNode();
            cur->val = nodes[i].second;
            if (path.back()->left == nullptr)
            {
                path.back()->left = cur;
            }
            else
            {
                path.back()->right = cur;
            }
            cur_depth++;
            path.push_back(cur);
        }
        return out;
    }
};

