Python Code (BFS / Kahn’s Algorithm)
from collections import deque

class Graph:
    def __init__(self, V):
        self.V = V
        self.adj = [[] for _ in range(V)]

    def add_edge(self, u, v):
        self.adj[u].append(v)   # Directed edge

    def has_cycle_bfs(self):
        indegree = [0] * self.V

        # Step 1: Calculate indegree of each node
        for u in range(self.V):
            for v in self.adj[u]:
                indegree[v] += 1

        # Step 2: Add nodes with indegree 0 to queue
        queue = deque()
        for i in range(self.V):
            if indegree[i] == 0:
                queue.append(i)

        visited_count = 0

        # Step 3: BFS traversal
        while queue:
            node = queue.popleft()
            visited_count += 1

            for neighbor in self.adj[node]:
                indegree[neighbor] -= 1
                if indegree[neighbor] == 0:
                    queue.append(neighbor)

        # Step 4: Cycle detection
        return visited_count != self.V

▶️ Sample Input (Graph Edges)
g = Graph(4)
g.add_edge(0, 1)
g.add_edge(1, 2)
g.add_edge(2, 3)
g.add_edge(3, 1)   # Creates a cycle

if g.has_cycle_bfs():
    print("Cycle detected in the directed graph.")
else:
    print("No cycle found in the directed graph.")

🖨️ Sample Output
Cycle detected in the directed graph.

🔍 Why Cycle Is Detected?
Initial Indegree Table
Node	Indegree
0	0
1	2
2	1
3	1

Only node 0 has indegree 0

BFS stops after removing 0

Nodes {1,2,3} remain → cycle exists

⏱️ Time Complexity
O(V + E)

Reason:

Each node processed once → O(V)

Each edge processed once → O(E)

💾 Space Complexity
O(V)

Reason:

indegree array → O(V)

queue → O(V)