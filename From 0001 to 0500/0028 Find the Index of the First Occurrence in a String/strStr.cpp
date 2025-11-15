/**
 * @file      strStr.cpp
 * @author    Khang Phan (vukhangk@outlook.com)
 * @brief     LeetCode #28: Find the Index of the First Occurrence in a String
 * @see       <a href="https://leetcode.com/problems/find-the-index-of-the-first-occurrence-in-a-string">Find the Index of the First Occurrence in a String</a>
 *
 * @note      The Knuth-Morris-Pratt (KMP) algorithm.
 *            Time Complexity : O(M + N) - M and N are the length of haystack and needle respectively.
 *            Space Complexity: O(N).
 */

#include <string>
#include <vector>

using namespace std;

class Solution {
private:
    // LPS (Longest Prefix Suffix) array
    void computeLPS(const string& needle, vector<int>& lps) {
        int len = 0; // Length of the previous longest prefix/suffix
        int i = 1;
        lps[0] = 0;
        while (i < needle.size()) {
            if (needle[i] == needle[len]) {
                ++len;
                lps[i] = len;
                ++i;
            } else {
                if (len != 0) {
                    len = lps[len - 1];
                } else {
                    lps[i] = 0;
                    ++i;
                }
            }
        }
    }

public:
    int strStr(string haystack, string needle) {
        int hlen = haystack.size();
        int nlen = needle.size();

        // Edge cases
        if (nlen == 0) {
            return 0;
        }
        if (hlen < nlen) {
            return -1;
        }

        // 1. Compute the LPS array
        vector<int> lps(nlen, 0);
        computeLPS(needle, lps);

        // 2. Search for needle in haystack
        int i = 0; // haystack
        int j = 0; // needle
        while (i < hlen) {
            // Match current characters
            if (needle[j] == haystack[i]) {
                ++i;
                ++j;
            }

            // Match all
            if (j == nlen) {
                return (i - j);
            } else if ((i < hlen) && (needle[j] != haystack[i])) {
                // Mismatch after j matches
                if (j != 0) {
                    j = lps[j - 1]; // Use LPS array to shift j backward
                } else { // Mismatch at the first character
                    ++i;
                }
            }
        }

        // No match found
        return -1;
    }
};
