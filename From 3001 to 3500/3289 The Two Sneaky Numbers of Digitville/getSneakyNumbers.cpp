/**
 * @file      getSneakyNumbers.cpp
 * @author    Khang Phan (vukhangk@outlook.com)
 * @brief     LeetCode #3289: The Two Sneaky Numbers of Digitville
 * @see       <a href="https://leetcode.com/problems/the-two-sneaky-numbers-of-digitville">The Two Sneaky Numbers of Digitville</a>
 * 
 * @note      Use hash map to count the frequency of each number.
 *            Time Complexity : O(N) - N is the number of elements.
 *            Space Complexity: O(N).
 */

#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> getSneakyNumbers(vector<int>& nums) {
        vector<int> ans;
        unordered_map<int, int> freq;

        // Calculate the frequency
        for (const auto& num : nums) {
            ++freq[num];
        }

        // Find the keys appear 2 times
        for (const auto& pair : freq) {
            if (pair.second == 2) {
                ans.push_back(pair.first);
            }
        }

        // Return
        return ans;
    }
};
