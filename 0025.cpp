/*
25. Reverse Nodes in k-Group


Description:

Given the head of a linked list, reverse the nodes of the list k at a time, and return the modified list.

k is a positive integer and is less than or equal to the length of the linked list. If the number of nodes is not a multiple of k then left-out nodes, in the end, should remain as it is.

You may not alter the values in the list's nodes, only nodes themselves may be changed.

 

Example 1:

Input: head = [1,2,3,4,5], k = 2
Output: [2,1,4,3,5]

Example 2:

Input: head = [1,2,3,4,5], k = 3
Output: [3,2,1,4,5]

 

Constraints:

    The number of nodes in the list is n.
    1 <= k <= n <= 5000
    0 <= Node.val <= 1000

 

Follow-up: Can you solve the problem in O(1) extra memory space?

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
    ListNode* reverseKGroup(ListNode* head, int k) {
        bool out_set = false;
        ListNode* out = head;
        ListNode* nprev = nullptr;
        while (head)
        {
            ListNode* cur = head;
            for (int i = 0; i < k - 1; i++)
            {
                cur = cur->next;
                if (! cur)
                {
                    return out;
                }
            }
            if (! out_set)
            {
                out = cur;
                out_set = true;
            }
            else
            {
                nprev->next = cur;
            }
            ListNode* prev = cur->next;
            nprev = head;
            cur = head;
            head = prev;
            for (int i = 0; i < k; i++)
            {
                ListNode* tmp = cur->next;
                cur->next = prev;
                prev = cur;
                cur = tmp;
            }
        }
        return out;
    }
};

