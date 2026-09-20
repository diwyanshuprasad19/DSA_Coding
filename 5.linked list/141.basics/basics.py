# =========================
# Linked List Implementation
# =========================

class Node:
    def __init__(self, data):
        self.data = data
        self.next = None


class LinkedList:
    def __init__(self):
        self.head = None

    # Add at beginning
    def add_first(self, data):
        node = Node(data)
        node.next = self.head
        self.head = node

    # Add at end
    def add_last(self, data):
        node = Node(data)
        if not self.head:
            self.head = node
            return

        curr = self.head
        while curr.next:
            curr = curr.next
        curr.next = node

    # Add at position (0-based index)
    def add_at(self, index, data):
        if index == 0:
            self.add_first(data)
            return

        node = Node(data)
        curr = self.head
        for _ in range(index - 1):
            if not curr:
                raise IndexError("Index out of range")
            curr = curr.next

        node.next = curr.next
        curr.next = node

    # Delete by value
    def delete_value(self, data):
        curr = self.head

        if curr and curr.data == data:
            self.head = curr.next
            return

        prev = None
        while curr and curr.data != data:
            prev = curr
            curr = curr.next

        if not curr:
            print("Value not found")
            return

        prev.next = curr.next

    # Delete by position
    def delete_at(self, index):
        if index == 0:
            self.head = self.head.next
            return

        curr = self.head
        for _ in range(index - 1):
            if not curr:
                raise IndexError("Index out of range")
            curr = curr.next

        curr.next = curr.next.next

    # Search
    def search(self, data):
        curr = self.head
        index = 0
        while curr:
            if curr.data == data:
                return index
            curr = curr.next
            index += 1
        return -1

    # Length
    def length(self):
        count = 0
        curr = self.head
        while curr:
            count += 1
            curr = curr.next
        return count

    # Display
    def display(self):
        curr = self.head
        while curr:
            print(curr.data, end=" -> ")
            curr = curr.next
        print("None")


# =========================
# Example Usage
# =========================
if __name__ == "__main__":
    ll = LinkedList()

    ll.add_last(10)
    ll.add_last(20)
    ll.add_last(30)
    ll.add_first(5)
    ll.add_at(2, 15)

    ll.display()        # 5 -> 10 -> 15 -> 20 -> 30 -> None

    ll.delete_value(15)
    ll.display()        # 5 -> 10 -> 20 -> 30 -> None

    ll.delete_at(1)
    ll.display()        # 5 -> 20 -> 30 -> None

    print(ll.search(30))  # 2
    print(ll.length())    # 3


5 -> 10 -> 15 -> 20 -> 30 -> None
5 -> 10 -> 20 -> 30 -> None
5 -> 20 -> 30 -> None
2
3

=== Code Execution Successful ===


⏱ Time Complexity
Operation	Complexity
Add	O(n)
Delete	O(n)
Search	O(n)
Display	O(n)


