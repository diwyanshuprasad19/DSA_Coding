Python Code (DFS)
class Graph:
    def __init__(self, V):
        self.V = V
        self.adj = [[] for _ in range(V)]

    def add_edge(self, u, v):
        self.adj[u].append(v)
        self.adj[v].append(u)   # Undirected graph

    def dfs(self, node, visited, parent):
        visited[node] = True

        for neighbor in self.adj[node]:
            if not visited[neighbor]:
                if self.dfs(neighbor, visited, node):
                    return True
            elif neighbor != parent:
                return True   # Cycle detected

        return False

    def has_cycle_dfs(self):
        visited = [False] * self.V

        for i in range(self.V):
            if not visited[i]:
                if self.dfs(i, visited, -1):
                    return True
        return False

▶️ Sample Input (Undirected Graph)
g = Graph(4)
g.add_edge(0, 1)
g.add_edge(1, 2)
g.add_edge(2, 3)
g.add_edge(3, 1)   # Cycle

if g.has_cycle_dfs():
    print("Cycle detected (DFS)")
else:
    print("No cycle (DFS)")

🖨️ Sample Output
Cycle detected (DFS)

⏱️ Time & Space Complexity (DFS)
Metric	Complexity
Time	O(V + E)
Space	O(V)

visited array → O(V)

Recursion stack → O(V)


4️⃣ DFS Traversal (Real-Time Walkthrough)
Start DFS from node 0
visited = [False, False, False, False]
dfs(0, visited, -1)

🔹 At node 0
visited = [True, False, False, False]
parent = -1
neighbors = [1]

Visit neighbor 1
if not visited[1]:
    dfs(1, visited, 0)

🔹 At node 1
visited = [True, True, False, False]
parent = 0
neighbors = [0, 2, 3]


Neighbor 0 → visited but it is parent → OK, ignore

Neighbor 2 → not visited → DFS deeper

🔹 At node 2
visited = [True, True, True, False]
parent = 1
neighbors = [1, 3]


Neighbor 1 → visited but parent → OK

Neighbor 3 → not visited → DFS deeper

🔹 At node 3
visited = [True, True, True, True]
parent = 2
neighbors = [2, 1]


Neighbor 2 → visited but parent → OK

Neighbor 1 → visited AND NOT parent

🚨 THIS LINE DETECTS THE CYCLE
elif neighbor != parent:
    return True

Why?

Node 1 is already visited

Node 1 is not the parent

That means we found an alternate path

Alternate path ⇒ CYCLE