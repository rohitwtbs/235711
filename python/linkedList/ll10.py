#!/bin/python

import math
import os
import random
import re
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


# Complete the mergeLists function below.

#
# For your reference:
#
# SinglyLinkedListNode:
#     int data
#     SinglyLinkedListNode next
#
#
def mergeLists(head1, head2):
    ll1 = head1
    ll2 = head2
    while(ll1):
        ll1 = ll1.next
    ll1.next = ll2.next
    return head1


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

        llist3 = mergeLists(llist1.head, llist2.head)

        print_singly_linked_list(llist3, ' ', fptr)
        fptr.write('\n')

    fptr.close()
