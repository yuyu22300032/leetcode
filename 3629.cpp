/*
3629. Minimum Jumps to Reach End via Prime Teleportation


Description:

You are given an integer array nums of length n.

You start at index 0, and your goal is to reach index n - 1.

From any index i, you may perform one of the following operations:

    Adjacent Step: Jump to index i + 1 or i - 1, if the index is within bounds.
    Prime Teleportation: If nums[i] is a p, you may instantly jump to any index j != i such that nums[j] % p == 0.

Return the minimum number of jumps required to reach index n - 1.

 

Example 1:

Input: nums = [1,2,4,6]

Output: 2

Explanation:

One optimal sequence of jumps is:

    Start at index i = 0. Take an adjacent step to index 1.
    At index i = 1, nums[1] = 2 is a prime number. Therefore, we teleport to index i = 3 as nums[3] = 6 is divisible by 2.

Thus, the answer is 2.

Example 2:

Input: nums = [2,3,4,7,9]

Output: 2

Explanation:

One optimal sequence of jumps is:

    Start at index i = 0. Take an adjacent step to index i = 1.
    At index i = 1, nums[1] = 3 is a prime number. Therefore, we teleport to index i = 4 since nums[4] = 9 is divisible by 3.

Thus, the answer is 2.

Example 3:

Input: nums = [4,6,5,8]

Output: 3

Explanation:

    Since no teleportation is possible, we move through 0 → 1 → 2 → 3. Thus, the answer is 3.

 

Constraints:

    1 <= n == nums.length <= 105
    1 <= nums[i] <= 106

 
*/

class Solution {
    bool isPrime(int n) {
        if (n == 1) {
            return false;
        }
        if (n == 2) {
            return true;
        }
        if (n % 2 == 0) {
            return false;
        }
        for (int i = 3; i * i <= n; i += 2) {
            if (n % i == 0) {
                return false;
            }
        }
        return true;
    }
public:
    int minJumps(vector<int>& nums) {
        unordered_map<int, vector<int>> jumps; // prime, jump to idxs
        for (int i = 0; i < nums.size(); i++) {
            int cur = nums[i];
            for (int j = 2; j * j <= cur; j++) {
                if (cur % j == 0) {
                    jumps[j].push_back(i);
                    do {
                        cur /= j;
                    } while (cur % j == 0);
                }
            }
            if (cur > 1) {
                jumps[cur].push_back(i);
            }
        }
        queue<pair<int, int>> searching; // idx, steps
        vector<bool> visited(nums.size(), false);
        searching.push({0, 0});
        visited[0] = true;
        while (! searching.empty()) {
            pair<int, int> cur = searching.front();
            searching.pop();
            if (cur.first + 1 == nums.size()) {
                return cur.second;
            }
            if (cur.first < nums.size() && !visited[cur.first + 1]) {
                searching.push({cur.first + 1, cur.second + 1});
                visited[cur.first + 1] = true;
            }
            if (cur.first > 0 && !visited[cur.first - 1]) {
                searching.push({cur.first - 1, cur.second + 1});
                visited[cur.first - 1] = true;
            }
            unordered_map<int, vector<int>>::iterator it = jumps.find(nums[cur.first]);
            if (it == jumps.end()) {
                continue;
            }
            for (int i = 0; i < it->second.size(); i++) {
                if (!visited[it->second[i]]) {
                    searching.push({it->second[i], cur.second + 1});
                    visited[it->second[i]] = true;
                }
            }
            jumps.erase(it);
        }
        return -1;
    }
};
