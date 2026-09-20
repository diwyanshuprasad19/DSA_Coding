Ques:https://leetcode.com/problems/word-ladder/description/

Yes ✅ — your solution for the Word Ladder problem is using Breadth-First Search (BFS).

code:

✅ Python Code (Without class Solution)
from collections import deque

def ladderLength(beginWord, endWord, wordList):
    # Create a set for fast lookup
    wordSet = set(wordList)

    # If endWord is not present, no transformation possible
    if endWord not in wordSet:
        return 0

    # BFS queue
    queue = deque([beginWord])

    # Distance starts from 1 (beginWord itself)
    distance = 1

    while queue:
        level_size = len(queue)

        for _ in range(level_size):
            current_word = queue.popleft()

            # Found endWord
            if current_word == endWord:
                return distance

            # Try changing each character
            for i in range(len(current_word)):
                for c in 'abcdefghijklmnopqrstuvwxyz':
                    if c == current_word[i]:
                        continue

                    new_word = current_word[:i] + c + current_word[i+1:]

                    if new_word in wordSet:
                        queue.append(new_word)
                        wordSet.remove(new_word)  # mark visited

        # Move to next level
        distance += 1

    return 0

▶️ Sample Input (Inside Code)
beginWord = "hit"
endWord = "cog"
wordList = ["hot","dot","dog","lot","log","cog"]

print(ladderLength(beginWord, endWord, wordList))

print(ladderLength(beginWord, endWord, wordList))

✅ Sample Output
5

Explanation
hit → hot → dot → dog → cog


Total words in path = 5

❌ Sample Input (No Possible Path)
beginWord = "hit"
endWord = "cog"
wordList = ["hot","dot","dog","lot","log"]

print(ladderLength(beginWord, endWord, wordList))

Output
0

⏱️ Time Complexity

Let:

N = number of words in wordList

M = length of each word

Time Complexity
O(N × M × 26)
≈ O(N × M)


Why?

Each word is processed once

For each word → M positions

For each position → 26 letters

🧠 Space Complexity
O(N)


Word set

BFS queue