Ques:https://leetcode.com/problems/critical-connections-in-a-network/description/

Sol:https://www.youtube.com/watch?v=qrAub5z8FeA

this is greedy approach

Code:

#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    int timer = 1;

    void dfs(int node, int parent, vector<int> &vis,
             vector<int> adj[], int tin[], int low[],
             vector<vector<int>> &bridges) {
        vis[node] = 1;
        tin[node] = low[node] = timer;
        timer++;

        for (auto it : adj[node]) {
            if (it == parent) continue; // skip the parent edge
            if (vis[it] == 0) {
                dfs(it, node, vis, adj, tin, low, bridges);
                low[node] = min(low[node], low[it]);

                // Bridge condition
                if (low[it] > tin[node]) {
                    bridges.push_back({it, node});
                }
            } else {
                // back-edge
                low[node] = min(low[node], low[it]);
            }
        }
    }

public:
    vector<vector<int>> criticalConnections(int n, vector<vector<int>> &connections) {
        vector<int> adj[n];
        for (auto it : connections) {
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }

        vector<int> vis(n, 0);
        int tin[n];
        int low[n];
        vector<vector<int>> bridges;

        dfs(0, -1, vis, adj, tin, low, bridges);

        return bridges;
    }
};

int main() {
    int n = 5;
    vector<vector<int>> connections = {
        {0, 1}, {1, 2}, {2, 0}, {1, 3}, {3, 4}
    };

    Solution obj;
    vector<vector<int>> ans = obj.criticalConnections(n, connections);

    cout << "Bridges:\n";
    for (auto &b : ans) {
        cout << b[0] << " " << b[1] << "\n";
    }

    return 0;
}
Sample Input
ini
Copy
Edit
n = 5
connections = [
    {0,1}, {1,2}, {2,0}, {1,3}, {3,4}
]
Sample Output
makefile
Copy
Edit
Bridges:
3 4
1 3



Time Complexity
O(V + E) → DFS visits each vertex and edge once.

Space Complexity
O(V + E) → adjacency list + auxiliary arrays (tin, low, vis) + recursion stack.

