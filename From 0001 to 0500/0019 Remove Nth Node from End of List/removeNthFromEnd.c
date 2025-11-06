/**
 * @file      removeNthFromEnd.c
 * @author    Khang Phan (vukhangk@outlook.com)
 * @brief     LeetCode #19: Remove Nth Node from End of List
 * @see       <a href="https://leetcode.com/problems/remove-nth-node-from-end-of-list">Remove Nth Node from End of List</a>
 *
 * @note      Maintain the gap between the two pointers and move the ahead pointer to the end.
 *            Time Complexity : O(N) - N is the length of the input list.
 *            Space Complexity: O(1).
 */

#include <stdlib.h>

// Definition for singly-linked list
struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* removeNthFromEnd(struct ListNode* head, int n) {
    // Dummy head
    struct ListNode* dummyHead = (struct ListNode*)malloc(sizeof(struct ListNode));
    dummyHead->val = 0;
    dummyHead->next = head;

    // Two pointers
    struct ListNode* behind = dummyHead;
    struct ListNode* ahead = dummyHead;

    // Move 'ahead' n+1 steps to create the gap with 'behind'
    for (int i = 0; i <= n; ++i) {
        ahead = ahead->next;
    }

    // Move both pointers until 'ahead' reaches the end
    while (ahead != NULL) {
        behind = behind->next;
        ahead = ahead->next;
    }

    // When 'ahead' is null, 'behind' is at the node before the target node
    struct ListNode* target = behind->next;
    behind->next = target->next;
    free(target);

    // Return
    struct ListNode* ans = dummyHead->next;
    free(dummyHead);
    return ans;
}
