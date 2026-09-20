
def heapify(arr,n,i):
    largest=i
    left = 2*i +1
    right = 2*i +2
    
    if left<n and arr[left]>arr[largest]:
        largest=left
    if right<n and arr[right]>arr[largest]:
        largest=right
    
    if largest!=i:
        arr[largest],arr[i]= arr[i],arr[largest]
        heapify(arr,n,largest)


def build(arr,n):
    for i in range(n//2,-1,-1):
        heapify(arr,n,i)



arr = [13,2,11,21,14,7]
build(arr,len(arr))
arr[0]= arr[len(arr)-1]
heapify(arr,len(arr),0)
print(arr)

[14, 13, 11, 2, 7, 7]

=== Code Execution Successful ===



delete (delete max / min)

Steps:

Replace root with last element → O(1)

Heapify from root → O(log N)

delete → O(log N)