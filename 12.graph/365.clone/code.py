ques:https://leetcode.com/problems/clone-graph/description/

code:
class Node:
    def __init__(self, val=0, neighbors=None):
        self.val = val
        self.neighbors = neighbors if neighbors is not None else []


class Solution:
    def cloneGraph(self, node: 'Node') -> 'Node':
        if not node:
            return None

        visited = {}  # original_node -> cloned_node -dictionary

        def dfs(curr):
            if curr in visited:
                return visited[curr]

            # Create copy of current node
            copy = Node(curr.val)
            visited[curr] = copy

            # Clone neighbors
            for nei in curr.neighbors:
                copy.neighbors.append(dfs(nei))

            return copy

        return dfs(node)

▶️ Sample Input (Graph Construction)

Graph:

1 -- 2
|    |
4 -- 3

# Create graph nodes
n1 = Node(1)
n2 = Node(2)
n3 = Node(3)
n4 = Node(4)

# Connect neighbors
n1.neighbors = [n2, n4]
n2.neighbors = [n1, n3]
n3.neighbors = [n2, n4]
n4.neighbors = [n1, n3]

# Clone graph
sol = Solution()
cloned = sol.cloneGraph(n1)

▶️ Sample Output (Adjacency List Print)
def print_graph(node):
    visited = set()

    def dfs(n):
        if n in visited:
            return
        visited.add(n)
        print(f"Node {n.val}: {[x.val for x in n.neighbors]}")
        for x in n.neighbors:
            dfs(x)

    dfs(node)


print_graph(cloned)

✅ Output
Node 1: [2, 4]
Node 2: [1, 3]
Node 3: [2, 4]
Node 4: [1, 3]


✔ Structure matches original
✔ Nodes are new objects (deep copy)

⏱️ Time Complexity
O(N + E)


N = number of nodes

E = number of edges

Each node and edge is visited once