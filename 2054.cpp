/*
2054. Two Best Non-Overlapping Events


Description:

You are given a 0-indexed 2D integer array of events where events[i] = [startTimei, endTimei, valuei]. The ith event starts at startTimei and ends at endTimei, and if you attend this event, you will receive a value of valuei. You can choose at most two non-overlapping events to attend such that the sum of their values is maximized.

Return this maximum sum.

Note that the start time and end time is inclusive: that is, you cannot attend two events where one of them starts and the other ends at the same time. More specifically, if you attend an event with end time t, the next event must start at or after t + 1.

 

Example 1:

Input: events = [[1,3,2],[4,5,2],[2,4,3]]
Output: 4
Explanation: Choose the green events, 0 and 1 for a sum of 2 + 2 = 4.

Example 2:
Example 1 Diagram

Input: events = [[1,3,2],[4,5,2],[1,5,5]]
Output: 5
Explanation: Choose event 2 for a sum of 5.

Example 3:

Input: events = [[1,5,3],[1,5,1],[6,6,5]]
Output: 8
Explanation: Choose events 0 and 2 for a sum of 3 + 5 = 8.

 

Constraints:

    2 <= events.length <= 105
    events[i].length == 3
    1 <= startTimei <= endTimei <= 109
    1 <= valuei <= 106


*/

class Solution {
public:
    int maxTwoEvents(vector<vector<int>>& events) {
        map<int, int> start_time_map; // max val since time
        for (int i = 0; i < events.size(); i++) {
            start_time_map[events[i][0]] = max(start_time_map[events[i][0]], events[i][2]);
        }
        int max_val = 0;
        for (map<int, int>::reverse_iterator sit = start_time_map.rbegin(); sit != start_time_map.rend(); sit++) {
            max_val = max(max_val, sit->second);
            sit->second = max_val;
        }
        map<int, int> end_time_map; // sort events on end time
        for (int i = 0; i < events.size(); i++) {
            end_time_map[events[i][1]] = max(end_time_map[events[i][1]], events[i][2]);
        }
        // max_val is already max val from single event
        map<int, int>::iterator it = start_time_map.begin();
        for (map<int, int>::iterator eit = end_time_map.begin(); eit != end_time_map.end(); eit++) {
            while (it != start_time_map.end()) {
                if (eit->first < it->first) {
                    max_val = max(max_val, eit->second + it->second);
                    break;
                }
                it++;
            }
        }
        return max_val;
    }
};
