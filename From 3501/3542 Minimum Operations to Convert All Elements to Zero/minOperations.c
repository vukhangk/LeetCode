/**
 * @file      minOperations.c
 * @author    Khang Phan (vukhangk@outlook.com)
 * @brief     LeetCode #3542: Minimum Operations to Convert All Elements to Zero
 * @see       <a href="https://leetcode.com/problems/minimum-operations-to-convert-all-elements-to-zero">Minimum Operations to Convert All Elements to Zero</a>
 * 
 * @note      Monotonic stack to find the next greater element on the left and right.
 *            Time Complexity : O(N) - N is the number of elements.
 *            Space Complexity: O(N).
 */

#include <stdlib.h>

int minOperations(int* nums, int numsSize) {
    // Monotonic increasing stack
    int* stk = (int*)malloc(numsSize * sizeof(int));
    if (!stk) {
        return 0;
    }

    // Main loop
    int top = 0;
    int ans = 0;
    for (int i = 0; i < numsSize; ++i) {
        int num = nums[i];

        // Pop smaller elements
        while ((top > 0) && (stk[top - 1] > num)) {
            --top;
        }

        // Skip if zero
        if (num == 0) {
            continue;
        }

        // New operation needed
        if ((top == 0) || (stk[top - 1] < num)) {
            ++ans;
            stk[top++] = num;
        }
    }

    // Return
    free(stk);
    return ans;
}
