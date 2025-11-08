/**
 * @file      removeOuterParentheses.c
 * @author    Khang Phan (vukhangk@outlook.com)
 * @brief     LeetCode #1021: Remove Outermost Parentheses
 * @see       <a href="https://leetcode.com/problems/remove-outermost-parentheses">Remove Outermost Parentheses</a>
 *
 * @note      A counter increments for opening parenthesis and decrements for closing ones.
 *            Time Complexity : O(L) - L is the length of the string.
 *            Space Complexity: O(L).
 */

char* removeOuterParentheses(char* s) {
    int count = 0;
    char* ans = (char*)malloc(strlen(s) + 1);
    int idx = 0;

    // Main loop
    char* c = s;
    while (*c) {
        // Outermost parentheses -> count = 0
        if ((*c == '(') && (count++ > 0)) {
            ans[idx++] = *c;
        } else if ((*c == ')') && (--count > 0)) {
            ans[idx++] = *c;
        }
        ++c;
    }
    ans[idx] = '\0';    

    // Return
    return ans;
}
