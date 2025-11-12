/**
 * @file      minOperations.cpp
 * @author    Khang Phan (vukhangk@outlook.com)
 * @brief     LeetCode #3542: Minimum Operations to Convert All Elements to Zero
 * @see       <a href="https://leetcode.com/problems/minimum-operations-to-convert-all-elements-to-zero">Minimum Operations to Convert All Elements to Zero</a>
 * 
 * @note      Monotonic stack to find the next greater element on the left and right.
 *            Time Complexity : O(N) - N is the number of elements.
 *            Space Complexity: O(N).
 */

#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int minOperations(vector<int>& nums) {
        // Monotonic increasing stack
        vector<int> stk;
       
        // Main loop
        int ans = 0;
        for (int num : nums) {
            // Pop smaller elements
            while ((!stk.empty()) && (stk.back() > num)) {
                stk.pop_back();
            }

            // Skip if zero
            if (num == 0) {
                continue;
            }

            // New operation needed
            if ((stk.empty()) || (stk.back() < num)) {
                ++ans;
                stk.push_back(num);
            }
        }

        // Return
        return ans;
    }
};
