/**
 * @file      minNumberOperations.cpp
 * @author    Khang Phan (vukhangk@outlook.com)
 * @brief     LeetCode #1526: Minimum Number of Increments on Subarrays to Form a Target Array
 * @see       <a href="https://leetcode.com/problems/minimum-number-of-increments-on-subarrays-to-form-a-target-array">Minimum Number of Increments on Subarrays to Form a Target Array</a>
 * 
 * @note      Sum of all positive differences between consecutive elements plus the first element.
 *            Time Complexity : O(N) - N is the size of the target array.
 *            Space Complexity: O(1).
 */

#include <vector>

using namespace std;

class Solution {
public:
    int minNumberOperations(vector<int>& target) {
        int ans = target[0];
        for (int i = 1; i < target.size(); ++i) {
            if (target[i] > target[i - 1]) {
                ans += target[i] - target[i - 1];
            }
        }
        return ans;
    }
};