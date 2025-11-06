/**
 * @file      romanToInt.c
 * @author    Khang Phan (vukhangk@outlook.com)
 * @brief     LeetCode #13: Roman to Integer
 * @see       <a href="https://leetcode.com/problems/roman-to-integer">Roman to Integer</a>
 * 
 * @note      Iterate from the back of the string.
 *            Time Complexity : O(L) - L is the length of the input string.
 *            Space Complexity: O(1).
 */

int getValue(char c) {
    switch (c) {
        case 'I': return    1;
        case 'V': return    5;
        case 'X': return   10;
        case 'L': return   50;
        case 'C': return  100;
        case 'D': return  500;
        case 'M': return 1000;
        default: return 0;
    }
}

int romanToInt(char* s) {
    // Iterate from the back
    int n = strlen(s);
    int ans = getValue(s[n - 1]);
    int prev = ans; // Character on the right
    for (int i = n - 2; i >= 0; --i) {
        int curr = getValue(s[i]);
        if (prev > curr) {
            ans -= curr;
        } else {
            ans += curr;
        }
        prev = curr;
    }

    // Return
    return ans;
}
