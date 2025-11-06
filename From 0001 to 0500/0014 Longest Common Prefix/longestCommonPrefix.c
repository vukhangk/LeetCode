/**
 * @file      maxArea.c
 * @author    Khang Phan (vukhangk@outlook.com)
 * @brief     LeetCode #14: Longest Common Prefix
 * @see       <a href="https://leetcode.com/problems/longest-common-prefix">Longest Common Prefix</a>
 *
 * @note      Vertical scanning, choose the first string as the reference.
 *            Time Complexity : O(S) - S is the sum of all characters in all strings.
 *            Space Complexity: O(1).
 */

char* longestCommonPrefix(char** strs, int strsSize) {
    // Get the size
    int strLen = strlen(strs[0]);

    // Main loop
    for (int j = 0; j < strLen; ++j) {
        // Iterate through each character of the first string
        char c = strs[0][j];
        // Compare with the same position in other strings
        for (int i = 1; i < strsSize; ++i) {
            if ((j == strlen(strs[i])) || (strs[i][j] != c)) {
                strs[0][j] = '\0';
                return strs[0];
            }
        }
    }

    // Return
    return strs[0];
}
