/*
2467. Most Profitable Path in a Tree


Description:

There is an undirected tree with n nodes labeled from 0 to n - 1, rooted at node 0. You are given a 2D integer array edges of length n - 1 where edges[i] = [ai, bi] indicates that there is an edge between nodes ai and bi in the tree.

At every node i, there is a gate. You are also given an array of even integers amount, where amount[i] represents:

    the price needed to open the gate at node i, if amount[i] is negative, or,
    the cash reward obtained on opening the gate at node i, otherwise.

The game goes on as follows:

    Initially, Alice is at node 0 and Bob is at node bob.
    At every second, Alice and Bob each move to an adjacent node. Alice moves towards some leaf node, while Bob moves towards node 0.
    For every node along their path, Alice and Bob either spend money to open the gate at that node, or accept the reward. Note that:
        If the gate is already open, no price will be required, nor will there be any cash reward.
        If Alice and Bob reach the node simultaneously, they share the price/reward for opening the gate there. In other words, if the price to open the gate is c, then both Alice and Bob pay c / 2 each. Similarly, if the reward at the gate is c, both of them receive c / 2 each.
    If Alice reaches a leaf node, she stops moving. Similarly, if Bob reaches node 0, he stops moving. Note that these events are independent of each other.

Return the maximum net income Alice can have if she travels towards the optimal leaf node.

 

Example 1:

Input: edges = [[0,1],[1,2],[1,3],[3,4]], bob = 3, amount = [-2,4,2,-4,6]
Output: 6
Explanation: 
The above diagram represents the given tree. The game goes as follows:
- Alice is initially on node 0, Bob on node 3. They open the gates of their respective nodes.
  Alice's net income is now -2.
- Both Alice and Bob move to node 1. 
  Since they reach here simultaneously, they open the gate together and share the reward.
  Alice's net income becomes -2 + (4 / 2) = 0.
- Alice moves on to node 3. Since Bob already opened its gate, Alice's income remains unchanged.
  Bob moves on to node 0, and stops moving.
- Alice moves on to node 4 and opens the gate there. Her net income becomes 0 + 6 = 6.
Now, neither Alice nor Bob can make any further moves, and the game ends.
It is not possible for Alice to get a higher net income.

Example 2:

Input: edges = [[0,1]], bob = 1, amount = [-7280,2350]
Output: -7280
Explanation: 
Alice follows the path 0->1 whereas Bob follows the path 1->0.
Thus, Alice opens the gate at node 0 only. Hence, her net income is -7280. 

 

Constraints:

    2 <= n <= 105
    edges.length == n - 1
    edges[i].length == 2
    0 <= ai, bi < n
    ai != bi
    edges represents a valid tree.
    1 <= bob < n
    amount.length == n
    amount[i] is an even integer in the range [-104, 104].


*/

class Solution {
public:
    struct bobSearch {
        int node;
        int depth;

        bobSearch(int _node, int _depth)
        : node(_node)
        , depth(_depth) { ; }
    };

    struct aliceSearch {
        int node;
        int depth;
        int income;

        aliceSearch(int _node, int _depth, int _income)
        : node(_node)
        , depth(_depth)
        , income(_income) { ; }
    };

    int mostProfitablePath(vector<vector<int>>& edges, int bob, vector<int>& amount) {
        // find node number
        int n = 0;
        for (int i = 0; i < edges.size(); ++i)
        {
            n = max(n, edges[i][0]);
            n = max(n, edges[i][1]);
        }

        // create node graph
        vector<set<int>> node_graph(n + 1);
        for (int i = 0; i < edges.size(); ++i)
        {
            node_graph[edges[i][0]].insert(edges[i][1]);
            node_graph[edges[i][1]].insert(edges[i][0]);
        }

        // dfs for bob to find optimal path
        vector<int> bob_path;
        {
            vector<bool> visited(n, false);
            stack<bobSearch> bob_search;
            bob_search.push(bobSearch(bob, 0));
            while (! bob_search.empty())
            {
                bobSearch cur = bob_search.top();
                bob_search.pop();
                visited[cur.node] = true;
                while (bob_path.size() > cur.depth)
                {
                    bob_path.pop_back();
                }
                bob_path.push_back(cur.node);
                if (cur.node == 0)
                {
                    break;
                }
                for (set<int>::iterator it = node_graph[cur.node].begin(); it != node_graph[cur.node].end(); ++it)
                {
                    if (! visited[*it])
                    {
                        bob_search.push(bobSearch(*it, cur.depth + 1));
                    }
                }
            }
        }
        
        // bfs for alice to find max income
        int out = INT_MIN;
        {
            vector<bool> visited(n, false);
            queue<aliceSearch> alice_search;
            alice_search.push(aliceSearch(0, 0, 0));
            while (! alice_search.empty())
            {
                aliceSearch cur = alice_search.front();
                alice_search.pop();
                visited[cur.node] = true;
                if ((cur.depth > 0) && (cur.depth - 1 < bob_path.size()))
                {
                    amount[bob_path[cur.depth - 1]] = 0;
                }
                int bob_node = -1;
                if (cur.depth < bob_path.size())
                {
                    bob_node = bob_path[cur.depth];
                }
                int cur_income = cur.income;
                if (cur.node == bob_node)
                {
                    cur_income += amount[cur.node] / 2;
                }
                else
                {
                    cur_income += amount[cur.node];
                }
                bool is_leaf_node = true;
                for (set<int>::iterator it = node_graph[cur.node].begin(); it != node_graph[cur.node].end(); ++it)
                {
                    if (! visited[*it])
                    {
                        is_leaf_node = false;
                        alice_search.push(aliceSearch(*it, cur.depth + 1, cur_income));
                    }
                }
                if (is_leaf_node)
                {
                    out = max(out, cur_income);
                }
            }
        }

        return out;
    }
};
