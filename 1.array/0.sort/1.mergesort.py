Ques: https://leetcode.com/problems/sort-an-array/description/

Code:

def merge(arr,l,m,r):
    nl = m-l+1
    nr = r-m
    
    arrl = arr[l:m+1]
    arrr = arr[m+1:r+1]
    
    i=0
    j=0
    k=l
    
    while i<nl and j<nr:
        if arrl[i]<=arrr[j]:
            arr[k] = arrl[i]
            i+=1
        else:
            arr[k] = arrr[j]
            j+=1
        k+=1
    
    while i<nl:
        arr[k]=arrl[i]
        i+=1
        k+=1
    
    while j<nr:
        arr[k]=arrr[j]
        j+=1
        k+=1

def mergesort(arr,l,r):
    if(l<r):
        m=l+(r-l)//2
        mergesort(arr,l,m)
        mergesort(arr,m+1,r)
        merge(arr,l,m,r)

def display(arr,n):
    print(" ".join(map(str,arr)))
    
def display_list(arr,n):
    for i in range(len(arr)):
        print(arr[i], end =" ")
    print()


if __name__ == "__main__":
    n = int(input())
    arr = list(map(int,input().split()))
    
    display(arr,n)
    mergesort(arr,0,n-1)
    display_list(arr,n)



Time and space:

Time and Space Complexity Analysis:
Time Complexity:

Best case: O(N log N)
Average case: O(N log N)
Worst case: O(N log N)
This complexity arises because the array is recursively divided into two halves (log N levels of recursion) and each level requires linear time (N) for merging.
Space Complexity:

O(N) (Auxiliary space)
Extra space is used for temporary arrays during merging.
Requires space for left and right subarrays of size nl and nr.








CLASS:


from typing import List

class Solution:
    def sortArray(self, nums: List[int]) -> List[int]:
        self.mergeSort(nums, 0, len(nums) - 1)
        return nums

    def mergeSort(self, nums: List[int], left: int, right: int) -> None:
        if left >= right:
            return
        mid = (left + right) // 2
        self.mergeSort(nums, left, mid)
        self.mergeSort(nums, mid + 1, right)
        self.merge(nums, left, mid, right)

    def merge(self, nums: List[int], left: int, mid: int, right: int) -> None:
        n1 = mid - left + 1
        n2 = right - mid
        leftArray = nums[left:mid + 1]
        rightArray = nums[mid + 1:right + 1]
        i = j = 0
        k = left
        while i < n1 and j < n2:
            if leftArray[i] <= rightArray[j]:
                nums[k] = leftArray[i]
                i += 1
            else:
                nums[k] = rightArray[j]
                j += 1
            k += 1
        while i < n1:
            nums[k] = leftArray[i]
            i += 1
            k += 1
        while j < n2:
            nums[k] = rightArray[j]
            j += 1
            k += 1


# 👇 This is your "main" part (outside the class)
if __name__ == "__main__":
    obj = Solution()                        # create an object of the class
    arr = [5, 2, 3, 1]                      # input array
    sorted_arr = obj.sortArray(arr)         # call the class method
    print("Sorted array:", sorted_arr)      # print output