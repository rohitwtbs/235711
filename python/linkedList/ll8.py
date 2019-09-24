#!/bin/python
# Compare two linked lists
import os
import sys
from __future__ import print_function


class SinglyLinkedListNode:
    def __init__(self, node_data):
        self.data = node_data
        self.next = None


class SinglyLinkedList:
    def __init__(self):
        self.head = None
        self.tail = None

    def insert_node(self, node_data):
        node = SinglyLinkedListNode(node_data)

        if not self.head:
            self.head = node
        else:
            self.tail.next = node

        self.tail = node


def print_singly_linked_list(node, sep, fptr):
    while node:
        fptr.write(str(node.data))

        node = node.next

        if node:
            fptr.write(sep)


# Complete the compare_lists function below.

#
# For your reference:
#
# SinglyLinkedListNode:
#     int data
#     SinglyLinkedListNode next
#
#
def compare_lists(head1, head2):
    ll1 = head1
    ll2 = head2
    while(ll1 and ll2):
        if ll1.data != ll2.data:
            return 0
        ll1 = ll1.next
        ll2 = ll2.next
    if ll1 == None and ll2 == None:
        return 1
    else:
        return 0




if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    tests = int(raw_input())

    for tests_itr in xrange(tests):
        llist1_count = int(raw_input())

        llist1 = SinglyLinkedList()

        for _ in xrange(llist1_count):
            llist1_item = int(raw_input())
            llist1.insert_node(llist1_item)

        llist2_count = int(raw_input())

        llist2 = SinglyLinkedList()

        for _ in xrange(llist2_count):
            llist2_item = int(raw_input())
            llist2.insert_node(llist2_item)

        result = compare_lists(llist1.head, llist2.head)

        fptr.write(str(int(result)) + '\n')

    fptr.close()
