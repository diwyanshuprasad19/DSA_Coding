Ques:https://www.geeksforgeeks.org/dsa/minimum-steps-reach-target-knight/

Code:
from collections import deque

dr=[-2,-2,-1,1,2,2,1,-1]
dc=[-1,1,2,2,-1,1,-2,-2]

def solv(start,end,n):
    queue=deque()
    x1,y1=start[0],start[1]
    x2,y2=end[0],end[1]
    queue.append([x1,y1,0])
    
    visited = [[False]*n for _ in range(n)]
    visited[x1][y1] = True 
    
    while queue:
        t = queue.popleft()
        if t[0]==x2 and t[1]==y2:
            return t[2]
        
        for i in range(8):
            nr,nc=t[0]+dr[i],t[1]+dc[i]
            if 0<=nc<n and 0<=nr<n and visited[nr][nc] == False:
                visited[nr][nc]=True
                queue.append([nr,nc,t[2]+1])
    
    return -1
            
        
        

start = [1,1]
end=[29,29]
dis =solv(start,end,30)
print(dis)

✅ Sample Output
20

⏱️ Time & Space Complexity
Time Complexity
O(N²)


Each cell is visited once, BFS explores max N × N cells.

Space Complexity
O(N²)


Distance matrix + queue storage.