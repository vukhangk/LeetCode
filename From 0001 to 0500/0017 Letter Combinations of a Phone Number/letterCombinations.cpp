/**
 * @file      letterCombinations.cpp
 * @author    Khang Phan (vukhangk@outlook.com)
 * @brief     LeetCode #17: Letter Combinations of a Phone Number
 * @see       <a href="https://leetcode.com/problems/letter-combinations-of-a-phone-number">Letter Combinations of a Phone Number</a>
 *
 * @note      Backtracking with recursion.
 *            Time Complexity : O(4^N * N) - N is the number of digits.
 *            Space Complexity: O(4^N * N + N).
 */

#include <vector>
#include <string>

using namespace std;

class Solution {
private:
    const vector<string> letterMap = {
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

    void backtrack(const string& digits, int index,
                   string& currCombination, vector<string>& result) {
        // If the current combination is complete
        if (index == digits.size()) {
            result.push_back(currCombination);
            return;
        }

        // Get the letters corresponding to the current digit
        const string& letters = letterMap[digits[index] - '0'];

        // Explore each letter for the current digit
        for (const char& letter : letters) {
            currCombination.push_back(letter);
            backtrack(digits, index + 1, currCombination, result);
            currCombination.pop_back();
        }
    }

public:
    vector<string> letterCombinations(string digits) {
        // Start backtracking
        vector<string> ans;
        string currCombination;
        backtrack(digits, 0, currCombination, ans);

        // Return
        return ans;
    }
};
