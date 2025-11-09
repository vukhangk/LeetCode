/**
 * @file      numberOfSteps.cpp
 * @author    Khang Phan (vukhangk@outlook.com)
 * @brief     LeetCode #1342: Number of Steps to Reduce a Number to Zero
 * @see       <a href="https://leetcode.com/problems/number-of-steps-to-reduce-a-number-to-zero">Number of Steps to Reduce a Number to Zero</a>
 *
 * @note      Brute force.
 *            Time Complexity : O(log(n)) - n is the input number.
 *            Space Complexity: O(1).
 */

class Solution {
public:
    int numberOfSteps(int num) {
        // Main loop
        int ans = 0;
        while (num > 0) {
            if (num & 0x1) {
                --num;
            } else {
                num >>= 1;
            }
            ++ans;
        }

        // Return
        return ans;
    }
};
