/**
 * @file      convert.cpp
 * @author    Khang Phan (vukhangk@outlook.com)
 * @brief     LeetCode #6: Zigzag Conversion
 * @see       <a href="https://leetcode.com/problems/zigzag-conversion">Zigzag Conversion</a>
 *
 * @note      Brute force with a variable representation for down direction.
 *            Time Complexity : O(L) - L is the length of the input string.
 *            Space Complexity: O(L).
 */

#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    string convert(string s, int numRows) {
        int n = s.size();

        // Edge cases
        if ((n == 1) || (n == 2) || (numRows == 1)) {
            return s;
        }

        // Answer string and row storage
        string ans = "";
        vector<string> rows(numRows, "");

        // Main loop
        int row = 0;
        int down = true;
        for (const char c : s) {
            rows[row].push_back(c);
            row += (down) ? 1 : -1;
            if ((row == 0) || (row == numRows - 1)) {
                down = !down;
            }
        }

        // Combine rows
        for (const string& str : rows) {
            ans.append(str);
        }

        // Return
        return ans;
    }
};
