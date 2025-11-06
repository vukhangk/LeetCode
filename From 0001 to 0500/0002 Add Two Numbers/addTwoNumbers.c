/**
 * @file      addTwoNumbers.c
 * @author    Khang Phan (vukhangk@outlook.com)
 * @brief     LeetCode #2: Add Two Numbers
 * @see       <a href="https://leetcode.com/problems/add-two-numbers">Add Two Numbers</a>
 *
 * @note      Utilize a dummy head to anchor the result list.
 *            Time Complexity : O(max(M, N)) - M and N are the lengths of the two input lists.
 *            Space Complexity: O(max(M, N)).
 */

#include <stdlib.h>

// Definition for singly-linked list
struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    // Dummy head
    struct ListNode* dummyHead = (struct ListNode*)malloc(sizeof(struct ListNode));
    dummyHead->val = 0;
    dummyHead->next = NULL;
    struct ListNode* currTail = dummyHead;

    // Main loop
    int carry = 0;
    while ((l1 != NULL) || (l2 != NULL) || (carry != 0)) {
        int val1 = (l1 != NULL) ? l1->val : 0;
        int val2 = (l2 != NULL) ? l2->val : 0;
        int sum = val1 + val2 + carry;
        carry = sum / 10;

        // Append new node
        struct ListNode* newNode = (struct ListNode*)malloc(sizeof(struct ListNode));
        newNode->val = sum % 10;
        newNode->next = NULL;
        currTail->next = newNode;
        currTail = currTail->next;

        // Advance l1 and l2
        if (l1 != NULL) {
            l1 = l1->next;
        }
        if (l2 != NULL) {
            l2 = l2->next;
        }
    }

    // Return
    struct ListNode* ans = dummyHead->next;
    free(dummyHead);
    return ans;
}
