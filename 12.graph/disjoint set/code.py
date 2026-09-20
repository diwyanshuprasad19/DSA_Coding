sol:https://www.youtube.com/watch?v=aBxjDBC4M1U

code:


class DisjointSet:
    def __init__(self, n):
        # nodes are from 1 to n
        self.rank = [0] * (n + 1)
        self.par = [i for i in range(n + 1)]

    def findUPar(self, v):
        if self.par[v] != v:
            self.par[v] = self.findUPar(self.par[v])  # path compression
        return self.par[v]

    def unionByRank(self, u, v):
        pu = self.findUPar(u)
        pv = self.findUPar(v)

        if pu == pv:
            return

        if self.rank[pu] < self.rank[pv]:
            self.par[pu] = pv
        elif self.rank[pv] < self.rank[pu]:
            self.par[pv] = pu
        else:
            self.par[pv] = pu
            self.rank[pu] += 1

ds = DisjointSet(7)

ds.unionByRank(1, 2)
ds.unionByRank(2, 3)
ds.unionByRank(4, 5)
ds.unionByRank(6, 7)
ds.unionByRank(5, 6)

# Check if 3 and 7 are in same set
if ds.findUPar(3) == ds.findUPar(7):
    print("Same")
else:
    print("Not same")

ds.unionByRank(3, 7)

if ds.findUPar(3) == ds.findUPar(7):
    print("Same")
else:
    print("Not same")


✅ Sample Output
Not same
Same

🧠 Explanation of Output
Before unionByRank(3, 7)

Sets are:

{1, 2, 3}
{4, 5, 6, 7}


So → Not same

After unionByRank(3, 7)

All nodes are connected:

{1, 2, 3, 4, 5, 6, 7}


So → Same

⏱️ Time Complexity
findUPar
O(α(N))

unionByRank
O(α(N))


Where α(N) = Inverse Ackermann function
➡️ grows so slowly that it is almost constant time

🧠 Space Complexity
O(N)


parent array

rank array


by rank only make it work

time and space compelxity:


1. Time Complexity Analysis
The code implements Disjoint Set Union (DSU) / Union-Find using Union by Rank and Path Compression.

findUPar(int node) (Find Operation):

Uses Path Compression, making it O(α(n)), where α(n) is the Inverse Ackermann function, which is almost constant O(1) for practical inputs.
unionByRank(int u, int v) (Union Operation):

Uses Union by Rank, ensuring that the depth of any tree is at most log(n).
The time complexity per union operation is O(α(n)).
Overall Complexity:

For m operations (including both find and union), the total time complexity is O(m * α(n)), which is almost O(m) in real-world cases.
✅ Final Time Complexity: O(m * α(n)) ≈ O(m) (amortized)

2. Space Complexity Analysis
parent array: O(n) (stores parent of each node)
rank array: O(n) (stores rank of each node)
Additional Variables: O(1)
✅ Final Space Complexity: O(n)

Operation	                     Worst-Case Time Complexity	    Amortized Time Complexity
Find (with Path Compression)	     O(log n)	                    O(α(n)) ≈ O(1)
Union (with Rank)	                 O(log n)	                    O(α(n)) ≈ O(1)
Total (for m operations)	         O(m log n)	                   O(m α(n)) ≈ O(m)

