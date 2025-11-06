/**
 * @file      maxArea.cpp
 * @author    Khang Phan (vukhangk@outlook.com)
 * @brief     LeetCode #11: Container with Most Water
 * @see       <a href="https://leetcode.com/problems/container-with-most-water">Container with Most Water</a>
 *
 * @note      Use two pointers to find the maximum area.
 *            Time Complexity : O(N) - N is the number of elements.
 *            Space Complexity: O(1).
 */

#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        // Two pointers
        int l  = 0;
        int r = height.size() - 1;

        // Main loop
        int maxArea = 0;
        while (l < r) {
            maxArea  = max(maxArea, min(height[r], height[l]) * (r - l));
            if (height[l] < height[r]) {
                ++l;
            } else {
                --r;
            }
        }

        // Return
        return maxArea;
        
    }
};
