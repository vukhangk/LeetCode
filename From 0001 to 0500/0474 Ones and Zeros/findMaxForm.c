/**
 * @file      findMaxForm.c
 * @author    Khang Phan (vukhangk@outlook.com)
 * @brief     LeetCode #474: Ones and Zeros
 * @see       <a href="https://leetcode.com/problems/ones-and-zeros">Ones and Zeros</a>
 * 
 * @note      DP to find the maximum number of strings that can be formed with given zeros and ones.
 *            Time Complexity : O(N * m * n) - N is the number of strings, m and n are the limits for zeros and ones.
 *            Space Complexity: O(m * n).
 */

#include <stdlib.h>

#define MAX(A, B)       ((A) > (B) ? (A) : (B))

int findMaxForm(char** strs, int strsSize, int m, int n) {
    // Allocate DP array
    int* dp = (int*)calloc((m + 1) * (n + 1), sizeof(int));
    if (!dp) {
        return 0;
    }

    // Main loop
    for (int k = 0; k < strsSize; ++k) {
        // Count '0's and '1's
        int zeros = 0;
        int ones = 0;
        for (char* c = strs[k]; *c; ++c) {
            if (*c == '0') {
                ++zeros;
            } else { // *c == '1'
                ++ones;
            }
        }

        // Update DP array
        for (int i = m; i >= zeros; --i) {
            for (int j = n; j >= ones; --j) {
                int idx = i * (n + 1) + j;
                int prevIdx = (i - zeros) * (n + 1) + (j - ones);
                dp[idx] = MAX(dp[idx], dp[prevIdx] + 1);
            }
        }
    }

    // Return
    int ans = dp[m * (n + 1) + n]; // dp[m][n]
    free(dp);
    return ans;
}
