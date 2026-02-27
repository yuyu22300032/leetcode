/*
3666. Minimum Operations to Equalize Binary String


Description:

You are given a binary string s, and an integer k.

In one operation, you must choose exactly k different indices and flip each '0' to '1' and each '1' to '0'.

Return the minimum number of operations required to make all characters in the string equal to '1'. If it is not possible, return -1.

 

Example 1:

Input: s = "110", k = 1

Output: 1

Explanation:

    There is one '0' in s.
    Since k = 1, we can flip it directly in one operation.

Example 2:

Input: s = "0101", k = 3

Output: 2

Explanation:

One optimal set of operations choosing k = 3 indices in each operation is:

    Operation 1: Flip indices [0, 1, 3]. s changes from "0101" to "1000".
    Operation 2: Flip indices [1, 2, 3]. s changes from "1000" to "1111".

Thus, the minimum number of operations is 2.

Example 3:

Input: s = "101", k = 2

Output: -1

Explanation:

Since k = 2 and s has only one '0', it is impossible to flip exactly k indices to make all '1'. Hence, the answer is -1.

 

Constraints:

    1 <= s.length <= 10​​​​​​​5
    s[i] is either '0' or '1'.
    1 <= k <= s.length


*/

class Solution {
public:
    int minOperations(string s, int k) {
        int n = s.size();
        int zeroCnt = 0;
        for (int i = 0; i < n; i++) {
            if (s[i] == '0') {
                zeroCnt++;
            }
        }
        if (zeroCnt == 0) {
            return 0;
        }
        set<int> unvisited[2];
        for (int i = 0; i <= n; ++i) {
            unvisited[i % 2].insert(i);
        }

        queue<pair<int, int>> search;
        search.push({zeroCnt, 0});
        unvisited[zeroCnt % 2].erase(zeroCnt);

        while (!search.empty()) {
            pair<int, int> cur = search.front();
            search.pop();

            int minZeros = cur.first + k - 2 * min(k, cur.first);
            int maxZeros = cur.first + k - 2 * max(0, k - (n - cur.first));
            int p = minZeros % 2;
            set<int>::iterator it = unvisited[p].lower_bound(minZeros);
            set<int>::iterator it_end = unvisited[p].upper_bound(maxZeros);
            while (it != it_end) {
                if (*it == 0) {
                    return cur.second + 1;
                }
                search.push({*it, cur.second + 1});
                it = unvisited[p].erase(it);
            }
        }
        return -1;
    }
};
