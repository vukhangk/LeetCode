/**
 * @file      removeOuterParentheses.cpp
 * @author    Khang Phan (vukhangk@outlook.com)
 * @brief     LeetCode #1021: Remove Outermost Parentheses
 * @see       <a href="https://leetcode.com/problems/remove-outermost-parentheses">Remove Outermost Parentheses</a>
 *
 * @note      A counter increments for opening parenthesis and decrements for closing ones.
 *            Time Complexity : O(L) - L is the length of the string.
 *            Space Complexity: O(L).
 */

#include <string>

using namespace std;

class Solution {
public:
    string removeOuterParentheses(string s) {
        int count = 0;
        string ans = "";
        for (const char& c : s) {
            // Outermost parentheses -> count = 0
            if ((c == '(') && (count++ > 0)) {
                ans.push_back(c);
            } else if ((c == ')') && (--count > 0)) {
                ans.push_back(c);
            }
        }

        // Return
        return ans;
    }
};
