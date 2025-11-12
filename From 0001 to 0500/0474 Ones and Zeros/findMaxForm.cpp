/**
 * @file      findMaxForm.cpp
 * @author    Khang Phan (vukhangk@outlook.com)
 * @brief     LeetCode #474: Ones and Zeros
 * @see       <a href="https://leetcode.com/problems/ones-and-zeros">Ones and Zeros</a>
 * 
 * @note      DP to find the maximum number of strings that can be formed with given zeros and ones.
 *            Time Complexity : O(N * m * n) - N is the number of strings, m and n are the limits for zeros and ones.
 *            Space Complexity: O(m * n).
 */

#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

        // Main loop
        for (const string& str : strs) {
            int zeros = count(str.begin(), str.end(), '0');
            int ones = str.size() - zeros;
            for (int i = m; i >= zeros; --i) {
                for (int j = n; j >= ones; --j) {
                    dp[i][j] = max(dp[i][j], dp[i - zeros][j - ones] + 1);
                }
            }
        }

        // Return
        return dp[m][n];
    }
};