/**
 * @file      removeNthFromEnd.cpp
 * @author    Khang Phan (vukhangk@outlook.com)
 * @brief     LeetCode #19: Remove Nth Node from End of List
 * @see       <a href="https://leetcode.com/problems/remove-nth-node-from-end-of-list">Remove Nth Node from End of List</a>
 *
 * @note      Maintain the gap between the two pointers and move the ahead pointer to the end.
 *            Time Complexity : O(N) - N is the length of the input list.
 *            Space Complexity: O(1).
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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        // Dummy head
        ListNode* dummyHead = new ListNode(0);
        dummyHead->next = head;

        // Two pointers
        ListNode* behind = dummyHead;
        ListNode* ahead = dummyHead;

        // Move 'ahead' n+1 steps to create the gap with 'behind'
        for (int i = 0; i <= n; ++i) {
            ahead = ahead->next;
            
        }

        // Move both pointers until 'ahead' reaches the end
        while (ahead != nullptr) {
            behind = behind->next;
            ahead = ahead->next;
        }

        // When 'ahead' is null, 'behind' is at the node before the target node
        ListNode* target = behind->next;
        behind->next = target->next;
        delete target;
        
        // Return
        ListNode* ans = dummyHead->next;
        delete dummyHead;
        return ans;
    }
};
