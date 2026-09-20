🧱 STEP 0: Prerequisites (must know first)

Before heap, make sure you understand:

✅ Arrays

Indexing (i, 2*i+1, 2*i+2)

In-place modification

✅ Binary Tree basics

Parent

Left child

Right child

Height

Levels

👉 If binary tree basics are weak, heap will feel confusing.

🧱 STEP 1: What is a Heap? (MOST IMPORTANT)
Heap is:

A Complete Binary Tree with a heap property

Two types:

Max Heap

Parent ≥ children

Min Heap

Parent ≤ children

Example (Max Heap):

        50
       /  \
     30    40
    /  \
  10   20

🧱 STEP 2: Complete Binary Tree (CRITICAL)

Heap is not any binary tree.

Complete Binary Tree rules:

All levels filled except possibly last

Last level filled left to right

✅ This property allows heap to be stored in an array

🧱 STEP 3: Heap Array Representation (VERY IMPORTANT)

This is where most people struggle.

For index i:

Left child  = 2*i + 1
Right child = 2*i + 2
Parent      = (i - 1) // 2


Example:

Array: [50, 30, 40, 10, 20]

Index:  0   1   2   3   4


Tree:

        50
       /  \
     30    40
    /  \
  10   20


👉 Heap = Tree concept + Array implementation

🧱 STEP 4: Heap Property (RULES)
Max Heap rule:
arr[parent] >= arr[left]
arr[parent] >= arr[right]

Min Heap rule:
arr[parent] <= arr[left]
arr[parent] <= arr[right]


⚠️ Heap is NOT sorted
Only parent-child relation is guaranteed.

🧱 STEP 5: Heapify (CORE OPERATION)

Heapify means:

“Fix the heap property at a given index”

Two types:

Heapify Down (used in heap sort, delete)

Heapify Up (used in insert)

Heapify Down (most important)

Used when:

Root is disturbed

After swap

During heap sort

Logic:

Compare node with children

Swap with largest/smallest

Move down

Repeat

⏱ Time: O(log N)

🧱 STEP 6: Build Heap (WHY O(N)?)

This is where confusion happens.

Idea:

Start from last non-leaf

Heapify downward

for i in range(n//2 - 1, -1, -1):
    heapify(arr, n, i)


Why works:

Leaves already satisfy heap property

Bottom-up fixing is efficient

⏱ Time: O(N)
(important interview fact)

🧱 STEP 7: Heap Operations (MUST KNOW)
Operation	Time
Build Heap	O(N)
Heapify	O(log N)
Insert	O(log N)
Delete Max/Min	O(log N)
Get Max/Min	O(1)