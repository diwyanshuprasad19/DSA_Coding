✅ Default Heap in Python
📦 Module used
import heapq

🔑 Default behavior

Python heap = MIN HEAP

That means:

Parent ≤ Children


Smallest element is always at index 0.


1️⃣ Convert list to heap (FASTEST)
import heapq

arr = [10, 5, 20, 1]
heapq.heapify(arr)
print(arr)

Output
[1, 5, 20, 10]


⏱ Time: O(N)

2️⃣ Insert elements one by one
heap = []
heapq.heappush(heap, 10)
heapq.heappush(heap, 5)
heapq.heappush(heap, 20)
heapq.heappush(heap, 1)

print(heap)


⏱ Time: O(N log N)

🔹 Removing Elements
Pop smallest element
x = heapq.heappop(heap)
print(x)


⏱ Time: O(log N)

🔹 Peek (get min)
print(heap[0])


⏱ Time: O(1)

🔹 Max Heap in Python (IMPORTANT)

Python does NOT provide max heap by default.

Trick: Store negative values
import heapq

arr = [10, 5, 20, 1]
max_heap = [-x for x in arr]
heapq.heapify(max_heap)

print(-max_heap[0])   # max element

📊 Time Complexity Summary
Operation	Time
heapify	O(N)
heappush	O(log N)
heappop	O(log N)
peek	O(1)