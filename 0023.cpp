/*
23. Merge k Sorted Lists


Description:

You are given an array of k linked-lists lists, each linked-list is sorted in ascending order.

Merge all the linked-lists into one sorted linked-list and return it.

 

Example 1:

Input: lists = [[1,4,5],[1,3,4],[2,6]]
Output: [1,1,2,3,4,4,5,6]
Explanation: The linked-lists are:
[
  1->4->5,
  1->3->4,
  2->6
]
merging them into one sorted list:
1->1->2->3->4->4->5->6

Example 2:

Input: lists = []
Output: []

Example 3:

Input: lists = [[]]
Output: []

 

Constraints:

    k == lists.length
    0 <= k <= 104
    0 <= lists[i].length <= 500
    -104 <= lists[i][j] <= 104
    lists[i] is sorted in ascending order.
    The sum of lists[i].length will not exceed 104.


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
    struct Wrapper {
        ListNode* node;

        Wrapper(ListNode* _node)
        : node(_node) { ; }
    };
    struct Compare {
        // compiler did not allow pointer directly
        // bool operator()(const ListNode* node1, const ListNode* node2) const {return true}
        bool operator()(const Wrapper node1, const Wrapper node2) const {
            return node1.node->val > node2.node->val;
        }
    };
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        std::priority_queue<Wrapper, vector<Wrapper>, Compare> prio_queue;
        for (int i = 0; i < lists.size(); ++i)
        {
            if (lists[i])
            {
                prio_queue.push(Wrapper(lists[i]));
            }
        }
        if (prio_queue.empty())
        {
            return nullptr;
        }
        ListNode* out = prio_queue.top().node;
        prio_queue.pop();
        ListNode* cur = out;
        if (cur->next)
        {
            prio_queue.push(Wrapper(cur->next));
        }
        while (! prio_queue.empty())
        {
            cur->next = prio_queue.top().node;
            cur = cur->next;
            prio_queue.pop();
            if (cur->next)
            {
                prio_queue.push(Wrapper(cur->next));
            }
        }
        return out;
    }
};

