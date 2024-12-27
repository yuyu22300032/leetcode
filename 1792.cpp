/*
1792. Maximum Average Pass Ratio


Description:

There is a school that has classes of students and each class will be having a final exam. You are given a 2D integer array classes, where classes[i] = [passi, totali]. You know beforehand that in the ith class, there are totali total students, but only passi number of students will pass the exam.

You are also given an integer extraStudents. There are another extraStudents brilliant students that are guaranteed to pass the exam of any class they are assigned to. You want to assign each of the extraStudents students to a class in a way that maximizes the average pass ratio across all the classes.

The pass ratio of a class is equal to the number of students of the class that will pass the exam divided by the total number of students of the class. The average pass ratio is the sum of pass ratios of all the classes divided by the number of the classes.

Return the maximum possible average pass ratio after assigning the extraStudents students. Answers within 10-5 of the actual answer will be accepted.

 

Example 1:

Input: classes = [[1,2],[3,5],[2,2]], extraStudents = 2
Output: 0.78333
Explanation: You can assign the two extra students to the first class. The average pass ratio will be equal to (3/4 + 3/5 + 2/2) / 3 = 0.78333.

Example 2:

Input: classes = [[2,4],[3,9],[4,5],[2,10]], extraStudents = 4
Output: 0.53485


 

Constraints:

    1 <= classes.length <= 105
    classes[i].length == 2
    1 <= passi <= totali <= 105
    1 <= extraStudents <= 105

*/

class Solution {
public:
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
        multimap<double, pair<int, int>> heap;
        for (size_t i = 0; i < classes.size(); ++i)
        {
            if (classes[i][0] == classes[i][1])
            {
                continue;
            }
            double diff = static_cast<double>(classes[i][0] + 1) / (classes[i][1] + 1) - (static_cast<double>(classes[i][0]) / classes[i][1]);
            heap.insert(pair<double, pair<int, int>>(diff, pair<int, int>(classes[i][0], classes[i][1])));
        }
        if (heap.size() == 0)
        {
            return 1.0;
        }
        for (int i = 0; i < extraStudents; ++i)
        {
            multimap<double, pair<int, int>>::iterator it = heap.end();
            --it;
            int new_pass = it->second.first + 1;
            int new_cnt = it->second.second + 1;
            double diff = (static_cast<double>(new_pass + 1) / (new_cnt + 1)) - (static_cast<double>(new_pass) / new_cnt);
            heap.erase(it);
            heap.insert(pair<double, pair<int, int>>(diff, pair<int, int>(new_pass, new_cnt)));
        }
        double out = classes.size() - heap.size();
        for (multimap<double, pair<int, int>>::iterator it = heap.begin(); it != heap.end(); ++it)
        {
            out += static_cast<double>(it->second.first) / it->second.second;
        }
        out /= classes.size();
        return out;
    }
};


