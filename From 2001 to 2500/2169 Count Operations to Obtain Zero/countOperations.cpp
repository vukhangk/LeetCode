/**
 * @file      countOperations.cpp
 * @author    Khang Phan (vukhangk@outlook.com)
 * @brief     LeetCode #2169: Count Operations to Obtain Zero
 * @see       <a href="https://leetcode.com/problems/count-operations-to-obtain-zero">Count Operations to Obtain Zero</a>
 *
 * @note      The number of subtractions to make A from greater than B to less than B is A / B, swap them and repeat.
 *            Time Complexity : O(log(min(A, B))) - A and B are the inputs.
 *            Space Complexity: O(1).
 */

#include <algorithm>
#include <utility>

using namespace std;

class Solution {
public:
    int countOperations(int num1, int num2) {
        int a = max(num1, num2);
        int b = min(num1, num2);

        // Main loop
        int ans = 0;
        while ((a != 0) && (b != 0)) {
            ans += a / b;
            swap(a, b);
            b %= a;
        }

        // Return
        return ans;
    }
};
