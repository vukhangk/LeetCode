/**
 * @file      myAtoi.cpp
 * @author    Khang Phan (vukhangk@outlook.com)
 * @brief     LeetCode #8: String to Integer
 * @see       <a href="https://leetcode.com/problems/string-to-integer-atoi">String to Integer</a>
 *
 * @note      Brute force, check for overflow/underflow before updating the number.
 *            Time Complexity : O(N) - N is the length of the input string.
 *            Space Complexity: O(1).
 */

#include <string>
#include <climits>

using namespace std;

class Solution {
public:
    int myAtoi(string s) {
        int n = s.size();

        // Edge case
        if (n == 0) {
            return 0;
        }

        // Current index
        int idx = 0;

        // 1. Ignore all leading whitespaces
        while ((idx < n) && (s[idx] == ' ')) {
            ++idx;
        }
        // If the string is full of whitespaces
        if (idx >= n) {
            return 0;
        }

        // 2. Check the sign
        int sign = 1;
        if (s[idx] == '+') {
            ++idx;
        }
        else if (s[idx] == '-') {
            sign = -1;
            ++idx;
        }

        // 3. Convert to number
        long long number = 0;
        long long limit = (sign == 1) ? INT_MAX : -(long long)INT_MIN;
        while (idx < n) {
            int digit = s[idx] - '0';

            // Exit the loop if it is not a digit
            if ((digit < 0) || (digit > 9)) {
                break;
            }

            // Check the overflow
            if (number > limit / 10 || ((number == limit / 10) && (digit > limit % 10))) {
                return (sign == 1) ? INT_MAX : INT_MIN;
            }

            // Update number, leading zeros will not affect
            number = number * 10 + digit;
            ++idx;
        }

        // Return
        return (number * sign);
    }
};
