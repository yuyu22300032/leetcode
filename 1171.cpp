/*
1171. Remove Zero Sum Consecutive Nodes from Linked List


Description:

Given the head of a linked list, we repeatedly delete consecutive sequences of nodes that sum to 0 until there are no such sequences.

After doing so, return the head of the final linked list.  You may return any such answer.

 

(Note that in the examples below, all sequences are serializations of ListNode objects.)

Example 1:

Input: head = [1,2,-3,3,1]
Output: [3,1]
Note: The answer [1,2,1] would also be accepted.

Example 2:

Input: head = [1,2,3,-3,4]
Output: [1,2,4]

Example 3:

Input: head = [1,2,3,-3,-2]
Output: [1]

 

Constraints:

    The given linked list will contain between 1 and 1000 nodes.
    Each node in the linked list has -1000 <= node.val <= 1000.


*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* removeZeroSumSublists(ListNode* head) {
        vector<pair<int, ListNode*>> sumsfromNode;
        ListNode* out = head;
        ListNode* cur = head;
        while (cur != nullptr) {
            sumsfromNode.push_back(pair<int, ListNode*>(0, cur));
            for (int i = 0; i < sumsfromNode.size(); i++) {
                sumsfromNode[i].first += cur->val;
                if (sumsfromNode[i].first == 0) {
                    if (i == 0) {
                        // no prev node, need to update head
                        out = cur->next;
                        sumsfromNode.clear();
                    } else {
                        sumsfromNode.resize(i);
                        sumsfromNode[i - 1].second->next = cur->next;
                    }
                }
            }
            cur = cur->next;
        }
        return out;
    }
};
