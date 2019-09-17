#!/bin/python
#to delete a node
import math
import os
import random
import re
import sys
# from __future__ import print_function

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

# Complete the deleteNode function below.

#
# For your reference:
#
# SinglyLinkedListNode:
#     int data
#     SinglyLinkedListNode next
#
#
def deleteNode(head, position):
    count = 0
    if head:
        ll=head
        while(ll):
            previous = ll
            ll = ll.next
            count = count + 1
            if count == position:
                rightHand = ll.next
                middleNode = SinglyLinkedListNode(data)
                middleNode.next = rightHand
                ll.next = middleNode
                return head
    newNode = SinglyLinkedListNode(data)
    head = newNode
    return head

if __name__ == '__main__':
    # fptr = open(os.environ['OUTPUT_PATH'], 'w')

    llist_count = int(raw_input())

    llist = SinglyLinkedList()

    for _ in xrange(llist_count):
        llist_item = int(raw_input())
        llist.insert_node(llist_item)

    position = int(raw_input())

    llist1 = deleteNode(llist.head, position)

    # print_singly_linked_list(llist1, ' ', fptr)
    # fptr.write('\n')
    #
    # fptr.close()
