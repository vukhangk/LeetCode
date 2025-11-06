/**
 * @file      twoSum.cpp
 * @author    Khang Phan (vukhangk@outlook.com)
 * @brief     LeetCode #1: Two Sum
 * @see       <a href="https://leetcode.com/problems/two-sum">Two Sum</a>
 * 
 * @note      Utilize the hash map to store complements and their indices.
 *            Time Complexity : O(N) - N is the number of elements in the input list.
 *            Space Complexity: O(N).
 */

#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        // Store complement values
        unordered_map<int, int> map;
        
        // Main loop
        for (int i = 0; i < nums.size(); ++i) {
            int a = nums[i];    // Number
            int b = target - a; // Complement
            if (map.count(b)) {
                return {map[b], i};
            } else {
                map[a] = i;
            }
        }

        // Return empty if no solution found
        return {};
    }
};
