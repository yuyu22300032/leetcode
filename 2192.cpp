/*
2192. All Ancestors of a Node in a Directed Acyclic Graph


Description:

You are given a positive integer n representing the number of nodes of a Directed Acyclic Graph (DAG). The nodes are numbered from 0 to n - 1 (inclusive).

You are also given a 2D integer array edges, where edges[i] = [fromi, toi] denotes that there is a unidirectional edge from fromi to toi in the graph.

Return a list answer, where answer[i] is the list of ancestors of the ith node, sorted in ascending order.

A node u is an ancestor of another node v if u can reach v via a set of edges.


Example 1:
Input: n = 8, edgeList = [[0,3],[0,4],[1,3],[2,4],[2,7],[3,5],[3,6],[3,7],[4,6]]
Output: [[],[],[],[0,1],[0,2],[0,1,3],[0,1,2,3,4],[0,1,2,3]]

Example 2:
Input: n = 5, edgeList = [[0,1],[0,2],[0,3],[0,4],[1,2],[1,3],[1,4],[2,3],[2,4],[3,4]]
Output: [[],[0],[0,1],[0,1,2],[0,1,2,3]]


Constraints:

    1 <= n <= 1000
    0 <= edges.length <= min(2000, n * (n - 1) / 2)
    edges[i].length == 2
    0 <= fromi, toi <= n - 1
    fromi != toi
    There are no duplicate edges.
    The graph is directed and acyclic.
*/

class Solution {
public:
    void dfs(vector<vector<int>>& graph, int new_node, int cur, vector<vector<int>>& out, vector<bool>& searched) {
        searched[cur] = true;
        for (vector<int>::iterator it = graph[cur].begin(); it != graph[cur].end(); it++) {
            if (! searched[*it]) {
                out[*it].push_back(new_node);
                dfs(graph, new_node, *it, out, searched);
            }
        }
    }
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        vector<vector<int>> out(n);
        vector<vector<int>> graph(n);
        for (vector<vector<int>>::iterator it = edges.begin(); it != edges.end(); it++)
        {
            graph[(*it)[0]].push_back((*it)[1]);
        }

        for (int i = 0; i < n; i++)
        {
            vector<bool> searched(n, false);
            dfs(graph, i, i, out, searched);
        }

        return out;
    }
};
