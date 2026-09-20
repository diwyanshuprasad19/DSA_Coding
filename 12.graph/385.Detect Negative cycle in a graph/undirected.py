Why This Is True (Key Insight)

Consider any undirected edge:

u ——(-5)—— v


Because the edge is undirected, you can traverse it both ways:

u → v → u


Total cycle weight:

-5 + -5 = -10   (negative)


➡️ That is a valid negative cycle.

Therefore
Undirected Graph Rules
Condition	Negative Cycle Exists?
Any edge weight < 0	✅ YES
All edge weights ≥ 0	❌ NO
So “How to find negative cycle” in undirected graph?
Algorithm (Trivial & Correct)
def has_negative_cycle_undirected(edges):
    for u, v, w in edges:
        if w < 0:
            return True
    return False

Example
Input
edges = [
    (0, 1, 4),
    (1, 2, -3),   # negative edge
    (2, 3, 2)
]

Output
True

Reason

Cycle:

1 → 2 → 1
Weight = -3 + -3 = -6
