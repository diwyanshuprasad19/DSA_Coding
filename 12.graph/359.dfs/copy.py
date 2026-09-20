class Graph:
    def __init__(self, V):
        self.V = V
        self.adj = [[] for _ in range(V)]

    def add_edge(self, u, v):
        self.adj[u].append(v)
        self.adj[v].append(u)   # Undirected graph

    def dfs_util(self, node, visited):
        visited[node] = True
        print(node, end=" ")

        for neighbor in self.adj[node]:
            if not visited[neighbor]:
                self.dfs_util(neighbor, visited)

    def dfs(self, start):
        visited = [False] * self.V
        print("DFS (Recursive) Traversal:", end=" ")
        self.dfs_util(start, visited)
        print()


# ---- Driver Code ----
g = Graph(6)
g.add_edge(0, 1)
g.add_edge(0, 2)
g.add_edge(1, 3)
g.add_edge(1, 4)
g.add_edge(2, 5)

g.dfs(0)

▶️ Sample Input (Graph Edges)
0 -- 1
0 -- 2
1 -- 3
1 -- 4
2 -- 5

🖨️ Sample Output
DFS (Recursive) Traversal: 0 1 3 4 2 5

🔍 Why this Output? (Step-by-Step)
Graph Structure
        0
      /   \
     1     2
    / \     \
   3   4     5

DFS Traversal (Depth First)
Start → 0
Go deep → 1
Go deep → 3 (dead end)
Backtrack → 1
Go deep → 4 (dead end)
Backtrack → 0
Go deep → 2
Go deep → 5


➡️ Output Order:

0 → 1 → 3 → 4 → 2 → 5

⏱️ Time Complexity
O(V + E)
Explanation:

Each vertex is visited once → O(V)

Each edge is explored once → O(E)

Total = O(V + E)

💾 Space Complexity
O(V)
Why?

Visited array → O(V)

Recursive call stack (worst case: linear graph) → O(V)

Total = O(V)

📌 BFS vs DFS (Quick Interview Comparison)
Feature	BFS	DFS
Data structure	Queue	Recursion / Stack
Traversal style	Level-wise	Depth-wise
Space (worst)	O(V)	O(V)
Best use	Shortest path	Cycle detection
