/**
 * @file      isValid.c
 * @author    Khang Phan (vukhangk@outlook.com)
 * @brief     LeetCode #20: Valid Parentheses
 * @see       <a href="https://leetcode.com/problems/valid-parentheses">Valid Parentheses</a>
 *
 * @note      Use a stack to keep track of opening parentheses.
 *            Time Complexity : O(L) - L is the length of the input string.
 *            Space Complexity: O(L).
 */

#include <stdbool.h>
#include <string.h>

bool isOpening(char c) {
    return ((c == '(') || (c == '[') || (c == '{'));
}

bool isMatching(char opening, char closing) {
    return ((opening == '(' && closing == ')') ||
            (opening == '[' && closing == ']') ||
            (opening == '{' && closing == '}'));
}

bool isValid(char* s) {
    char stack[strlen(s)];

    // Main loop
    int sp = -1; // Stack pointer
    char* c = s; // Current character
    while (*c) {
        if (isOpening(*c)) {
            stack[++sp] = *c;
        } else {
            if (sp == -1) {
                // There is no opening parentheses before
                return false;
            }
            if (!isMatching(stack[sp], *c)) {
                return false;
            }
            --sp;
        }
        ++c;
    }

    // Return
    return (sp == -1);
}
