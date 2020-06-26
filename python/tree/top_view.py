# Todo
# the solution is correct but the order os solution in hackerank ouput and
# this program output doesnot matches
# try to solve this thing.

class Node:
    def __init__(self, info):
        self.info = info
        self.left = None
        self.right = None
        self.level = None

    def __str__(self):
        return str(self.info)


class BinarySearchTree:
    def __init__(self):
        self.root = None

    def create(self, val):
        if self.root == None:
            self.root = Node(val)
        else:
            current = self.root

            while True:
                if val < current.info:
                    if current.left:
                        current = current.left
                    else:
                        current.left = Node(val)
                        break
                elif val > current.info:
                    if current.right:
                        current = current.right
                    else:
                        current.right = Node(val)
                        break
                else:
                    break


"""
Node is defined as
self.left (the left child of the node)
self.right (the right child of the node)
self.info (the value of the node)
"""

def top_view(root):
    queue = []
    vertex_to_rank = {}
    rank_to_vertex = {}
    vertex_to_rank[root] = 0
    # print(vertex_to_rank)
    rank_to_vertex[0] = [root]
    queue.append(root)
    while len(queue) != 0:
        top = queue.pop(0)
        # print (top.info,end =" ")
        if top.left != None:
            queue.append(top.left)
            vertex_to_rank[top.left] = vertex_to_rank[top] - 1
            if rank_to_vertex.__contains__(vertex_to_rank[top] - 1):
                rank_to_vertex[vertex_to_rank[top] - 1].append(top.left)
            else:
                rank_to_vertex[vertex_to_rank[top] - 1] = []
                rank_to_vertex[vertex_to_rank[top] - 1].append(top.left)
        if top.right != None:
            queue.append(top.right)
            vertex_to_rank[top.right] = vertex_to_rank[top] + 1
            if rank_to_vertex.__contains__(vertex_to_rank[top] + 1):
                rank_to_vertex[vertex_to_rank[top] + 1].append(top.right)
            else:
                rank_to_vertex[vertex_to_rank[top] + 1] = []
                rank_to_vertex[vertex_to_rank[top] + 1].append(top.right)
    # order the keys so that the top view in the sequence that we see.
    import collections
    od = collections.OrderedDict(sorted(rank_to_vertex.items()))
    for key,value in rank_to_vertex.items():
        address = value.pop(0)
        print (address.info,end=" ")




tree = BinarySearchTree()
t = int(input())

arr = list(map(int, input().split()))

for i in range(t):
    tree.create(arr[i])

top_view(tree.root)