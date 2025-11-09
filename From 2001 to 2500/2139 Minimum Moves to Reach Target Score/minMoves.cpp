/**
 * @file      minMoves.cpp
 * @author    Khang Phan (vukhangk@outlook.com)
 * @brief     LeetCode #2139: Minimum Moves to Reach Target Score
 * @see       <a href="https://leetcode.com/problems/minimum-moves-to-reach-target-score">Minimum Moves to Reach Target Score</a>
 *
 * @note      Prioritize using double operations when possible.
 *            Time Complexity : O(log(n)) - n is the target score.
 *            Space Complexity: O(1).
 */

class Solution {
public:
    int minMoves(int target, int maxDoubles) {
        int ans = 0;

        // Prioritize using double operations when possible
        while ((target > 1) && (maxDoubles > 0)) {
            if (target & 0x1) { // Odd
                ans += 2; // Decreased by 1 and then divide by 2
            } else { // Even
                ans +=1; // Divide by 2
            }
            --maxDoubles;
            target /= 2;
        }

        // Remaining increments
        ans += target - 1;

        // Return
        return ans;
    }
};
