
class Node:


	def __init__(self, data):
		self.data = data
		self.next = None



class LinkedList:


	def __init__(self):
		self.head = None

	def printList(self):
		print "printing linkedlist"
		temp = self.head
		while (temp):

			print temp.data,
			temp = temp.next

	def reverseList(this):
		print "printing reverseList"
		temp = this.head
		if temp.next:
			print temp.data
			temp = temp.next
			this.reverseList(temp)
			print temp.data
	def addNode(self, node):
		temp = self.head
		while (temp.next):
			temp = temp.next
		temp.next = node


# Code execution starts here
if __name__ == '__main__':


	llist = LinkedList()
	count = input()
	while (count):
		element = input()
		if llist.head:
			# print "in if part"
			llist.addNode(Node(element))
		else:
			# print "in else part"
			llist.head = Node(element)

		count = count - 1


	llist.printList()
	llist.reverseList()
