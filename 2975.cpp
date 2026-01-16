/*
2975. Maximum Square Area by Removing Fences From a Field


Description:

There is a large (m - 1) x (n - 1) rectangular field with corners at (1, 1) and (m, n) containing some horizontal and vertical fences given in arrays hFences and vFences respectively.

Horizontal fences are from the coordinates (hFences[i], 1) to (hFences[i], n) and vertical fences are from the coordinates (1, vFences[i]) to (m, vFences[i]).

Return the maximum area of a square field that can be formed by removing some fences (possibly none) or -1 if it is impossible to make a square field.

Since the answer may be large, return it modulo 109 + 7.

Note: The field is surrounded by two horizontal fences from the coordinates (1, 1) to (1, n) and (m, 1) to (m, n) and two vertical fences from the coordinates (1, 1) to (m, 1) and (1, n) to (m, n). These fences cannot be removed.

 

Example 1:

Input: m = 4, n = 3, hFences = [2,3], vFences = [2]
Output: 4
Explanation: Removing the horizontal fence at 2 and the vertical fence at 2 will give a square field of area 4.

Example 2:

Input: m = 6, n = 7, hFences = [2], vFences = [4]
Output: -1
Explanation: It can be proved that there is no way to create a square field by removing fences.

 

Constraints:

    3 <= m, n <= 109
    1 <= hFences.length, vFences.length <= 600
    1 < hFences[i] < m
    1 < vFences[i] < n
    hFences and vFences are unique.


*/

class Solution {
    void getLengths(int m, vector<int>& fences, unordered_set<int>& lengths) {
        sort(fences.begin(), fences.end());
        int bound = 1;
        lengths.insert(m - 1);
        for (int i = 0; i < fences.size(); i++) {
            lengths.insert(fences[i] - 1);
            lengths.insert(m - fences[i]);
            for (int j = i + 1; j < fences.size(); j++) {
                lengths.insert(fences[j] - fences[i]);
            }
        }
    }
public:
    int maximizeSquareArea(int m, int n, vector<int>& hFences, vector<int>& vFences) {
        unordered_set<int> h_lens;
        unordered_set<int> v_lens;
        getLengths(m, hFences, h_lens);
        getLengths(n, vFences, v_lens);
        int square = 0;
        for (unordered_set<int>::iterator it = h_lens.begin(); it != h_lens.end(); it++) {
            if (v_lens.count(*it) > 0) {
                square = max(square, *it);
            }
        }
        if (square == 0) {
            return -1;
        }
        int out = (long long)(square) * square % 1000000007;
        return out;
    }
};
