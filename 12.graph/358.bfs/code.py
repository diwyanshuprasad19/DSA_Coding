from collections import deque

class Graph:
    def __init__(self, V):
        self.V = V
        self.adj = [[] for _ in range(V)]

    def add_edge(self, u, v):
        self.adj[u].append(v)
        self.adj[v].append(u)   # Undirected graph

    def bfs(self, start):
        visited = [False] * self.V
        queue = deque()

        queue.append(start)
        visited[start] = True

        print("BFS Traversal:", end=" ")

        while queue:
            node = queue.popleft()
            print(node, end=" ")

            for neighbor in self.adj[node]:
                if not visited[neighbor]:
                    visited[neighbor] = True
                    queue.append(neighbor)

        print()


# ---- Driver Code ----
g = Graph(6)
g.add_edge(0, 1)
g.add_edge(0, 2)
g.add_edge(1, 3)
g.add_edge(1, 4)
g.add_edge(2, 5)

g.bfs(0)



🔎 Why this is the output (Step-by-Step)
Graph Structure
        0
      /   \
     1     2
    / \     \
   3   4     5

BFS starts from node 0
Step	Queue	Visited Node	Output
1	[0]	0	0
2	[1, 2]	1	0 1
3	[2, 3, 4]	2	0 1 2
4	[3, 4, 5]	3	0 1 2 3
5	[4, 5]	4	0 1 2 3 4
6	[5]	5	0 1 2 3 4 5


Time Complexity of BFS
Time Complexity = O(V + E)

BFS does two main things:

1️⃣ Visits every vertex once

Each node is marked visited only one time

Cost → O(V)

2️⃣ Traverses every edge once

For an undirected graph, each edge is checked from both ends

For a directed graph, each edge is checked once

Cost → O(E)

✅ Total Time
O(V) + O(E) = O(V + E)

🔎 Example

If:

V = 6 (nodes)

E = 5 (edges)

BFS will:

Visit 6 nodes

Process 5 edges

➡️ Linear work → very efficient

💾 Space Complexity of BFS
Space Complexity = O(V)
Why?

BFS uses extra memory for:

1️⃣ visited array

Stores a boolean for each vertex

Size → O(V)

2️⃣ Queue

In worst case, queue can hold all vertices

Size → O(V)

✅ Total Space
O(V) + O(V) = O(V)