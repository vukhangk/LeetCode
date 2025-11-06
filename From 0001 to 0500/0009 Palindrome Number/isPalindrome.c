/**
 * @file      isPalindrome.c
 * @author    Khang Phan (vukhangk@outlook.com)
 * @brief     LeetCode #9: Palindrome Number
 * @see       <a href="https://leetcode.com/problems/palindrome-number">Palindrome Number</a>
 *
 * @note      Split the number into two halves and compare.
 *            Time Complexity : O(log(n)) - n is the input positive number.
 *            Space Complexity: O(1).
 */

#include <stdbool.h>

bool isPalindrome(int x) {
    // Edge cases
    if ((x < 0) || ((x % 10 == 0) && (x != 0))) {
        return false;
    }
    
    // Check on the reverse half
    int rev = 0;
    while (x > rev) {
        rev = rev * 10 + (x % 10);
        x /= 10;
    }

    // Return
    return ((x == rev) || (x == rev / 10));
}
