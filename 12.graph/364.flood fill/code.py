Ques:https://leetcode.com/problems/flood-fill/description/


Yes ✅ — your Flood Fill solution here is using Depth-First Search (DFS).
Both DFS and BFS work for Flood Fill.
DFS is preferred because it is simpler, uses less auxiliary data structures, and does not require shortest-path guarantees.

Code:

✅ Approach: Depth-First Search (DFS)

Start from (sr, sc)

Move in 4 directions (up, down, left, right)

Recolor only pixels with the same original color

Recolored pixels act as visited

🧾 Code (with Sample Input & Output):

✅ Approach

Depth-First Search (DFS)

Start DFS from (sr, sc)

Move in 4 directions (up, down, left, right)

Recolor only pixels matching the original color

Recolored pixels automatically act as visited

Code:


def func(r,c,image,pc,n,m,old_color):
    
    if r<0 or r>=n or c<0 or c>=m:
        return
    if image[r][c]!=old_color:
        return
    image[r][c]=pc
    func(r+1,c,image,pc,n,m,old_color)
    func(r-1,c,image,pc,n,m,old_color)
    func(r,c+1,image,pc,n,m,old_color)
    func(r,c-1,image,pc,n,m,old_color)


def solv(r,c,image,pc):
    n=len(image)
    m=len(image[0])
    if image[r][c] == pc:
        return
    old_color = image[r][c]
    
    func(r,c,image,pc,n,m,old_color)
    
    

image = [
    [1, 1, 1],
    [1, 1, 0],
    [1, 0, 1]
]

sc=1
sr=1

pc=2

solv(sr,sc,image,pc)
for i in range(len(image)):
    for j in range(len(image[i])):
        print(image[i][j])
    
    print()

▶️ Sample Output
[2, 2, 2]
[2, 2, 0]
[2, 0, 1]

⏱️ Time Complexity
O(N × M)


In the worst case, every pixel is visited once.

🧠 Space Complexity
O(N × M)


Due to recursion stack in the worst case (entire grid filled)