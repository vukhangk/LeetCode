/**
 * @file      letterCombinations.c
 * @author    Khang Phan (vukhangk@outlook.com)
 * @brief     LeetCode #17: Letter Combinations of a Phone Number
 * @see       <a href="https://leetcode.com/problems/letter-combinations-of-a-phone-number">Letter Combinations of a Phone Number</a>
 *
 * @note      Backtracking with recursion.
 *            Time Complexity : O(4^N * N) - N is the number of letters per digit.
 *            Space Complexity: O(4^N * N + N).
 */

#include <string.h>

const char** letterMap = (const char*[]) {
    "",
    "",
    "abc",
    "def",
    "ghi",
    "jkl",
    "mno",
    "pqrs",
    "tuv",
    "wxyz"
};

void backtrack(char* digits, int index,
               char* currCombination, char** result, int* returnSize) {
    // If the current combination is complete
    if (digits[index] == '\0') {
        result[*returnSize] = (char*)malloc((index + 1) * sizeof(char));
        currCombination[index] = '\0';
        strcpy(result[*returnSize], currCombination);
        ++(*returnSize);
        return;
    }

    // Explore each letter for the current digit
    const char* letters = letterMap[digits[index] - '0'];
    for (int i = 0; letters[i] != '\0'; ++i) {
        currCombination[index] = letters[i];
        backtrack(digits, index + 1, currCombination, result, returnSize);
    }
}

char** letterCombinations(char* digits, int* returnSize) {
    // Initialize return size
    *returnSize = 0;

    // Edge case
    if (digits[0] == '\0') {
        return NULL;
    }

    // Calculate maximum combinations
    int maxCombinations = 1;
    for (char* d = digits; *d != '\0'; ++d) {
        int digit = *d - '0';
        int lettersCount = 0;
        while (letterMap[digit][lettersCount] != '\0') {
            ++lettersCount;
        }
        maxCombinations *= lettersCount;
    }
    
    // Start backtracking
    char** ans = (char**)malloc(maxCombinations * sizeof(char*));
    char* currCombination = (char*)malloc((strlen(digits) + 1) * sizeof(char));
    backtrack(digits, 0, currCombination, ans, returnSize);
    free(currCombination);

    // Return
    return ans;
}
