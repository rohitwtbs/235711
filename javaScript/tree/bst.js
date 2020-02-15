// to do - deletion, post and preorder, search,min node,max node

class Node {
    constructor(data) {
        this.data = data;
        this.left = null;
        this.right = null;
    }
}

class BST {
    constructor() {
        this.root = null;
    }

    getRootNode() {
        return this.root;
    }

    insert(data) {
        let node = new Node(data);
        if (this.root === null) {
            this.root = node;
        } else {
            this.insertNode(this.root, node);
        }

    }

    insertNode(node, newNode) {
        if (node.data > newNode.data) {
            if (node.left === null) {
                node.left = newNode;
            } else {
                this.insertNode(node.left, newNode);
            }
        } else {
            if (node.right === null) {
                node.right = newNode;
            } else {
                this.insertNode(node.right, newNode);
            }
        }

    }

    inorder(node) {
        if (node !== null) {
            this.inorder(node.left);
            console.log(node.data);
            this.inorder(node.right);
        }
    }

    preorder(node) {
        if (node !== null) {
            console.log(node.data);
            this.preorder(node.left);
            this.preorder(node.right);
        }
    }

    postorder(node) {
        if (node !== null) {
            this.postorder(node.left);
            this.postorder(node.right);
            console.log(node.data);
        }
    }

    findMinNode(node) {
        if (node.left === null) {
            console.log(node.data);
            return node;
        }
        this.findMinNode(node.left);
    }

    findMaxNode(node) {
        if (node.right == null) {
            console.log(node.data);
            return node;
        }
        this.findMaxNode(node.right);
    }

    delete(data) {
        this.root = this.removeNode(this.root, data);
    }

    removeNode(node, key) {
        // if the root is null then tree is  
        // empty 
        if (node === null)
            return null;

        // if data to be delete is less than  
        // roots data then move to left subtree 
        else if (key < node.data) {
            node.left = this.removeNode(node.left, key);
            return node;
        }

        // if data to be delete is greater than  
        // roots data then move to right subtree 
        else if (key > node.data) {
            node.right = this.removeNode(node.right, key);
            return node;
        }

        // if data is similar to the root's data  
        // then delete this node 
        else {
            // deleting node with no children 
            if (node.left === null && node.right === null) {
                node = null;
                return node;
            }

            // deleting node with one children 
            if (node.left === null) {
                node = node.right;
                return node;
            }

            else if (node.right === null) {
                node = node.left;
                return node;
            }

            // Deleting node with two children 
            // minumum node of the rigt subtree 
            // is stored in aux 
            var aux = this.findMinNode(node.right);
            node.data = aux.data;

            node.right = this.removeNode(node.right, aux.data);
            return node;
        }
    }
}

var bst = new BST();

bst.insert(15);
bst.insert(25);
bst.insert(10);
bst.insert(7);
bst.insert(22);
bst.insert(17);
bst.insert(13);
bst.insert(5);
bst.insert(9);
bst.insert(27);

bst.inorder(bst.getRootNode());
console.log('wait');
// bst.preorder(bst.getRootNode());
// console.log('wait');
// bst.postorder(bst.getRootNode());
// bst.findMinNode(bst.getRootNode());
// bst.findMaxNode(bst.getRootNode());
bst.delete(10);
bst.inorder(bst.getRootNode());