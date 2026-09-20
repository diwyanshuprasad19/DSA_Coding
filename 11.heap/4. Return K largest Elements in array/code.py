Ques:https://leetcode.com/problems/kth-largest-element-in-an-array/description/

Code:

import heapq

class Solution:
    def findKthLargest(self, nums, k):
        min_heap = []

        for num in nums:
            heapq.heappush(min_heap, num)
            if len(min_heap) > k:
                heapq.heappop(min_heap)

        return min_heap[0]


if __name__ == "__main__":
    sol = Solution()
    nums = [3, 2, 3, 1, 2, 4, 5, 5, 6]
    k = 4
    print(f"The {k}th largest element is: {sol.findKthLargest(nums, k)}")


Time Complexity:
Insertion in Min-Heap: Each element is inserted into the heap, which takes O(log k) time.
Iteration through n elements: We iterate over all n elements of the array.
Pop Operation: Whenever the heap exceeds k elements, we pop the smallest element, which also takes O(log k) time.
Final Complexity Calculation:
Each insertion and pop operation costs O(log k).
We perform these operations n times.
Thus, the total complexity is O(n log k).
Space Complexity:
Min-Heap Storage: At most, k elements are stored in the heap at any time.
Ignoring Input Storage: The input array nums is given as input and does not contribute to additional space complexity.
Final Space Complexity: O(k).
Final Complexity Summary
Operation	Complexity
Time Complexity	O(n log k)
Space Complexity	O(k)