/*
67. Add Binary


Description:

Given two binary strings a and b, return their sum as a binary string.

 

Example 1:

Input: a = "11", b = "1"
Output: "100"

Example 2:

Input: a = "1010", b = "1011"
Output: "10101"

 

Constraints:

    1 <= a.length, b.length <= 104
    a and b consist only of '0' or '1' characters.
    Each string does not contain leading zeros except for the zero itself.


*/

class Solution {
public:
    string addBinary(string a, string b) {
        string res;
        bool carry = false;
        if (a.size() < b.size()) {
            a.insert(0, b.size() - a.size(), '0');
        } else if (a.size() > b.size()) {
            b.insert(0, a.size() - b.size(), '0');
        }
        for (int i = a.size() - 1; i >= 0; i--) {
            if (carry) {
                if (a[i] == '1' && b[i] == '1') {
                    res.insert(0, 1, '1');
                } else if (a[i] == '0' && b[i] == '0') {
                    res.insert(0, 1, '1');
                    carry = false;
                } else {
                    res.insert(0, 1, '0');
                }
            } else {
                if (a[i] == '1' && b[i] == '1') {
                    res.insert(0, 1, '0');
                    carry = true;
                } else if (a[i] == '0' && b[i] == '0') {
                    res.insert(0, 1, '0');
                } else {
                    res.insert(0, 1, '1');
                }
            }
        }
        if (carry) {
            res.insert(0, 1, '1');
        }
        return res;
    }
};
