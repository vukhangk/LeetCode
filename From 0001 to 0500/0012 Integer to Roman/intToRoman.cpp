/**
 * @file      intToRoman.cpp
 * @author    Khang Phan (vukhangk@outlook.com)
 * @brief     LeetCode #12: Integer to Roman
 * @see       <a href="https://leetcode.com/problems/integer-to-roman">Integer to Roman</a>
 * 
 * @note      Map the largest part to their corresponding Roman symbols.
 *            E.g., 3894 = 3000 + 800 + 90 + 4.
 *            Time Complexity : O(1).
 *            Space Complexity: O(1).
 */

#include <string>
#include <vector>

using namespace std;

class Solution {
private:
    // Store the values
    const vector<int> value = {
        1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1
    };
    
    // Store the Roman symbols
    const vector<string> symbol = {
        "M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"
    };

public:
    string intToRoman(int num) {
        // Find the symbol
        string ans = "";
        for (int i = 0; i < value.size(); ++i) {
            while (num >= value[i]) {
                ans += symbol[i];
                num -= value[i];
            }
        }

        // Return
        return ans;
    }
};
