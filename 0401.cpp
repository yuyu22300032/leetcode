/*
401. Binary Watch


Description:

A binary watch has 4 LEDs on the top to represent the hours (0-11), and 6 LEDs on the bottom to represent the minutes (0-59). Each LED represents a zero or one, with the least significant bit on the right.

    For example, the below binary watch reads "4:51".

Given an integer turnedOn which represents the number of LEDs that are currently on (ignoring the PM), return all possible times the watch could represent. You may return the answer in any order.

The hour must not contain a leading zero.

    For example, "01:00" is not valid. It should be "1:00".

The minute must consist of two digits and may contain a leading zero.

    For example, "10:2" is not valid. It should be "10:02".

 

Example 1:

Input: turnedOn = 1
Output: ["0:01","0:02","0:04","0:08","0:16","0:32","1:00","2:00","4:00","8:00"]

Example 2:

Input: turnedOn = 9
Output: []

 

Constraints:

    0 <= turnedOn <= 10


*/

class Solution {
    vector<string> generateValues(int targetBits, bool isMinute) {
        vector<string> result;
        int maxVal = 0;
        if (isMinute) {
            maxVal = 59;
        } else {
            maxVal = 11;
        }
        for (int i = 0; i <= maxVal; ++i) {
            if (__builtin_popcount(i) == targetBits) {
                string s = to_string(i);
                if (isMinute) {
                    result.push_back(i < 10 ? "0" + s : s);
                } else {
                    result.push_back(s + ":");
                }
            }
        }
        return result;
    }
public:
    vector<string> readBinaryWatch(int turnedOn) {
        vector<string> out;
        for (int hourLedCnt = 0; hourLedCnt <= turnedOn; hourLedCnt++) {
            vector<string> hours = generateValues(hourLedCnt, false);
            if (hours.size() == 0) {
                break;
            }
            vector<string> minutes = generateValues(turnedOn - hourLedCnt, true);
            if (minutes.size() == 0) {
                continue;
            }
            for (int j = 0; j < hours.size(); j++) {
                for (int k = 0; k < minutes.size(); k++) {
                    out.push_back(hours[j] + minutes[k]);
                }
            }
        }
        return out;
    }
};
