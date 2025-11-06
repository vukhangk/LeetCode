/**
 * @file      myAtoi.c
 * @author    Khang Phan (vukhangk@outlook.com)
 * @brief     LeetCode #8: String to Integer
 * @see       <a href="https://leetcode.com/problems/string-to-integer-atoi">String to Integer</a>
 *
 * @note      Brute force, check for overflow/underflow before updating the number.
 *            Time Complexity : O(N) - N is the length of the input string.
 *            Space Complexity: O(1).
 */

#include <stddef.h>
#include <limits.h>

int myAtoi(char* s) {
    // Edge case
    if (s == NULL) {
        return 0;
    }

    // Current character pointer
    char* c = s;
    
    // 1. Ignore all leading whitespaces
    while (*c == ' ') {
        ++c;
    }
    // If the string is full of whitespaces
    if (*c == '\0') {
        return 0;
    }

    // 2. Check the sign
    int sign = 1;
    if (*c == '+') {
        ++c;
    }
    else if (*c == '-') {
        sign = -1;
        ++c;
    }

    // 3. Convert to number
    long long number = 0;
    long long limit = (sign == 1) ? INT_MAX : -(long long)INT_MIN;
    while (*c) {
        int digit = *c - '0';

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
        ++c;
    }

    // Return
    return (number * sign);
}
