/*
684. Redundant Connection


Description:

In this problem, a tree is an undirected graph that is connected and has no cycles.

You are given a graph that started as a tree with n nodes labeled from 1 to n, with one additional edge added. The added edge has two different vertices chosen from 1 to n, and was not an edge that already existed. The graph is represented as an array edges of length n where edges[i] = [ai, bi] indicates that there is an edge between nodes ai and bi in the graph.

Return an edge that can be removed so that the resulting graph is a tree of n nodes. If there are multiple answers, return the answer that occurs last in the input.

 

Example 1:

Input: edges = [[1,2],[1,3],[2,3]]
Output: [2,3]

Example 2:

Input: edges = [[1,2],[2,3],[3,4],[1,4],[1,5]]
Output: [1,4]

 

Constraints:

    n == edges.length
    3 <= n <= 1000
    edges[i].length == 2
    1 <= ai < bi <= edges.length
    ai != bi
    There are no repeated edges.
    The given graph is connected.


*/

class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        list<set<int>> groups;
        for(int i = 0; i < edges.size(); ++i)
        {
            list<set<int>>::iterator it1 = groups.end();
            list<set<int>>::iterator it2 = groups.end();
            for (list<set<int>>::iterator it = groups.begin(); it != groups.end(); ++it)
            {
                if (it->count(edges[i][0]) > 0)
                {
                    it1 = it;
                    if (it2 != groups.end())
                    {
                        break;
                    }
                }
                if (it->count(edges[i][1]) > 0)
                {
                    it2 = it;
                    if (it1 != groups.end())
                    {
                        break;
                    }
                }
            }
            if (it1 == groups.end() && it2 == groups.end())
            {
                set<int> new_group;
                new_group.insert(edges[i][0]);
                new_group.insert(edges[i][1]);
                groups.push_back(new_group);
                continue;
            }
            if (it1 == groups.end())
            {
                it2->insert(edges[i][0]);
                continue;
            }
            if (it2 == groups.end())
            {
                it1->insert(edges[i][1]);
                continue;
            }
            if (it1 == it2)
            {
                return edges[i];
            }
            it1->insert(it2->begin(), it2->end());
            groups.erase(it2);
        }
        return vector<int>();
    }
};

