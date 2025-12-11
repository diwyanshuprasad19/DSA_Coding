Ques:https://takeuforward.org/plus/dsa/problems/kosaraju's-algorithm

sol:https://www.youtube.com/watch?v=R6uoSjZ2imo

Code:

#include <bits/stdc++.h>
using namespace std;

class Solution {
    void dfs1(int node, vector<int>& vis, vector<int> adj[], stack<int>& st) {
        vis[node] = 1;
        for (int it : adj[node]) {
            if (vis[it] == 0) dfs1(it, vis, adj, st);
        }
        st.push(node); // finish time order
    }

    void dfs3(int node, vector<int>& vis, vector<int> adjT[]) {
        vis[node] = 1;
        for (int it : adjT[node]) {
            if (vis[it] == 0) dfs3(it, vis, adjT);
        }
    }

public:
    // Function to find number of strongly connected components in the graph.
    int kosaraju(int V, vector<int> adj[]) {
        vector<int> vis(V, 0);
        stack<int> st;

        // 1) Order by finish time
        for (int i = 0; i < V; i++) {
            if (vis[i] == 0) dfs1(i, vis, adj, st);
        }

        // 2) Build transpose graph
        vector<int> adjT[V];
        for (int i = 0; i < V; i++) {
            for (int it : adj[i]) {
                adjT[it].push_back(i); // reverse edge i -> it  becomes it -> i
            }
        }

        // 3) DFS on transpose in stack order
        fill(vis.begin(), vis.end(), 0);
        int scc = 0;
        while (!st.empty()) {
            int node = st.top(); st.pop();
            if (vis[node] == 0) {
                scc++;
                dfs3(node, vis, adjT);
            }
        }
        return scc;
    }
};

// ----- Demo -----
int main() {
    int V = 5;
    vector<int> adj[5];
    // directed edges: 0->1, 1->2, 2->0 form one SCC; 1->3, 3->4 are singles
    vector<pair<int,int>> edges = {{0,1},{1,2},{2,0},{1,3},{3,4}};
    for (auto &e : edges) adj[e.first].push_back(e.second);

    Solution sol;
    cout << sol.kosaraju(V, adj) << "\n"; // Expected: 3
    return 0;
}



Complexity:

Time: O(V + E) (two DFS traversals + building transpose)

Space: O(V + E) (adjacency lists, transpose, visited, stack)