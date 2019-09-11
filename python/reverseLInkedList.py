# k reverse a linked list
# but first reverse a linked list

counter = 0
gHead = {}
class Node:


	def __init__(self, data):
		self.data = data
		self.next = None



class LinkedList:


	counter = 0

	def __init__(self):
		self.head = None

	def printList(self,temp):
		# print "printing linkedlist"
		# temp = gHead
		while (temp):

			print temp.data,
			temp = temp.next

	def reverK(self,k):
		global prev
		# print "printing linkedlist"
		stack = []

		temp = self.head
		while (temp):
			# print temp.data
			stack.append(temp)
			temp = temp.next
			# print stack[0].data
			if len(stack) == k:
				# print 'inside to check'
				small = self.getSmall(stack,k)
				self.printList(small)
				if prev:
					prev.next = small
				else:
					prev = small
				stack = []
		prev.next = None





	def getSmall(self,stack,k):
		global counter
		global gHead
		# print "prinitng stack"
		# print stack
		if counter == 0:
			gHead = stack[k-1]
			counter = counter + 1
		temp = stack.pop()
		start = temp
		# print temp.data
		# print temp.next
		while (len(stack)!= 0):
			temp.next = stack[len(stack)-1]
			temp = stack.pop()
		temp.next = None
		return start





	def reverseList(this,llist, head, k):

		temp = head or llist
		print temp
		if temp.next:
			# print temp.data
			temp = temp.next
			this.reverseList(temp,None)
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


	# llist.printList()
	counter = 0
	gHead = {}
	prev = None
	llist.reverK(3)
	# llist.printList(gHead)
	# print "printing reverseList"
	# print "enter value of k"
	# k = input()
	# llist.reverseList(llist, llist.head,k)

