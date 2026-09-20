A Fenwick Tree, also called a Binary Indexed Tree (BIT), is a data structure used when you need:
    
this is mostly for the update take O(n)

fast updates to array values
fast prefix sums / range sums

Operation	Complexity
Update one value	O(log n)
Prefix sum	O(log n)
Range sum	O(log n)
Space	O(n)
first time create->nlogn tc



Youtube-https://www.youtube.com/watch?v=CWDQJGaN1gY

Code:
    
1. Point Update
2. Prefix Sum
3. Range Sum
4. Build from array
5. Set a value
6. Find kth / lower_bound using prefix sums


class FenwickTree:
    def __init__(self, arr):
        """
        Create Fenwick Tree from array
        """

        self.n = len(arr)

        # Store original array
        self.arr = arr[:]

        # Fenwick Tree uses 1-based indexing
        self.tree = [0] * (self.n + 1)

        # Build tree
        for i, value in enumerate(arr):
            self._add(i, value)


    # ------------------------------------------------
    # 1. Internal Add
    # ------------------------------------------------
    def _add(self, index, delta):
        """
        Add delta to arr[index]

        Time: O(log n)
        """

        # Convert 0-based index -> 1-based
        i = index + 1

        while i <= self.n:

            self.tree[i] += delta

            # Move to next responsible node
            i += i & -i


    # ------------------------------------------------
    # 2. Add value to an index
    # ------------------------------------------------
    def add(self, index, delta):
        """
        arr[index] += delta

        Example:
        arr[2] = 5

        add(2, 3)

        arr[2] becomes 8
        """

        if index < 0 or index >= self.n:
            raise IndexError("Index out of range")

        self.arr[index] += delta

        self._add(index, delta)


    # ------------------------------------------------
    # 3. Set / Update value
    # ------------------------------------------------
    def update(self, index, new_value):
        """
        Change arr[index] to new_value

        Example:

        arr[2] = 5

        update(2, 10)

        arr[2] becomes 10
        """

        if index < 0 or index >= self.n:
            raise IndexError("Index out of range")

        # Find change required
        delta = new_value - self.arr[index]

        # Update original array
        self.arr[index] = new_value

        # Update Fenwick Tree
        self._add(index, delta)


    # ------------------------------------------------
    # 4. Prefix Sum
    # ------------------------------------------------
    def prefix_sum(self, index):
        """
        Sum from:

        arr[0] ... arr[index]

        Time: O(log n)
        """

        if index < 0:
            return 0

        if index >= self.n:
            raise IndexError("Index out of range")

        # Convert to 1-based
        i = index + 1

        total = 0

        while i > 0:

            total += self.tree[i]

            # Move towards 0
            i -= i & -i

        return total


    # ------------------------------------------------
    # 5. Range Sum
    # ------------------------------------------------
    def range_sum(self, left, right):
        """
        Sum from:

        arr[left] ... arr[right]

        Formula:

        prefix(right) - prefix(left - 1)

        Time: O(log n)
        """

        if left < 0 or right >= self.n or left > right:
            raise ValueError("Invalid range")

        return (
            self.prefix_sum(right)
            -
            self.prefix_sum(left - 1)
        )


    # ------------------------------------------------
    # 6. Get single value
    # ------------------------------------------------
    def get(self, index):
        """
        Return arr[index]
        """

        if index < 0 or index >= self.n:
            raise IndexError("Index out of range")

        return self.arr[index]


    # ------------------------------------------------
    # 7. Lower Bound
    # ------------------------------------------------
    def lower_bound(self, target):
        """
        Find first index such that:

        prefix_sum(index) >= target

        Works correctly when frequencies /
        array values are non-negative.

        Time: O(log n)
        """

        if target <= 0:
            return 0

        total_sum = self.prefix_sum(self.n - 1)

        if target > total_sum:
            return -1

        index = 0

        # Highest power of 2 <= n
        bit = 1 << (self.n.bit_length() - 1)

        while bit > 0:

            next_index = index + bit

            if (
                next_index <= self.n
                and
                self.tree[next_index] < target
            ):

                target -= self.tree[next_index]

                index = next_index

            bit >>= 1

        # index is already the 0-based answer
        return index


    # ------------------------------------------------
    # 8. Show original array
    # ------------------------------------------------
    def show_array(self):
        print("Array:")
        print(self.arr)


    # ------------------------------------------------
    # 9. Show Fenwick Tree
    # ------------------------------------------------
    def show_tree(self):
        print("Fenwick Tree:")
        print(self.tree)


    # ------------------------------------------------
    # 10. Show index-wise values
    # ------------------------------------------------
    def show(self):

        print("\nOriginal Array:")
        print(self.arr)

        print("\nFenwick Tree:")
        print(self.tree)

        print("\nIndex -> Value")

        for i in range(self.n):
            print(i, "->", self.arr[i])
