/**
 * @file      numSteps.c
 * @author    Khang Phan (vukhangk@outlook.com)
 * @brief     LeetCode #1404: Number of Steps to Reduce a Number in Binary Representation to One
 * @see       <a href="https://leetcode.com/problems/number-of-steps-to-reduce-a-number-in-binary-representation-to-one">Number of Steps to Reduce a Number in Binary Representation to One</a>
 *
 * @note      Reverse iteration and carry handling.
 *            Time Complexity : O(log(L)) - L is the length of the binary string.
 *            Space Complexity: O(1).
 */

#include <string.h>

int numSteps(char* s) {
    // Main loop
    int ans = 0;
    int carry = 0;
    for (int i = strlen(s) - 1; i > 0; --i) {
        int curr = s[i] - '0' + carry;
        if (curr & 0x1) {
            ans += 2;
            carry = 1;
        } else {
            ans += 1;
        }
    }

    // Return
    return (ans + carry);
}
