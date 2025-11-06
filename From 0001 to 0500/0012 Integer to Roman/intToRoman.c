/**
 * @file      intToRoman.c
 * @author    Khang Phan (vukhangk@outlook.com)
 * @brief     LeetCode #12: Integer to Roman
 * @see       <a href="https://leetcode.com/problems/integer-to-roman">Integer to Roman</a>
 * 
 * @note      Map the largest part to their corresponding Roman symbols.
 *            E.g., 3894 = 3000 + 800 + 90 + 4.
 *            Time Complexity : O(1).
 *            Space Complexity: O(1).
 */

#include <string.h>

// Store the values
const int value[] = {
    1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1
};

// Store the Roman symbols
const char* symbol[] = {
    "M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"
};

// Number of symbols/values
#define N     (13)

char* intToRoman(int num) {
    // Answer string
    char* ans = (char*)malloc(16 * sizeof(char));
    if (ans == NULL) {
        return NULL;
    }
    ans[0] = '\0';

    // Find the symbol
    for (int i = 0; i < N; ++i) {
        while (num >= value[i]) {
            strcat(ans, symbol[i]);
            num -= value[i];
        }
    }

    // Return
    return ans;
}
