/**
 * @file      maxArea.cpp
 * @author    Khang Phan (vukhangk@outlook.com)
 * @brief     LeetCode #14: Longest Common Prefix
 * @see       <a href="https://leetcode.com/problems/longest-common-prefix">Longest Common Prefix</a>
 *
 * @note      Vertical scanning, choose the first string as the reference.
 *            Time Complexity : O(S) - S is the sum of all characters in all strings.
 *            Space Complexity: O(1).
 */

#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        // Get the size
        int n = strs.size();
        int strLen = strs[0].size();

        // Main loop
        for (int j = 0; j < strLen; ++j) {
            // Iterate through each character of the first string
            char c = strs[0][j];
            // Compare with the same position in other strings
            for (int i = 1; i < n; ++i) {
                if ((j == strs[i].size()) || (strs[i][j] != c)) {
                    return strs[0].substr(0, j);
                }
            }
        }

        // Return
        return strs[0];
    }
};
