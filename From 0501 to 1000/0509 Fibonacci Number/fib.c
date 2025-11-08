/**
 * @file      fib.c
 * @author    Khang Phan (vukhangk@outlook.com)
 * @brief     LeetCode #509: Fibonacci Number
 * @see       <a href="https://leetcode.com/problems/fibonacci-number">Fibonacci Number</a>
 *
 * @note      Utilize the dynamic programming to avoid recursion.
 *            Time Complexity : O(n).
 *            Space Complexity: O(n) or O(1).
 */

// Uses an array to store Fibonacci numbers -> O(n) space
int fib(int n){
    // Base cases
    if (n <= 1) {
        return n;
    }

    // Main loop
    int dp[n + 1];
    dp[0] = 0;
    dp[1] = 1;
    for (int i = 2; i <= n; ++i) {
        dp[i] = dp[i - 1] + dp[i - 2];
    }

    // Return
    return dp[n];
}

// Uses two variables to store only the last two Fibonacci numbers -> O(1) space
int optimizedFib(int n) {
    // Base cases
    if (n <= 1) {
        return n;
    }

    // Main loop
    int prev = 0;
    int curr = 1;
    for (int i = 2; i <= n; ++i) {
        int tmp = prev + curr;
        prev = curr;
        curr = tmp;
    }

    // Return
    return curr;
}
