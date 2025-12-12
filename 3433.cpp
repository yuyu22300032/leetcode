/*
3433. Count Mentions Per User


Description:

You are given an integer numberOfUsers representing the total number of users and an array events of size n x 3.

Each events[i] can be either of the following two types:

    Message Event: ["MESSAGE", "timestampi", "mentions_stringi"]
        This event indicates that a set of users was mentioned in a message at timestampi.
        The mentions_stringi string can contain one of the following tokens:
            id<number>: where <number> is an integer in range [0,numberOfUsers - 1]. There can be multiple ids separated by a single whitespace and may contain duplicates. This can mention even the offline users.
            ALL: mentions all users.
            HERE: mentions all online users.
    Offline Event: ["OFFLINE", "timestampi", "idi"]
        This event indicates that the user idi had become offline at timestampi for 60 time units. The user will automatically be online again at time timestampi + 60.

Return an array mentions where mentions[i] represents the number of mentions the user with id i has across all MESSAGE events.

All users are initially online, and if a user goes offline or comes back online, their status change is processed before handling any message event that occurs at the same timestamp.

Note that a user can be mentioned multiple times in a single message event, and each mention should be counted separately.

 

Example 1:

Input: numberOfUsers = 2, events = [["MESSAGE","10","id1 id0"],["OFFLINE","11","0"],["MESSAGE","71","HERE"]]

Output: [2,2]

Explanation:

Initially, all users are online.

At timestamp 10, id1 and id0 are mentioned. mentions = [1,1]

At timestamp 11, id0 goes offline.

At timestamp 71, id0 comes back online and "HERE" is mentioned. mentions = [2,2]

Example 2:

Input: numberOfUsers = 2, events = [["MESSAGE","10","id1 id0"],["OFFLINE","11","0"],["MESSAGE","12","ALL"]]

Output: [2,2]

Explanation:

Initially, all users are online.

At timestamp 10, id1 and id0 are mentioned. mentions = [1,1]

At timestamp 11, id0 goes offline.

At timestamp 12, "ALL" is mentioned. This includes offline users, so both id0 and id1 are mentioned. mentions = [2,2]

Example 3:

Input: numberOfUsers = 2, events = [["OFFLINE","10","0"],["MESSAGE","12","HERE"]]

Output: [0,1]

Explanation:

Initially, all users are online.

At timestamp 10, id0 goes offline.

At timestamp 12, "HERE" is mentioned. Because id0 is still offline, they will not be mentioned. mentions = [0,1]

 

Constraints:

    1 <= numberOfUsers <= 100
    1 <= events.length <= 100
    events[i].length == 3
    events[i][0] will be one of MESSAGE or OFFLINE.
    1 <= int(events[i][1]) <= 105
    The number of id<number> mentions in any "MESSAGE" event is between 1 and 100.
    0 <= <number> <= numberOfUsers - 1
    It is guaranteed that the user id referenced in the OFFLINE event is online at the time the event occurs.

*/

class Solution {
private:
    // For edge case that unsure ordering when offline event and automatic online event has same timestamp
    int convertTimestamp(string& ts) {
        return stoi(ts) * 2;
    }

    int idStringToInt(string& id_str) {
        return stoi(id_str.substr(2));
    }

    void getIDs(string& mentions_string, vector<int>& ids) {
        std::stringstream ss(mentions_string);
        std::string id_str;

        while (std::getline(ss, id_str, ' ')) {
            ids.push_back(idStringToInt(id_str));
        }
    }

    struct StatusChange {
        int id;
        bool goOffline;
        StatusChange(int _id, bool _goOffline) {
            id = _id;
            goOffline = _goOffline;
        }
    };

public:
    vector<int> countMentions(int numberOfUsers, vector<vector<string>>& events) {
        multimap<int, StatusChange> status_events; // <time, StatusChange>
        multiset<int> mention_here_timestamps;
        vector<bool> status(numberOfUsers, true);
        vector<int> output(numberOfUsers, 0);
        int all_cnt = 0;
        for (int i = 0; i < events.size(); i++) {
            if (events[i][0].compare("MESSAGE") == 0) {
                if (events[i][2].compare("ALL") == 0) {
                    all_cnt += 1;
                    continue;
                }
                int timestamp = convertTimestamp(events[i][1]);
                if (events[i][2].compare("HERE") == 0) {
                    mention_here_timestamps.insert(timestamp);
                    continue;
                }
                vector<int> ids;
                getIDs(events[i][2], ids);
                for (int j = 0; j < ids.size(); j++) {
                    output[ids[j]] += 1;
                }
            } else if (events[i][0].compare("OFFLINE") == 0) {
                int timestamp = convertTimestamp(events[i][1]);
                int id = stoi(events[i][2]);
                status_events.insert(pair{timestamp, StatusChange(id, true)});
                status_events.insert(pair{timestamp + 119, StatusChange(id, false)});
            } else {
                // ERROR!!
                cout << "ERROR!!" << endl;
            }
        }
        for (int i = 0; i < output.size(); i++) {
            output[i] += all_cnt;
        }
        multimap<int, StatusChange>::iterator status_it = status_events.begin();
        for (multiset<int>::iterator it = mention_here_timestamps.begin(); it != mention_here_timestamps.end(); it++) {
            while (status_it != status_events.end() && status_it->first <= *it) {
                if (status_it->second.goOffline) {
                    status[status_it->second.id] = false;
                } else {
                    status[status_it->second.id] = true;
                }
                status_it++;
            }
            for (int i = 0; i < output.size(); i++) {
                if (status[i]) {
                    output[i] += 1;
                }
            }
        }
        return output;
    }
};