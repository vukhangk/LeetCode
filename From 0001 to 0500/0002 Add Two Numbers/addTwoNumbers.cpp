/**
 * @file      addTwoNumbers.cpp
 * @author    Khang Phan (vukhangk@outlook.com)
 * @brief     LeetCode #2: Add Two Numbers
 * @see       <a href="https://leetcode.com/problems/add-two-numbers">Add Two Numbers</a>
 *
 * @note      Utilize a dummy head to anchor the result list.
 *            Time Complexity : O(max(M, N)) - M and N are the lengths of the two input lists.
 *            Space Complexity: O(max(M, N)).
 */

// Definition for singly-linked list
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        // Dummy head
        ListNode* dummyHead = new ListNode(0);
        ListNode* currTail = dummyHead;

        // Main loop
        int carry = 0;
        while ((l1 != nullptr) || (l2 != nullptr) || (carry != 0)) {
            int val1 = (l1 != nullptr) ? l1->val : 0;
            int val2 = (l2 != nullptr) ? l2->val : 0;
            int sum = val1 + val2 + carry;
            carry = sum / 10;

            // Append new node
            currTail->next = new ListNode(sum % 10);
            currTail = currTail->next;

            // Advance l1 and l2
            if (l1 != nullptr) {
                l1 = l1->next;
            }
            if (l2 != nullptr) {
                l2 = l2->next;
            }
        }

        // Return
        ListNode* ans = dummyHead->next;
        delete dummyHead;
        return ans;
    }
};
