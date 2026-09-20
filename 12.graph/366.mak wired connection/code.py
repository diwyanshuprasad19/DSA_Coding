ques:https://leetcode.com/problems/number-of-operations-to-make-network-connected/

code:

Python Solution (Union by Rank + Path Compression)
class DisjointSet:
    def __init__(self, n):
        self.parent = [i for i in range(n)]
        self.rank = [0] * n

    def find(self, x):
        if self.parent[x] != x:
            self.parent[x] = self.find(self.parent[x])  # path compression
        return self.parent[x]

    def union(self, x, y):
        px = self.find(x)
        py = self.find(y)

        if px == py:
            return

        # union by rank
        if self.rank[px] < self.rank[py]:
            self.parent[px] = py
        elif self.rank[px] > self.rank[py]:
            self.parent[py] = px
        else:
            self.parent[py] = px
            self.rank[px] += 1

Main Function Using Union-Find
def makeConnected(n, connections):
    # Not enough cables
    if len(connections) < n - 1:
        return -1

    ds = DisjointSet(n)

    for u, v in connections:
        ds.union(u, v)

    # Count number of connected components
    components = set()
    for i in range(n):
        components.add(ds.find(i))

    return len(components) - 1

Sample Input (Same as DFS)
n = 4
connections = [
    [0, 1],
    [0, 2],
    [1, 2]
]

print(makeConnected(n, connections))

Output
1

Impossible Case
n = 4
connections = [
    [0, 1],
    [2, 3]
]

print(makeConnected(n, connections))

Output
-1

Complexity Comparison
DFS / BFS

Time: O(N + E)

Space: O(N + E) (graph + recursion stack)

Union-Find (Rank + Path Compression)

Time: O(E · α(N)) ≈ almost O(E)

Space: O(N)

👉 α(N) (inverse Ackermann) is practically constant.


❓ Why we write
components = set()


and NOT

components = {}


even though {} “exists”.

🔴 The core reason

In Python:

{}   ➜ EMPTY DICTIONARY ❌
set() ➜ EMPTY SET ✅

✅ Proof (try this mentally)
print(type({}))


Output:

<class 'dict'>

print(type(set()))


Output:

<class 'set'>
