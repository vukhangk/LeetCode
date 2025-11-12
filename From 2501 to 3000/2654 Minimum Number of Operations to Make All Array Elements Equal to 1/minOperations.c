/**
 * @file      minOperations.c
 * @author    Khang Phan (vukhangk@outlook.com)
 * @brief     LeetCode #2654: Minimum Number of Operations to Make All Array Elements Equal to 1
 * @see       <a href="https://leetcode.com/problems/minimum-number-of-operations-to-make-all-array-elements-equal-to-1">Minimum Number of Operations to Make All Array Elements Equal to 1</a>
 *
 * @note      Divide the problem into two cases: there is at least one '1' and no '1' in the array.
 *            Time Complexity : O(N ^ 2 * log(maxElement)) - N is the number of elements in the array, log(maxElement) is due to the GCD calculation.
 *            Space Complexity: O(1).
 */

#include <limits.h>
#include <stdlib.h>

#define MIN(A, B)       (((A) < (B)) ? (A) : (B))

int gcd(int a, int b) {
    // Euclidean algorithm
    while (b != 0) {
        int tmp = b;
        b = a % b;
        a = tmp;
    }

    // Return
    return a;
}

int minOperations(int* nums, int numsSize) {
    int n = numsSize;

    // Case 1: There is at least one '1' in the array
    int ones = 0;
    for (int i = 0; i < n; ++i) {
        if (nums[i] == 1) {
            ones++;
        }
    }
    if (ones > 0) {
        return (n - ones);
    }
    
    // Case 2: No '1' in the array, need to find the shortest subarray with GCD = 1
    int minOps = INT_MAX;
    for (int i = 0; i < n; ++i) {
        int g = nums[i];
        for (int j = i + 1; j < n; ++j) {
            // If GCD(a, b) = g, then GCD(a, b, c) = GCD(g, c)
            g = gcd(g, nums[j]);
            if (g == 1) {
                minOps = MIN(minOps, j - i);
                break;
            }
        }
    }

    // Need additional n - 1 operations
    return ((minOps == INT_MAX) ? (-1) : (minOps + (n - 1)));
}
