/**
 * @file      minCost.cpp
 * @author    Khang Phan (vukhangk@outlook.com)
 * @brief     LeetCode #1578: Minimum Time to Make Rope Colorful
 * @see       <a href="https://leetcode.com/problems/minimum-time-to-make-rope-colorful">Minimum Time to Make Rope Colorful</a>
 *
 * @note      Brute force.
 *            Time Complexity : O(L) - L is the length of the string.
 *            Space Complexity: O(1).
 */

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int ans = 0;
        char prevColor = colors[0];
        int totalTime = neededTime[0];
        int maxTime = neededTime[0];

        // Main loop
        for (int i = 1; i < colors.size(); ++i) {
            char currColor = colors[i];
            int currTime = neededTime[i];

            // Check for consecutive balloons
            if (prevColor == currColor) {
                totalTime += currTime;
                maxTime = max(maxTime, currTime);
            } else {
                ans += totalTime - maxTime;
                prevColor = currColor;
                totalTime = currTime;
                maxTime = currTime;
            }
        }

        // Handle the very last consecutive balloon
        ans += totalTime - maxTime;

        // Return
        return ans;
    }
};
