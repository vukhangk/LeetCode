/**
 * @file      deleteDuplicates.cpp
 * @author    Khang Phan (vukhangk@outlook.com)
 * @brief     LeetCode #83: Remove Duplicates from Sorted List
 * @see       <a href="https://leetcode.com/problems/remove-duplicates-from-sorted-list">Remove Duplicates from Sorted List</a>
 *
 * @note      Brute force.
 *            Time Complexity : O(N) - N is the number of nodes.
 *            Space Complexity: O(1) or O(N) - Modifies in place / Recursive stack.
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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* curr = head;

        // Main loop
        while ((curr != nullptr) && (curr->next != nullptr)) {
            if (curr->val == curr->next->val) {
                ListNode* duplicate = curr->next;
                curr->next = curr->next->next;
                delete duplicate;
            } else {
                curr = curr->next;
            }
        }

        // Return
        return head;
    }

    // Recursive approach
    ListNode* deleteDuplicates2(ListNode* head) {
        // NULL or only one node left
        if ((head == nullptr) || (head->next == nullptr)) {
            return head;
        }
        
        // Return
        head->next = deleteDuplicates2(head->next);
        return ((head->val == head->next->val) ? head->next : head);
    }
};
