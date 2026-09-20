Ques:https://takeuforward.org/plus/dsa/problems/kosaraju's-algorithm

sol:https://www.youtube.com/watch?v=R6uoSjZ2imo

only valid for directed graph

Code:

✅ Python Version (Normal Functions Only)
def dfs1(node, vis, adj, stack):
    vis[node] = True
    for it in adj[node]:
        if not vis[it]:
            dfs1(it, vis, adj, stack)
    stack.append(node)  # finish time order


def dfs3(node, vis, adjT):
    vis[node] = True
    for it in adjT[node]:
        if not vis[it]:
            dfs3(it, vis, adjT)


def kosaraju(V, adj):
    vis = [False] * V
    stack = []

    # 1) Order nodes by finish time
    for i in range(V):
        if not vis[i]:
            dfs1(i, vis, adj, stack)

    # 2) Build transpose graph
    adjT = [[] for _ in range(V)]
    for i in range(V):
        for it in adj[i]:
            adjT[it].append(i)  # reverse edge

    # 3) DFS on transpose graph in stack order
    vis = [False] * V
    scc = 0

    while stack:
        node = stack.pop()
        if not vis[node]:
            scc += 1
            dfs3(node, vis, adjT)

    return scc

✅ Example Usage
V = 5
adj = [[] for _ in range(V)]

edges = [(0,1),(1,2),(2,0),(1,3),(3,4)]
for u, v in edges:
    adj[u].append(v)

print(kosaraju(V, adj))  # Output: 3




📌 Output
3

⏱ Time Complexity
O(V + E)


First DFS: O(V + E)

Transpose construction: O(E)

Second DFS: O(V + E)

🧠 Space Complexity
O(V + E)


Adjacency list

Transpose graph

Visited array

Stack