class Graph:
    def __init__(self, V):
        self.V = V
        self.adj = [[] for _ in range(V)]

    def add_edge(self, u, v):
        self.adj[u].append(v)   # Directed graph

    def dfs(self, node, visited, rec_stack):
        visited[node] = True
        rec_stack[node] = True

        for neighbor in self.adj[node]:
            if not visited[neighbor]:
                if self.dfs(neighbor, visited, rec_stack):
                    return True
            elif rec_stack[neighbor]:
                return True   # Cycle detected

        rec_stack[node] = False
        return False

    def has_cycle(self):
        visited = [False] * self.V
        rec_stack = [False] * self.V

        for i in range(self.V):
            if not visited[i]:
                if self.dfs(i, visited, rec_stack):
                    return True
        return False


# ---- Driver Code ----
g = Graph(4)
g.add_edge(0, 1)
g.add_edge(1, 2)
g.add_edge(2, 3)
g.add_edge(3, 1)   # Creates a cycle

if g.has_cycle():
    print("Cycle detected in the directed graph.")
else:
    print("No cycle found in the directed graph.")


▶️ Sample Input (Edges)
0 → 1
1 → 2
2 → 3
3 → 1

🖨️ Sample Output
Cycle detected in the directed graph.

🔍 Why is a Cycle Detected?
DFS Path
0 → 1 → 2 → 3
        ↑     |
        └─────┘


Node 1 is already in the recursion stack

That means we found a back-edge

Back-edge ⇒ cycle exists

🧠 Key Idea (Very Important)
Array	Purpose
visited	Node already processed
rec_stack	Node currently in DFS path

👉 If we visit a node already in rec_stack, we found a cycle

⏱️ Time Complexity
O(V + E)
Explanation:

Each node is visited once → O(V)

Each edge is checked once → O(E)

Total = O(V + E)

💾 Space Complexity
O(V)
Why?

visited array → O(V)

rec_stack array → O(V)

DFS recursion stack → O(V) (worst case)

Total = O(V)