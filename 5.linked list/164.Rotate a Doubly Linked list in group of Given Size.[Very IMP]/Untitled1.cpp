// Java implementation to reverse a doubly linked list
// in groups of given size without recursion
// Iterative Method

import java.io.*;
import java.util.*;

// Represents a node of doubly linked list
class Node {
	int data;
	Node next, prev;
}

class GFG {

	// function to get a new node
	static Node getNode(int data)
	{
		// allocating node
		Node new_node = new Node();
		new_node.data = data;
		new_node.next = new_node.prev = null;

		return new_node;
	}

	// function to insert a node at the beginning
	// of the Doubly Linked List
	static Node push(Node head, Node new_node)
	{
		// since we are adding at the beginning,
		// prev is always NULL
		new_node.prev = null;

		// link the old list off the new node
		new_node.next = head;

		// change prev of head node to new node
		if (head != null)
			head.prev = new_node;

		// move the head to point to the new node
		head = new_node;
		return head;
	}

	// function to reverse a doubly linked list
	// in groups of given size
	static Node revListInGroupOfGivenSize(Node head, int k)
	{

	}

	// Function to print nodes in a
	// given doubly linked list
	static void printList(Node head)
	{
		while (head != null) {
			System.out.print(head.data + " ");
			head = head.next;
		}
	}

	// Driver code
	public static void main(String args[])
	{
		// Start with the empty list
		Node head = null;

		// Create doubly linked: 10<->8<->4<->2
		head = push(head, getNode(2));
		head = push(head, getNode(4));
		head = push(head, getNode(8));
		head = push(head, getNode(10));

		int k = 2;

		System.out.print("Original list: ");
		printList(head);

		// Reverse doubly linked list in groups of
		// size 'k'
		head = revListInGroupOfGivenSize(head, k);

		System.out.print("\nModified list: ");
		printList(head);
	}
}

// This code is contributed by Chayan Sharma

