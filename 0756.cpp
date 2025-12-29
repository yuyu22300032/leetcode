/*
756. Pyramid Transition Matrix


Description:

You are stacking blocks to form a pyramid. Each block has a color, which is represented by a single letter. Each row of blocks contains one less block than the row beneath it and is centered on top.

To make the pyramid aesthetically pleasing, there are only specific triangular patterns that are allowed. A triangular pattern consists of a single block stacked on top of two blocks. The patterns are given as a list of three-letter strings allowed, where the first two characters of a pattern represent the left and right bottom blocks respectively, and the third character is the top block.

    For example, "ABC" represents a triangular pattern with a 'C' block stacked on top of an 'A' (left) and 'B' (right) block. Note that this is different from "BAC" where 'B' is on the left bottom and 'A' is on the right bottom.

You start with a bottom row of blocks bottom, given as a single string, that you must use as the base of the pyramid.

Given bottom and allowed, return true if you can build the pyramid all the way to the top such that every triangular pattern in the pyramid is in allowed, or false otherwise.

 

Example 1:

Input: bottom = "BCD", allowed = ["BCC","CDE","CEA","FFF"]
Output: true
Explanation: The allowed triangular patterns are shown on the right.
Starting from the bottom (level 3), we can build "CE" on level 2 and then build "A" on level 1.
There are three triangular patterns in the pyramid, which are "BCC", "CDE", and "CEA". All are allowed.

Example 2:

Input: bottom = "AAAA", allowed = ["AAB","AAC","BCD","BBE","DEF"]
Output: false
Explanation: The allowed triangular patterns are shown on the right.
Starting from the bottom (level 4), there are multiple ways to build level 3, but trying all the possibilites, you will get always stuck before building level 1.

 

Constraints:

    2 <= bottom.length <= 6
    0 <= allowed.length <= 216
    allowed[i].length == 3
    The letters in all input strings are from the set {'A', 'B', 'C', 'D', 'E', 'F'}.
    All the values of allowed are unique.
*/

class Solution {
    unordered_multimap<string, char> allowed_map_;
    unordered_set<string> checked_;

    bool checkPyramid(string& bottom) {
        if (bottom.size() == 2) {
            return (allowed_map_.count(bottom) > 0);
        }
        if (checked_.count(bottom) > 0) {
            return false;
        }
        vector<string> new_bottoms;
        for (int i = 1; i < bottom.size(); i++) {
            pair<unordered_multimap<string, char>::iterator, unordered_multimap<string, char>::iterator> allows = allowed_map_.equal_range(bottom.substr(i-1, 2));
            if (allows.first == allows.second) {
                return false;
            }
            unordered_multimap<string, char>::iterator it = allows.first;
            int cur_count = new_bottoms.size();
            if (cur_count == 0) {
                while (it != allows.second) {
                    new_bottoms.push_back(string(1, it->second));
                    it++;
                }
            } else {
                it++;
                while (it != allows.second) {
                    for (int j = 0; j < cur_count; j++) {
                        new_bottoms.push_back(new_bottoms[j] + it->second);
                    }
                    it++;
                }
                for (int j = 0; j < cur_count; j++) {
                    new_bottoms[j] += allows.first->second;
                }
            }
        }
        for (int i = 0; i < new_bottoms.size(); i++) {
            if (checkPyramid(new_bottoms[i])) {
                return true;
            }
            checked_.insert(new_bottoms[i]);
        }
        return false;
    }
public:
    bool pyramidTransition(string bottom, vector<string>& allowed) {
        allowed_map_.clear();
        checked_.clear();
        for (int i = 0; i < allowed.size(); i++) {
            allowed_map_.insert(pair<string, char>(allowed[i].substr(0, 2), allowed[i][2]));
        }
        return checkPyramid(bottom);
    }
};

