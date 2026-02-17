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
    vector<string> generateHours(int ledCnt) {
        switch (ledCnt) {
            case 0:
                return {"0:"};
            case 1:
                return {"1:", "2:", "4:", "8:"};
            case 2:
                return {"3:", "5:", "6:", "9:", "10:"};
            case 3:
                return {"7:", "11:"};
            default:
                break;
        }
        return vector<string>{};
    }
    vector<string> generateMinutes(int ledCnt) {
        switch (ledCnt) {
            case 0:
                return {"00"};
            case 1:
                return {"01", "02", "04", "08", "16", "32"};
            case 2:
                return {"03", "05", "06", "09", "10", "12", "17", "18", "20", "24", "33", "34", "36", "40", "48"};
            case 3:
                return {"07", "11", "13", "14", "19", "21", "22", "25", "26", "28", "35", "37", "38", "41", "42", "44", "49", "50", "52", "56"};
            case 4:
                return {"15", "23", "27", "29", "30", "39", "43", "45", "46", "51", "53", "54", "57", "58"};
            case 5:
                return {"31", "47", "55", "59"};
            default:
                break;
        }
        return vector<string>{};
    }
public:
    vector<string> readBinaryWatch(int turnedOn) {
        vector<string> out;
        for (int hourLedCnt = 0; hourLedCnt <= turnedOn; hourLedCnt++) {
            vector<string> hours = generateHours(hourLedCnt);
            if (hours.size() == 0) {
                break;
            }
            int minuteLedCnt = turnedOn - hourLedCnt;
            vector<string> minutes = generateMinutes(minuteLedCnt);
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
