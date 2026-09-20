🧩 Python Code (BFS)
from collections import deque

class Graph:
    def __init__(self, V):
        self.V = V
        self.adj = [[] for _ in range(V)]

    def add_edge(self, u, v):
        self.adj[u].append(v)
        self.adj[v].append(u)   # Undirected graph

    def has_cycle_bfs(self):
        visited = [False] * self.V

        for start in range(self.V):
            if not visited[start]:
                queue = deque()
                queue.append((start, -1))
                visited[start] = True

                while queue:
                    node, parent = queue.popleft()

                    for neighbor in self.adj[node]:
                        if not visited[neighbor]:
                            visited[neighbor] = True
                            queue.append((neighbor, node))
                        elif neighbor != parent:
                            return True   # Cycle detected

        return False

▶️ Sample Input (Same Graph)
g = Graph(4)
g.add_edge(0, 1)
g.add_edge(1, 2)
g.add_edge(2, 3)
g.add_edge(3, 1)   # Cycle

if g.has_cycle_bfs():
    print("Cycle detected (BFS)")
else:
    print("No cycle (BFS)")

🖨️ Sample Output
Cycle detected (BFS)

⏱️ Time & Space Complexity (BFS)
Metric	Complexity
Time	O(V + E)
Space	O(V)

visited array → O(V)

Queue → O(V)