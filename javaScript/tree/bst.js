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
        if(node.data > newNode.data) {
            if(node.left === null) {
                node.left = newNode;
            } else {
                this.insertNode(node.left, newNode);
            }
        } else {
            if(node.right === null) {
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
        if ( node.left === null) {
            console.log(node.data);
            return node.data;
        }
        this.findMinNode(node.left);
    }
    
    findMaxNode(node) {
        if (node.right == null) {
            console.log(node.data);
            return node.data;
        }
        this.findMaxNode(node.right);
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

// bst.inorder(bst.getRootNode());
// console.log('wait');
// bst.preorder(bst.getRootNode());
// console.log('wait');
// bst.postorder(bst.getRootNode());
bst.findMinNode(bst.getRootNode());
bst.findMaxNode(bst.getRootNode());