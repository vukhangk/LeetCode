/**
 * @file      lengthOfLongestSubstring.cpp
 * @author    Khang Phan (vukhangk@outlook.com)
 * @brief     LeetCode #3: Longest Substring Without Repeating Characters
 * @see       <a href="https://leetcode.com/problems/longest-substring-without-repeating-characters">Longest Substring Without Repeating Characters</a>
 *
 * @note      Utilize a sliding window with a hash map to track characters indices.
 *            Time Complexity : O(N) - N is the length of the input string.
 *            Space Complexity: O(K) - K is the character set size (hash map keys).
 */

#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        unordered_map<char, int> map;
        
        // Main loop
        int left = 0;
        int maxLen = 0;
        for (int right = 0; right < n; ++right) {
            char c = s[right];
            // If c exists before and its index is within the current window
            if ((map.count(c)) && (map[c] > left)) {
                left = map[c]; // Move left pointer to the index after the previous occurrence of c
            }
            map[c] = right + 1;
            maxLen = max(maxLen, right - left + 1);

        }

        // Return
        return maxLen;
    }
};
