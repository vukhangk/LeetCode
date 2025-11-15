/**
 * @file      rangeAddQueries.c
 * @author    Khang Phan (vukhangk@outlook.com)
 * @brief     LeetCode #2536: Increment Submatrices by One
 * @see       <a href="https://leetcode.com/problems/increment-submatrices-by-one">Increment Submatrices by One</a>
 *
 * @note      Prefix sum on the difference array.
 *            Time Complexity : O(n ^ 2 + Q) - n and Q are number of matrix dimension and queries respectively.
 *            Space Complexity: O(n ^ 2)
 */

int** rangeAddQueries(int n, int** queries, int queriesSize, int* queriesColSize, int* returnSize, int** returnColumnSizes) {
    // Allocate the difference array -> O(n ^ 2) space
    *returnSize = n;
    *returnColumnSizes = (int*)malloc(n * sizeof(int));
    int** diff = (int**)malloc(n * sizeof(int*));
    for (int i = 0; i < n; ++i) {
        (*returnColumnSizes)[i] = n;
        diff[i] = (int*)calloc(n, sizeof(int));
    }
    
    // 1. Compute the difference array -> O(Q) time
    for (int q = 0; q < queriesSize; ++q) {
        // Extract query parameters
        const int r1 = queries[q][0];
        const int c1 = queries[q][1];
        const int r2 = queries[q][2];
        const int c2 = queries[q][3];
        
        // Top left
        ++diff[r1][c1];

        // Top right
        if ((c2 + 1) < n) {
            --diff[r1][c2 + 1];
        }

        // Bottom left
        if ((r2 + 1) < n) {
            --diff[r2 + 1][c1];
        }

        // Bottom right
        if (((r2 + 1) < n) && ((c2 + 1) < n)) {
            ++diff[r2 + 1][c2 + 1];
        }
    }
    
    // 2. Prefix sum -> O(n ^ 2) time
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            // The cell above
            if (i > 0) {
                diff[i][j] += diff[i - 1][j];
            }

            // The cell to the left
            if (j > 0) {
                diff[i][j] += diff[i][j - 1];
            }

            // The top-left diagonal cell
            if ((i > 0) && (j > 0)) {
                diff[i][j] -= diff[i - 1][j - 1];
            }
        }
    }

    // Return
    return diff;
}
