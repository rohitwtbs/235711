class Node:
    def __init__(self, info):
        self.info = info
        self.left = None
        self.right = None

class BinaryTree:
    def __init__(self):
        self.root = None
        self.queue = []

    def create(self, value):
        if self.root == None:
            self.root = Node(value)
        queue = []
        queue.append(self.root)
        while len(queue) != 0:
            top = queue.pop(0)
            if top.left != None:
                queue.append(top.left)
            else:
                top.left = Node(value)
                break
            if top.right != None:
                queue.append(top.right)
            else:
                top.right = Node(value)
                break
        
def inOrder(root):
    if root != None:
        inOrder(root.left)
        print (root.info,end =" ")
        inOrder(root.right)


def level_order(root):
    queue = []
    queue.append(root)
    while len(queue) != 0:
        top = queue.pop(0)
        print (top.info,end =" ")
        if top.left != None:
            queue.append(top.left)
        if top.right != None:
            queue.append(top.right)





tree = BinaryTree()
t = int(input())

arr = list(map(int, input().split()))

for i in range(t):
    tree.create(arr[i])

inOrder(tree.root)
level_order(tree.root)


# Todo
# check why level order is printing an extra item