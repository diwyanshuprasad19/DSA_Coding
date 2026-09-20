https://www.youtube.com/watch?v=V6H1qAeB-l4&t=1s
https://takeuforward.org/data-structure/dijkstras-algorithm-using-priority-queue-g-32/



code solutions-

✅ Function-Based Dijkstra (Python)
import heapq

def dijkstra(V, adj, S):
    """
    Finds the shortest distance from source S to all vertices
    using Dijkstra's Algorithm.
    """

    # Min-heap: (distance, node)
    pq = []

    # Distance array
    dist = [float('inf')] * V

    # Source initialization
    dist[S] = 0
    heapq.heappush(pq, (0, S))

    while pq:
        curr_dist, node = heapq.heappop(pq)

        # Skip if already processed with smaller distance
        if curr_dist > dist[node]:
            continue

        # Relax all adjacent edges
        for neighbor, weight in adj[node]:
            if curr_dist + weight < dist[neighbor]:
                dist[neighbor] = curr_dist + weight
                heapq.heappush(pq, (dist[neighbor], neighbor))

    return dist

🧠 How to Proceed (Step-by-Step Logic)
Step 1: Prepare the graph

Use adjacency list
Each entry → [neighbor, weight]

adj = [
    [[1, 1], [2, 6]],
    [[2, 3], [0, 1]],
    [[1, 3], [0, 6]]
]

Step 2: Initialize

Distance array → ∞

Source distance → 0

Push (0, source) into min-heap

Step 3: Use Min-Heap

Always extract node with minimum distance

Heap ensures optimal greedy choice

Step 4: Relaxation
If current_distance + edge_weight < known_distance:
    update distance
    push to heap


This is the core of Dijkstra.

Step 5: Skip outdated paths
if curr_dist > dist[node]:
    continue


Prevents unnecessary work.

🧪 Sample Driver Code
V = 3
S = 2

adj = [
    [[1, 1], [2, 6]],
    [[2, 3], [0, 1]],
    [[1, 3], [0, 6]]
]

result = dijkstra(V, adj, S)
print(result)

📥 Sample Input
Vertices = 3
Source = 2
Edges:
2 → 1 (3)
2 → 0 (6)
1 → 0 (1)

📤 Sample Output
[4, 3, 0]

Explanation:

2 → 2 = 0

2 → 1 = 3

2 → 1 → 0 = 3 + 1 = 4

⏱️ Time Complexity
O(E log V)

Heap push for each edge relaxation → E log V

Heap pop operations → V log V

💾 Space Complexity
O(V + E)

Distance array → O(V)

Adjacency list → O(E)

Priority queue → O(V)




https://www.youtube.com/watch?v=3dINsjyfooY
explaiantion

📌 Priority Queue (Min/Max Heap) — Operation Costs
Operation	Meaning	Time Complexity
Push / Insert	Add a new element to the heap	O(log N)
Pop / Extract-min	Remove the smallest (or largest) element from the heap	O(log N)
Top / Peek	Get the smallest (or largest) element without removing	O(1)
Size / Empty	Get number of elements / check if empty	O(1)