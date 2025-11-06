/**
 * @file      isValid.cpp
 * @author    Khang Phan (vukhangk@outlook.com)
 * @brief     LeetCode #20: Valid Parentheses
 * @see       <a href="https://leetcode.com/problems/valid-parentheses">Valid Parentheses</a>
 *
 * @note      Use a stack to keep track of opening parentheses.
 *            Time Complexity : O(L) - L is the length of the input string.
 *            Space Complexity: O(L).
 */

#include <string>
#include <stack>

using namespace std;

class Solution {
private: // Helper functions
    bool isOpening(char c) {
        return ((c == '(') || (c == '[') || (c == '{'));
    }

    bool isMatching(char opening, char closing) {
        return ((opening == '(' && closing == ')') ||
                (opening == '[' && closing == ']') ||
                (opening == '{' && closing == '}'));
    }

public:
    bool isValid(string s) {
        stack<char> stackChar;
        for (const auto& c : s) {
            if (isOpening(c)) {
                stackChar.push(c);
            } else {
                if (stackChar.empty()) {
                    // There is no opening parentheses before
                    return false;
                }

                if (!isMatching(stackChar.top(), c)) {
                    return false;
                }
                stackChar.pop();
            }
        }

        // Return
        return (stackChar.empty());
    }
};
