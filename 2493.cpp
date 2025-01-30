/*
2493. Divide Nodes Into the Maximum Number of Groups


Description:

You are given a positive integer n representing the number of nodes in an undirected graph. The nodes are labeled from 1 to n.

You are also given a 2D integer array edges, where edges[i] = [ai, bi] indicates that there is a bidirectional edge between nodes ai and bi. Notice that the given graph may be disconnected.

Divide the nodes of the graph into m groups (1-indexed) such that:

    Each node in the graph belongs to exactly one group.
    For every pair of nodes in the graph that are connected by an edge [ai, bi], if ai belongs to the group with index x, and bi belongs to the group with index y, then |y - x| = 1.

Return the maximum number of groups (i.e., maximum m) into which you can divide the nodes. Return -1 if it is impossible to group the nodes with the given conditions.

 

Example 1:

Input: n = 6, edges = [[1,2],[1,4],[1,5],[2,6],[2,3],[4,6]]
Output: 4
Explanation: As shown in the image we:
- Add node 5 to the first group.
- Add node 1 to the second group.
- Add nodes 2 and 4 to the third group.
- Add nodes 3 and 6 to the fourth group.
We can see that every edge is satisfied.
It can be shown that that if we create a fifth group and move any node from the third or fourth group to it, at least on of the edges will not be satisfied.

Example 2:

Input: n = 3, edges = [[1,2],[2,3],[3,1]]
Output: -1
Explanation: If we add node 1 to the first group, node 2 to the second group, and node 3 to the third group to satisfy the first two edges, we can see that the third edge will not be satisfied.
It can be shown that no grouping is possible.

 

Constraints:

    1 <= n <= 500
    1 <= edges.length <= 104
    edges[i].length == 2
    1 <= ai, bi <= n
    ai != bi
    There is at most one edge between any pair of vertices.


*/

class Solution {
public:
    int getRoot(int node, vector<int> &source)
    {
        while (source[node] != -1)
        {
            node = source[node];
        }
        return node;
    }

    int getDepth(vector<vector<int>> &graph, int root, int n)
    {
        queue<int> search;
        vector<int> depth(n + 1, -1);
        search.push(root);
        depth[root] = 0;
        int cur_depth = 0;

        while (! search.empty())
        {
            int cur_cnt = search.size();
            for (int i = 0; i < cur_cnt; i++)
            {
                int cur = search.front();
                search.pop();
                for (int j = 0; j < graph[cur].size(); ++j)
                {
                    if (depth[graph[cur][j]] == -1)
                    {
                        depth[graph[cur][j]] = cur_depth + 1;
                        search.push(graph[cur][j]);
                    }
                    else if (depth[graph[cur][j]] == cur_depth)
                    {
                        return -1;
                    }
                }
            }
            cur_depth++;
        }
        return cur_depth;
    }

    int magnificentSets(int n, vector<vector<int>> &edges) {
        vector<vector<int>> graph(n + 1);
        vector<int> source(n + 1, -1);
        vector<int> depth(n + 1, 0);
        for (int i = 0; i < edges.size(); ++i)
        {
            graph[edges[i][0]].push_back(edges[i][1]);
            graph[edges[i][1]].push_back(edges[i][0]);
            int source1 = getRoot(edges[i][0], source);
            int source2 = getRoot(edges[i][1], source);
            if (source1 == source2)
            {
                continue;
            }

            if (depth[source1] == depth[source2])
            {
                depth[source1] += 1;
            }
            else if (depth[source1] < depth[source2])
            {
                swap(source1, source2);
            }

            source[source2] = source1;
        }

        vector<int> depths(n + 1, 0);
        for (int cur = 1; cur <= n; cur++)
        {
            int cur_depth = getDepth(graph, cur, n);
            if (cur_depth == -1)
            {
                return -1;
            }
            int root = getRoot(cur, source);
            depths[root] = max(depths[root], cur_depth);
        }

        int out = 0;
        for (int i = 0; i < depths.size(); ++i)
        {
            out += depths[i];
        }
        return out;
    }    
};

