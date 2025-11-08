/**
 * @file      mySqrt.c
 * @author    Khang Phan (vukhangk@outlook.com)
 * @brief     LeetCode #69: Sqrt(x)
 * @see       <a href="https://leetcode.com/problems/sqrtx">Sqrt(x)</a>
 *
 * @note      Binary search.
 *            Time Complexity : O(log(n)) - n is the input number.
 *            Space Complexity: O(1).
 */

int mySqrt(int x) {
    // Edge case
    if (x == 0) {
        return 0;
    }

    // Main loop
    int left = 1;
    int right = x;
    int ans = 1; // sqrt(x) is at least 1 for x >= 1
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (mid <= (x / mid)) {
            ans = mid;
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    // Return
    return ans;
}
