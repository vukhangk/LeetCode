/**
 * @file      maxOperations.cpp
 * @author    Khang Phan (vukhangk@outlook.com)
 * @brief     LeetCode #3228: Maximum Number of Operations to Move Ones to the End
 * @see       <a href="https://leetcode.com/problems/maximum-number-of-operations-to-move-ones-to-the-end">Maximum Number of Operations to Move Ones to the End</a>
 * 
 * @note      Each '0' will get passed by the number of '1's before it.
 *            Time Complexity : O(N) - N is the number of bits.
 *            Space Complexity: O(1).
 */

#include <string>

using namespace std;

class Solution {
public:
    int maxOperations(string s) {
        // Main loop
        int ans = 0;
        int ones = (s[0] == '1');
        for (int i = 1; i < s.size(); ++i) {
            if (s[i] == '1') {
                ++ones;
            } else {
                if (s[i - 1] == '1') {
                    ans += ones;
                }
            }
        }

        // Return
        return ans;
    }
};
