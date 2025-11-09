/**
 * @file      countValidSelections.c
 * @author    Khang Phan (vukhangk@outlook.com)
 * @brief     LeetCode #3354: Make Array Elements Equal to Zero
 * @see       <a href="https://leetcode.com/problems/make-array-elements-equal-to-zero">Make Array Elements Equal to Zero</a>
 *
 * @note      The sum of the left and right subarrays must be equal (2 valid directions) or differ by 1 (1 valid direction).
 *            Time Complexity : O(n) - n is the number of elements in the array.
 *            Space Complexity: O(1).
 */

int countValidSelections(int* nums, int numsSize) {
    int sum = 0;
    for (int i = 0; i < numsSize; ++i) {
        sum += nums[i];
    }

    // Main loop
    int ans = 0;
    int sumLeft = 0;
    for (int i = 0; i < numsSize; ++i) {
        int sumRight = sum - sumLeft;
        if (nums[i] == 0) {
            if (sumLeft == sumRight) {
                ans += 2;
            } else if ((sumLeft == sumRight + 1) || (sumLeft == sumRight - 1)) {
                ans += 1;
            }
        } else {
            sumLeft += nums[i];
        }
    }

    // Return
    return ans;
}
