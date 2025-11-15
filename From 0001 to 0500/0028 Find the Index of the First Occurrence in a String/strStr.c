/**
 * @file      strStr.c
 * @author    Khang Phan (vukhangk@outlook.com)
 * @brief     LeetCode #28: Find the Index of the First Occurrence in a String
 * @see       <a href="https://leetcode.com/problems/find-the-index-of-the-first-occurrence-in-a-string">Find the Index of the First Occurrence in a String</a>
 *
 * @note      The Knuth-Morris-Pratt (KMP) algorithm.
 *            Time Complexity : O(M + N) - M and N are the length of haystack and needle respectively.
 *            Space Complexity: O(N).
 */

#include <string.h>

void computeLPS(const char* needle, int* lps) {
    int len = 0; // Length of the previous longest prefix/suffix
    int i = 1;
    lps[0] = 0;
    while (i < strlen(needle)) {
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

int strStr(char* haystack, char* needle) {
    int hlen = strlen(haystack);
    int nlen = strlen(needle);

    // Edge cases
    if (nlen == 0) {
        return 0;
    }
    if (hlen < nlen) {
        return -1;
    }

    // 1. Compute the LPS array
    int* lps = (int*)malloc(nlen * sizeof(int));
    computeLPS(needle, lps);

    // 2. Search for needle in haystack
    int i = 0; // haystack
    int j = 0; // needle
    while (i < hlen) {
        // Match current characters
        if (haystack[i] == needle[j]) {
            ++i;
            ++j;
        }

        // Match all
        if (j == nlen) {
            free(lps);
            return (i - j);
        } else if ((i < hlen) && (haystack[i] != needle[j])) {
            if (j != 0) {
                j = lps[j - 1];
            } else {
                ++i;
            }
        }
    }

    // No match found
    free(lps);
    return -1;
}
