Ques:https://leetcode.com/problems/critical-connections-in-a-network/description/

Sol:https://www.youtube.com/watch?v=qrAub5z8FeA

this is greedy approach

Code:

Python Code — Critical Connections (Bridges)
def dfs(node, parent, adj, vis, tin, low, timer, bridges):
    vis[node] = True
    tin[node] = low[node] = timer[0]
    timer[0] += 1

    for it in adj[node]:
        if it == parent:
            continue

        if not vis[it]:
            dfs(it, node, adj, vis, tin, low, timer, bridges)
            low[node] = min(low[node], low[it])

            # Bridge condition
            if low[it] > tin[node]:
                bridges.append([node, it])
        else:
            # back edge
            low[node] = min(low[node], tin[it])


def criticalConnections(n, connections):
    adj = [[] for _ in range(n)]
    for u, v in connections:
        adj[u].append(v)
        adj[v].append(u)

    vis = [False] * n
    tin = [-1] * n
    low = [-1] * n
    timer = [1]
    bridges = []

    # In case the graph is disconnected
    for i in range(n):
        if not vis[i]:
            dfs(i, -1, adj, vis, tin, low, timer, bridges)

    return bridges

▶️ Sample Input
n = 5
connections = [
    [0, 1],
    [1, 2],
    [2, 0],
    [1, 3],
    [3, 4]
]

print(criticalConnections(n, connections))

✅ Output
[[1, 3], [3, 4]]

Explanation

Removing 1–3 disconnects node 3

Removing 3–4 disconnects node 4

Cycle (0–1–2) has no bridges

⏱ Time Complexity
O(V + E)


Single DFS traversal

Each edge processed once

🧠 Space Complexity
O(V + E)


Adjacency list

tin, low, visited arrays

Recursion stack (DFS)

