Ques: https://leetcode.com/problems/find-median-from-data-stream/description/
Ques: https://www.geeksforgeeks.org/dsa/median-of-stream-of-integers-running-integers/


Code:

Python (Function-Based, Heapq)
import heapq

# max heap (invert values)
left = []   # max heap
right = []  # min heap

def insert_num(x):
    # Step 1: Insert
    if not left or x <= -left[0]:
        heapq.heappush(left, -x)
    else:
        heapq.heappush(right, x)

    # Step 2: Balance
    if len(left) > len(right) + 1:
        heapq.heappush(right, -heapq.heappop(left))
    elif len(right) > len(left):
        heapq.heappush(left, -heapq.heappop(right))

def get_median():
    if len(left) == len(right):
        return (-left[0] + right[0]) / 2
    return -left[0]

🧪 Sample Input & Output
Input Stream
[5, 15, 1, 3]

Step-by-Step Medians
Insert	Median
5	5
15	10
1	5
3	4
Test Code
nums = [5, 15, 1, 3]
for n in nums:
    insert_num(n)
    print("Inserted:", n, "Median:", get_median())

Output
Inserted: 5 Median: 5
Inserted: 15 Median: 10.0
Inserted: 1 Median: 5
Inserted: 3 Median: 4

⏱️ Time & Space Complexity
Time Complexity
Operation	Complexity
insert_num	O(log N)
get_median	O(1)
Space Complexity
Component	Complexity
Two Heaps	O(N)