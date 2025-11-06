/**
 * @file      twoSum.c
 * @author    Khang Phan (vukhangk@outlook.com)
 * @brief     LeetCode #1: Two Sum
 * @see       <a href="https://leetcode.com/problems/two-sum">Two Sum</a>
 *
 * @note      Utilize two pointers to find the two numbers that add up to the target.
 *            Time Complexity : O(N * log(N)) - Due to sorting.
 *            Space Complexity: O(N).
 */

#include <stdlib.h>

// Structure to store value and its original index
typedef struct {
    int Value;
    int Index;
} Element_t;

// Comparator function for qsort()
int comparator(const void* a, const void* b) {
    return ((Element_t*)a)->Value - ((Element_t*)b)->Value;
}

int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
    // Create the answer array
    int* ans = (int*)malloc(2 * sizeof(int));
    *returnSize = 2;

    // Store original indices -> O(N) time
    Element_t* arr = (Element_t*)malloc(numsSize * sizeof(Element_t));
    for (int i = 0; i < numsSize; i++) {
        arr[i].Value = nums[i];
        arr[i].Index = i;
    }

    // Sort -> O(N * log(N)) time
    qsort(arr, numsSize, sizeof(Element_t), comparator);

    // Two pointers -> O(N) time
    int left = 0;
    int right = numsSize - 1;
    while (left < right) {
        int sum = arr[left].Value + arr[right].Value;
        if (sum == target) {
            ans[0] = arr[left].Index;
            ans[1] = arr[right].Index;
            free(arr);
            arr = NULL;
            return ans;
        } else if (sum < target) {
            ++left;
        } else {
            --right;
        }
    }

    // Not found
    free(arr);
    free(ans);
    arr = NULL;
    ans = NULL;
    *returnSize = 0;
    return NULL;
}
