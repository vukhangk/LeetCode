/**
 * @file      deleteDuplicates.c
 * @author    Khang Phan (vukhangk@outlook.com)
 * @brief     LeetCode #83: Remove Duplicates from Sorted List
 * @see       <a href="https://leetcode.com/problems/remove-duplicates-from-sorted-list">Remove Duplicates from Sorted List</a>
 *
 * @note      Brute force.
 *            Time Complexity : O(N) - N is the number of nodes.
 *            Space Complexity: O(1) or O(N) - Modifies in place / Recursive stack.
 */

#include <stdlib.h>

// Definition for singly-linked list
struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* deleteDuplicates(struct ListNode* head) {
    struct ListNode* curr = head;

    // Main loop
    while ((curr != NULL) && (curr->next != NULL)) {
        if (curr->val == curr->next->val) {
            struct ListNode* duplicate = curr->next;
            curr->next = curr->next->next;
            free(duplicate);
        } else {
            curr = curr->next;
        }
    }

    // Return
    return head;
}

// Recursive approach
struct ListNode* deleteDuplicates2(struct ListNode* head) {
    // NULL or only one node left
    if ((head == NULL) || (head->next == NULL)) {
        return head;
    }
    
    // Return
    head->next = deleteDuplicates2(head->next);
    return ((head->val == head->next->val) ? head->next : head);
}
