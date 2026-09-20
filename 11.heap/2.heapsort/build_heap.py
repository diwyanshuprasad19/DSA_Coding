🔗 YouTube Video:
https://www.youtube.com/watch?v=kU4KBD4NFtw

⏱ Time Complexity:
Build Heap: O(N)

N - 1 times, for each element it will run and call heapify, which takes O(logN)

Total: O(N log N)


Build Heap Code (Python – Max Heap)
def heapify(arr, n, i):
    largest = i
    left = 2 * i + 1
    right = 2 * i + 2

    if left < n and arr[left] > arr[largest]:
        largest = left

    if right < n and arr[right] > arr[largest]:
        largest = right

    if largest != i:
        arr[i], arr[largest] = arr[largest], arr[i]
        heapify(arr, n, largest)


def build_heap(arr):
    n = len(arr)

    # start from last non-leaf node
    for i in range(n // 2 - 1, -1, -1):
        heapify(arr, n, i)

🔍 How to use it
arr = [12, 11, 13, 5, 6, 7]
build_heap(arr)
print(arr)

Output (Max Heap):
[13, 11, 12, 5, 6, 7]

explian:https://docs.google.com/document/d/1jUZ2bRVxoSjRgPYSVDY1CpFTEtla7R7oB_uwZmWAIsA/edit?tab=t.0
