Question:https://www.geeksforgeeks.org/rat-in-a-maze/

🐀 Rat in a Maze — Python Implementation
🔹 Problem Recap

Given an n x n matrix of 0s and 1s

1 → path is allowed

0 → blocked

Rat starts at (0,0) and must reach (n-1,n-1)

Moves allowed: Up, Down, Left, Right

Find all possible paths in lexicographical order

# Directions: Down, Left, Right, Up
dir = "DLRU"
dr = [1, 0, 0, -1]
dc = [0, -1, 1, 0]

# Check if a cell is valid (inside the maze and open)
def isValid(r, c, n, maze):
    return r >= 0 and c >= 0 and r < n and c < n and maze[r][c] == 1

# Function to find all valid paths
def findPath(r, c, maze, path, res):
    n = len(maze)

    # If destination is reached, store the path
    if r == n - 1 and c == n - 1:
        res.append("".join(path))
        return
    
    # Mark current cell as visited
    maze[r][c] = 0

    for i in range(4):
        nr, nc = r + dr[i], c + dc[i]
        if isValid(nr, nc, n, maze):
            path.append(dir[i])
            
            # Move to the next cell recursively
            findPath(nr, nc, maze, path, res)
            
            # Backtrack
            path.pop()
    
    # Unmark current cell
    maze[r][c] = 1

# Function to find all paths and return them
def ratInMaze(maze):
    result = []
    n = len(maze)
    path = []

    if maze[0][0] == 1 and maze[n - 1][n - 1] == 1:
        
        # Start from (0,0)
        findPath(0, 0, maze, path, result)

    # Sort results lexicographically
    result.sort()
        
    return result

if __name__ == "__main__":
    maze = [
        [1, 0, 0, 0],
        [1, 1, 0, 1],
        [1, 1, 0, 0],
        [0, 1, 1, 1]
    ]

    result = ratInMaze(maze)

    for p in result:
        print(p, end=" ")

⏱️ Time & Space Complexity
Time Complexity
O(4^(n*n))


Each cell can move in 4 directions

Worst-case explores all possible paths

Space Complexity
O(n*n)


visited matrix → n x n

Recursive call stack → max n*n depth

📥 Sample Input
n = 4
m = [
    [1, 0, 0, 0],
    [1, 1, 0, 1],
    [1, 1, 0, 0],
    [0, 1, 1, 1]
]

📤 Sample Output
['DDRDRR', 'DRDDRR']

🚨 The Issue Your Version Causes
❌ You mark the destination cell as visited before checking it
maze[i][j] = 0   # marked visited

if i == n-1 and j == n-1:
    result.append("".join(path))
    return

🧠 What Actually Goes Wrong (Step-by-Step)
Scenario

There are multiple valid paths reaching the destination (n-1, n-1).

What your code does:

First path reaches destination

You mark destination as 0

You return immediately

❌ Destination cell is never restored to 1

Other recursive paths:

Reach near destination

Try to move into (n-1, n-1)

❌ isvalid() returns False

Those valid paths are silently skipped