/*
24. Swap Nodes in Pairs


Description:

Given a linked list, swap every two adjacent nodes and return its head. You must solve the problem without modifying the values in the list's nodes (i.e., only nodes themselves may be changed.)

 

Example 1:

Input: head = [1,2,3,4]

Output: [2,1,4,3]

Explanation:

Example 2:

Input: head = []

Output: []

Example 3:

Input: head = [1]

Output: [1]

Example 4:

Input: head = [1,2,3]

Output: [2,1,3]

 

Constraints:

    The number of nodes in the list is in the range [0, 100].
    0 <= Node.val <= 100


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
    ListNode* swapPairs(ListNode* head) {
        if (! head)
        {
            return nullptr;
        }
        if (! head->next)
        {
            return head;
        }
        ListNode* out = head->next;
        ListNode* cur = out->next;
        out->next = head;
        ListNode* prev = head;
        while (cur)
        {
            if (! cur->next)
            {
                prev->next = cur;
                return out;
            }
            prev->next = cur->next;
            prev = cur;
            ListNode* tmp = cur->next->next;
            cur->next->next = cur;
            cur = tmp;
        }
        prev->next = nullptr;

        return out;
    }
};
