#!/bin/python
#  get node data from the last
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

# Complete the getNode function below.

#
# For your reference:
#
# SinglyLinkedListNode:
#     int data
#     SinglyLinkedListNode next
#
#
def getNode(head, positionFromTail):
    list = []
    ll = head
    while(ll):
        list.append(ll.data)
        ll = ll.next
    while(list):
        list.pop()

if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    tests = int(raw_input())

    for tests_itr in xrange(tests):
        llist_count = int(raw_input())

        llist = SinglyLinkedList()

        for _ in xrange(llist_count):
            llist_item = int(raw_input())
            llist.insert_node(llist_item)

        position = int(raw_input())

        result = getNode(llist.head, position)

        fptr.write(str(result) + '\n')

    fptr.close()
