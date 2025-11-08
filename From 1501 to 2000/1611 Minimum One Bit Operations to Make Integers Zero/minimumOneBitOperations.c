/**
 * @file      minimumOneBitOperations.c
 * @author    Khang Phan (vukhangk@outlook.com)
 * @brief     LeetCode #1611: Minimum One Bit Operations to Make Integers Zero
 * @see       <a href="https://leetcode.com/problems/minimum-one-bit-operations-to-make-integers-zero">Minimum One Bit Operations to Make Integers Zero</a>
 *
 * @note      Gray code.
 *            Time Complexity : O(log(n)) - n is the input integer.
 *            Space Complexity: O(1).
 */

int minimumOneBitOperations(int n) {
    // Gray code
    int ans = n;
    while (n > 0) {
        n >>= 1;
        ans ^= n;
    }

    // Return
    return ans;
}
