/**
 * @file      groupAnagrams.cpp
 * @author    Khang Phan (vukhangk@outlook.com)
 * @brief     LeetCode #49: Group Anagrams
 * @see       <a href="https://leetcode.com/problems/group-anagrams">Group Anagrams</a>
 *
 * @note      Hash map with key is the sorted string.
 *            Time Complexity : O(N * L * log(L)) - N is the number of strings, L is the maximum length of a string.
 *            Space Complexity: O(N * L).
 */

#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        // Hash map to store sorted strings as keys -> O(N * L * log(L)) time
        unordered_map<string, vector<string>> map;
        for (const string& str : strs) {
            string sortedStr = str;
            sort(sortedStr.begin(), sortedStr.end());
            map[sortedStr].push_back(str);
        }

        // Get the answer -> O(N * L) time
        vector<vector<string>> ans;
        for (const auto& p : map) {
            ans.push_back(p.second);
        }

        // Return
        return ans;
    }
};
