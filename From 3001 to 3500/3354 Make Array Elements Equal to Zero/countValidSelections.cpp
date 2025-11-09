/**
 * @file      countValidSelections.cpp
 * @author    Khang Phan (vukhangk@outlook.com)
 * @brief     LeetCode #3354: Make Array Elements Equal to Zero
 * @see       <a href="https://leetcode.com/problems/make-array-elements-equal-to-zero">Make Array Elements Equal to Zero</a>
 *
 * @note      The sum of the left and right subarrays must be equal (2 valid directions) or differ by 1 (1 valid direction).
 *            Time Complexity : O(n) - n is the number of elements in the array.
 *            Space Complexity: O(1).
 */

#include <vector>
#include <numeric>

using namespace std;

class Solution {
public:
    int countValidSelections(vector<int>& nums) {
        int n = nums.size();
        int sum = accumulate(nums.begin(), nums.end(), 0);

        // Main loop
        int ans = 0;
        int sumLeft = 0;
        for (int i = 0; i < n; ++i) {
            int sumRight = sum - sumLeft;
            if (nums[i] == 0) {
                if ((sumLeft == sumRight)) {
                    ans += 2;
                } else if ((sumLeft == sumRight + 1) || (sumLeft == sumRight - 1)) {
                    ans += 1;
                }
            } else {
                sumLeft += nums[i];
            }
        }

        // Return
        return ans;
    }
};
