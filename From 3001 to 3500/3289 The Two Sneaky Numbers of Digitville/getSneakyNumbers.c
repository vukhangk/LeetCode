/**
 * @file      getSneakyNumbers.c
 * @author    Khang Phan (vukhangk@outlook.com)
 * @brief     LeetCode #3289: The Two Sneaky Numbers of Digitville
 * @see       <a href="https://leetcode.com/problems/the-two-sneaky-numbers-of-digitville">The Two Sneaky Numbers of Digitville</a>
 * 
 * @note      Use XOR operation to find the two unique numbers in the array.
 *            Time Complexity : O(N) - N is the number of elements.
 *            Space Complexity: O(1).
 */

#include <stdlib.h>

int* getSneakyNumbers(int* nums, int numsSize, int* returnSize) {
    // Result array
    *returnSize = 2;
    int* ans = (int*)malloc(2 * sizeof(int));
    if (ans == NULL) {
        *returnSize = 0;
        return NULL;
    }

    // Calculate A ^ B (two sneaky numbers)
    int n = numsSize - 2;
    int xor = 0;
    for (int i = 0; i < numsSize; ++i)  {
        xor ^= nums[i]; // All numbers
        if (i < n)  {
            xor ^= i; // Non-sneaky numbers
        }
    }

    // The rightmost different bit or any different bit (A != B)
    int diffBit = xor & (-xor);
    int a = 0;
    int b = 0;

    // Partition the input array
    for (int i = 0; i < numsSize; ++i) {
        if (nums[i] & diffBit) {
            a ^= nums[i];
        }
        else {
            b ^= nums[i];
        }
    }

    // Partition the correct range [0, n-1]
    for (int i = 0; i < n; ++i) {
        if (i & diffBit) {
            a ^= i;
        } else {
            b ^= i;
        }
    }
    
    // Return
    ans[0] = a;
    ans[1] = b;
    return ans;
}
