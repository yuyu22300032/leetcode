/*
1344. Angle Between Hands of a Clock


Description:

Given two numbers, hour and minutes, return the smaller angle (in degrees) formed between the hour and the minute hand.

Answers within 10-5 of the actual value will be accepted as correct.

 

Example 1:

Input: hour = 12, minutes = 30
Output: 165

Example 2:

Input: hour = 3, minutes = 30
Output: 75

Example 3:

Input: hour = 3, minutes = 15
Output: 7.5

 

Constraints:

    1 <= hour <= 12
    0 <= minutes <= 59


*/

class Solution {
public:
    double angleClock(int hour, int minutes) {
        double minPos = minutes * 6;
        if (hour == 12) {
            hour = 0;
        }
        double hourPos = (hour * 60 + minutes) * 0.5;
        double p1 = 0;
        double p2 = 0;
        if (hourPos > minPos) {
            p1 = hourPos;
            p2 = minPos;
        } else {
            p1 = minPos;
            p2 = hourPos;
        }
        double out = p1 - p2;
        if (out > 180) {
            out = 360 - out;
        }
        return out;
    }
};
