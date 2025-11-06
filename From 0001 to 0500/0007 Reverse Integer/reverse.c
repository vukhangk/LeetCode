/**
 * @file      reverse.c
 * @author    Khang Phan (vukhangk@outlook.com)
 * @brief     LeetCode #7: Reverse Integer
 * @see       <a href="https://leetcode.com/problems/reverse-integer">Reverse Integer</a>
 * 
 * @note      Before adding a digit to the reversed integer, check for overflow/underflow.
 *            Time Complexity : O(log(|x|)).
 *            Space Complexity: O(1).
 */

#include <limits.h>

int reverse(int x) {
    int ans = 0;

    while (x != 0) {
        int digit = x % 10;
        x /= 10;

        // If result overflows or underflows, return 0
        if ((ans > INT_MAX / 10) || (ans < INT_MIN / 10)) {
            return 0;
        }

        // Reverse
        ans = ans * 10 + digit;
    }

    return ans;
}
