/**
 * @file      isAnagram.c
 * @author    Khang Phan (vukhangk@outlook.com)
 * @brief     LeetCode #242: Valid Anagram
 * @see       <a href="https://leetcode.com/problems/valid-anagram">Valid Anagram</a>
 *
 * @note      Frequency counting.
 *            Time Complexity : O(max(M, N)) - M and N are the lengths of the strings.
 *            Space Complexity: O(1).
 */

#include <stdbool.h>

bool isAnagram(char* s, char* t) {
    int freqs[26] = {0};
    char* c;

    // Count the frequency
    c = s;
    while (*c) {
        ++freqs[*c - 'a'];
        ++c;
    }
    c = t;
    while (*c) {
        --freqs[*c - 'a'];
        ++c;
    }

    // Check if all counts are zero
    for (int i = 0; i < 26; ++i) {
        if (freqs[i] != 0) {
            return false;
        }
    }

    // Default
    return true;
}
