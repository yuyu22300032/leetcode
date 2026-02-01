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
            bool curRemoved = false;
            if (cur->val == 0) {
                curRemoved = true;
                if (sumsfromNode.size() == 0) {
                    out = cur->next;
                } else {
                    sumsfromNode.back().second->next = cur->next;
                }
            } else {
                for (int i = 0; i < sumsfromNode.size(); i++) {
                    if ((sumsfromNode[i].first + cur->val) != 0) {
                        continue;
                    }
                    // sum from node[i] to cur node equals 0
                    curRemoved = true;
                    // no prev node, need to update head
                    if (i == 0) {
                        out = cur->next;
                        sumsfromNode.clear();
                        break;
                    }
                    for (int j = 0; j < i; j++) {
                        sumsfromNode[j].first -= cur->val;
                    }
                    while (i < sumsfromNode.size()) {
                        sumsfromNode.pop_back();
                    }
                    ListNode* prevNode = sumsfromNode[i - 1].second;
                    prevNode->next = cur->next;
                    break;
                }
            }
            if (curRemoved) {
                for (int i = 0; i < sumsfromNode.size(); i++) {
                    sumsfromNode[i].first += cur->val * 2;
                }
                cur = cur->next;
                continue;
            }
            for (int i = 0; i < sumsfromNode.size(); i++) {
                sumsfromNode[i].first += cur->val;
            }
            sumsfromNode.push_back(pair<int, ListNode*>(cur->val, cur));
            cur = cur->next;
        }
        return out;
    }
};
