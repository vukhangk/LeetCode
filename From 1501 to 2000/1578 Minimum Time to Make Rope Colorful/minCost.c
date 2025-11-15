/**
 * @file      minCost.c
 * @author    Khang Phan (vukhangk@outlook.com)
 * @brief     LeetCode #1578: Minimum Time to Make Rope Colorful
 * @see       <a href="https://leetcode.com/problems/minimum-time-to-make-rope-colorful">Minimum Time to Make Rope Colorful</a>
 *
 * @note      Brute force.
 *            Time Complexity : O(L) - L is the length of the string.
 *            Space Complexity: O(1).
 */

#define MAX(A, B) ((A > B) ? A : B)

int minCost(char* colors, int* neededTime, int neededTimeSize) {
    // Output
    int ans = 0;

    // To calculate the time of consecutive balloons
    char* prevColor = colors;
    int totalTime = *neededTime;
    int maxTime = *neededTime;

    // Current pointer
    char* currColor = colors + 1;
    int* currTime = neededTime + 1;

    // Main loop
    while (currColor < colors + neededTimeSize) {
        if (*prevColor == *currColor) {
            totalTime += *currTime;
            maxTime = MAX(maxTime, *currTime);
        } else {
            ans += totalTime - maxTime;
            prevColor = currColor;
            totalTime = *currTime;
            maxTime = *currTime;
        }
        ++currColor;
        ++currTime;
    }

    // Handle the very last consecutive balloon
    ans += totalTime - maxTime;

    // Return
    return ans;
}
