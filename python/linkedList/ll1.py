# Insert a Node at the Tail of a Linked List

#!/bin/python

import math
import os
import random
import re
import sys

class SinglyLinkedListNode:
    def __init__(self, node_data):
        self.data = node_data
        self.next = None

class SinglyLinkedList:
    def __init__(self):
        self.head = None


# def print_singly_linked_list(node, sep, fptr):
#     while node:
#         fptr.write(str(node.data))
#
#         node = node.next
#
#         if node:
#             fptr.write(sep)

# Complete the insertNodeAtTail function below.

#
# For your reference:
#
# SinglyLinkedListNode:
#     int data
#     SinglyLinkedListNode next
#
#
def insertNodeAtTail(head, data):
    print data
    ll = head
    if hasattr(head, 'next') == False:
        head = SinglyLinkedListNode(data)
        return head
    while(ll.next):
        ll = ll.next
    newNode = SinglyLinkedListNode(data)
    ll.next = newNode




if __name__ == '__main__':
    # fptr = open(os.environ['OUTPUT_PATH'], 'w')

    llist_count = int(raw_input())

    llist = SinglyLinkedList()

    for i in xrange(llist_count):
        llist_item = int(raw_input())
        llist_head = insertNodeAtTail(llist.head, llist_item)
        llist.head = llist_head

    # print_singly_linked_list(llist.head, '\n', fptr)
    # fptr.write('\n')
    #
    # fptr.close()
