/**
 * @file      convert.c
 * @author    Khang Phan (vukhangk@outlook.com)
 * @brief     LeetCode #6: Zigzag Conversion
 * @see       <a href="https://leetcode.com/problems/zigzag-conversion">Zigzag Conversion</a>
 *
 * @note      Use the index calculation for row placement to avoid strcat() in a loop.
 *            Time Complexity : O(L) - L is the length of the input string.
 *            Space Complexity: O(L).
 */

#include <string.h>

char* convert(char* s, int numRows) {
    int n = strlen(s);

    // Edge cases
    if ((n == 1) || (n == 2) || (numRows == 1)) {
        return s;
    }

    // Answer string
    char* ans = (char*)malloc((n + 1) * sizeof(char));
    int ansIdx = 0;

    // Main loop
    int cycleLen = 2 * (numRows - 1);
    for (int i = 0; i < numRows; i++) {
        // Iterate through characters that belong to row 'i' -> O(L/cycleLen)
        for (int j = i; j < n; j += cycleLen) {
            // Add the character at the main column
            ans[ansIdx++] = s[j];
            // Check for the middle character (only for inner rows)
            int midIdx = j + cycleLen - 2 * i;
            // Check if the current row 'i' is an inner row
            if ((i > 0) && (i < numRows - 1) && (midIdx < n)) {
                ans[ansIdx++] = s[midIdx];
            }
        }
    }

    // Return
    ans[ansIdx] = '\0';
    return ans;
}
