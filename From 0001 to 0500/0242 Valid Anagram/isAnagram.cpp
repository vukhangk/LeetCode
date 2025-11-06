/**
 * @file      isAnagram.cpp
 * @author    Khang Phan (vukhangk@outlook.com)
 * @brief     LeetCode #242: Valid Anagram
 * @see       <a href="https://leetcode.com/problems/valid-anagram">Valid Anagram</a>
 *
 * @note      Frequency counting.
 *            Time Complexity : O(max(M, N)) - M and N are the lengths of the strings.
 *            Space Complexity: O(1).
 */

#include <array>
#include <string>

using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {
        array<int, 26> freqs = {};

        // Count the frequencies
        for (const char c : s) {
            ++freqs[c - 'a'];
        }
        for (const char c : t) {
            --freqs[c - 'a'];
        }

        // Check if all counts are zero
        for (const int freq : freqs) {
            if (freq != 0) {
                return false;
            }
        }

        // Default
        return true;
    }
};
