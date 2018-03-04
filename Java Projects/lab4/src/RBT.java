/**
 * Created by Kaela on 3/3/17.
 */
public class RBT<E extends Comparable<E>> {
    private Node<E> root;
    private Node<E> nil;

    public RBT() {
        nil = new Node<E>(null);
        nil.setColor('b');
        root = null;
    }

    public Node<E> getRoot() {
        return root;
    }

    public void setRoot(Node<E> newRoot) {
        root = newRoot;
    }

    public void insert(E data) {
        // Preform a regular insert
        boolean done = false;
        Node<E> newNode = new Node<E>(data);
        if (root == null) {                 // Make sure to check if anything is in the tree
            root = newNode;
            root.setParent(nil);
            root.setLeftChild(nil);
            root.setRightChild(nil);
        } else {                              //The Tree Is Not Empty
            Node<E> current = root;
            while (!done) {
                int difference = current.getData().compareTo(data);
                if (difference > 0) {                       //Data is Less than Current Node's Key
                    if (current.getLeftChild() == nil) {    //Current Does Not Have a Left Child
                        current.setLeftChild(newNode);
                        newNode.setParent(current);
                        newNode.setLeftChild(nil);
                        newNode.setRightChild(nil);
                        done = true;
                    } else {
                        current = current.getLeftChild();    //Current = Current's Left Child
                    }
                } else if (difference < 0) {
                    if (current.getRightChild() == nil) {    //Current Does Not Have a Right Child
                        current.setRightChild(newNode);
                        newNode.setParent(current);
                        newNode.setRightChild(nil);
                        newNode.setLeftChild(nil);
                        done = true;
                    } else {
                        current = current.getRightChild();    //Current = Current's Right Child
                    }
                }
            }

        }

        //Maintaining RBT
        fixInsert(newNode);

    }

    public Node<E> search(E data) {
        Node<E> current = root;
        boolean found = false;
        while (!found && current != nil) {
            int difference = current.getData().compareTo(data);
            if (difference > 0) {                       //Data is Less than Current Node's Key, Go Left
                current = current.getLeftChild();
            } else if (difference < 0) {
                current = current.getRightChild();      //Data is More than Current's Key, Go Right
            } else if (difference == 0) {
                found = true;
            }
        }
        if (current == nil) {
            return null;
        }
        else {
            return current;
        }
    }

    public void delete(E data) {
        // Preform a regular delete
        Node<E> delNode = search(data);
        char delNodeOriginalColor = delNode.getColor();
        Node<E> delNodeParent = delNode.getParent();
        Node<E> x = nil;

        if (delNode != nil) {                                                      //Only Delete if Found
            boolean isLeftChild = false;
            if (delNodeParent != nil && delNodeParent.getData().compareTo(data) > 0) {  //Is delNode a Left Child of Parent?
                isLeftChild = true;
            }

            if (delNode.getLeftChild() == nil && delNode.getRightChild() == nil) {    //delNode is a leaf
                if (delNode == root) {                                               //delNode is Root
                    root = null;
                } else if (isLeftChild) {                                                  //delNode is Left Child
                    delNodeParent.setLeftChild(nil);
                    nil.setParent(delNodeParent);
                    x = nil;
                } else {                                                               //delNode is Right Child
                    delNodeParent.setRightChild(nil);
                    nil.setParent(delNodeParent);
                    x = nil;
                }
            } else if (delNode.getRightChild() == nil) {                      //delNode only has Left Child
                if (delNode == root) {
                    root = delNode.getLeftChild();
                } else if (isLeftChild) {                                           //delNode is Left Child
                    delNodeParent.setLeftChild(delNode.getLeftChild());
                } else {                                                      //delNode is Right Child
                    delNodeParent.setRightChild(delNode.getLeftChild());
                }
                x = delNode.getLeftChild();
            } else if (delNode.getLeftChild() == nil) {                      //delNode only has Right Child
                if (delNode == root) {
                    root = delNode.getRightChild();                         //delNode is Root
                } else if (isLeftChild) {                                          //delNode is Left Child
                    delNodeParent.setLeftChild(delNode.getRightChild());
                } else {                                                      //delNode is Right Child
                    delNodeParent.setRightChild(delNode.getRightChild());
                }
                x = delNode.getRightChild();
            } else {                                                          //delNode has 2 Children
                Node<E> successor = findSuccessor(delNode);
                x = successor.getRightChild();
                delNodeOriginalColor = successor.getColor();
                if (delNode == root) {                                      //delNode is Root
                    root = successor;
                } else if (isLeftChild) {                                     //delNode is LeftChild
                    delNodeParent.setLeftChild(successor);                  //Connect Parent of delNode to Successor
                } else {
                    delNodeParent.setRightChild(successor);
                }
                successor.setLeftChild(delNode.getLeftChild());             //Connect Successor to delNode's left child
                successor.setColor(delNode.getColor());
            }


            //Maintain RBT
            if (delNodeOriginalColor == 'b') {
                fixDelete(x);
            }
        }

    }

    public void traverse(String order, Node<E> top) {
        // Preform a preorder traversal of the tree
        if (top != null) {
            switch (order) {
                case "preorder":
                    preOrder(root);
                    break;
                case "inorder":
                    inOrder(root);
                    break;
                case "postorder":
                    postOrder(root);
                    break;
            }
        }
    }


    public void rightRotate(Node<E> y) {
        Node<E> x = y.getLeftChild();
        y.setLeftChild(x.getRightChild());
        if (x.getRightChild() != nil) {
            x.getRightChild().setParent(y);
        }
        x.setParent(y.getParent());
        if (y.getParent() == nil) {
            root = x;
        } else if (y == y.getParent().getRightChild()) {
            y.getParent().setRightChild(x);
        } else {
            y.getParent().setLeftChild(x);
        }
        x.setRightChild(y);
        y.setParent(x);
    }

    public void leftRotate(Node<E> x) {
        Node<E> y = x.getRightChild();
        x.setRightChild(y.getLeftChild());
        if (y.getLeftChild() != nil) {
            y.getLeftChild().setParent(x);
        }
        y.setParent(x.getParent());
        if (x.getParent() == nil) {
            root = y;
        } else if (x == x.getParent().getLeftChild()) {
            x.getParent().setLeftChild(y);
        } else {
            x.getParent().setRightChild(y);
        }
        y.setLeftChild(x);
        x.setParent(y);
    }


    //Helper Functions

    private Node<E> findSuccessor(Node<E> delNode) {
        Node<E> successorParent = delNode;
        Node<E> successor = delNode;
        Node<E> current = delNode.getRightChild();
        while (current != nil) {
            successorParent = successor;
            successor = current;
            current = current.getLeftChild();
        }
        if (successor != delNode.getRightChild()) {
            successorParent.setLeftChild(successor.getRightChild());
            successor.setRightChild(delNode.getRightChild());
        }
        return successor;
    }

    private void inOrder(Node<E> localRoot) {
        if (localRoot != nil) {
            inOrder(localRoot.getLeftChild());
            System.out.print(localRoot.getData() + " ");
            inOrder(localRoot.getRightChild());
        }
    }

    private void preOrder(Node<E> localRoot) {
        if (localRoot != nil) {
            System.out.print(localRoot.getData() + " ");
            preOrder(localRoot.getLeftChild());
            preOrder(localRoot.getRightChild());
        }
    }

    private void postOrder(Node<E> localRoot) {
        if (localRoot != nil) {
            postOrder(localRoot.getLeftChild());
            postOrder(localRoot.getRightChild());
            System.out.print(localRoot.getData() + " ");
        }
    }

    private void fixInsert(Node<E> z) {
        if (z.getColor() == 'r' && z.getParent().getColor() == 'r') {
            while (z.getParent().getColor() == 'r') {
                //If Z is in its grandparent's left subtree
                if (z.getParent() == z.getParent().getParent().getLeftChild()) {
                    //Set y to be z's uncle
                    Node<E> y = z.getParent().getParent().getRightChild();
                    //case 1.1 --> z's uncle is red
                    if (y.getColor() == 'r') {
                        z.getParent().setColor('b');
                        y.setColor('b');
                        z.getParent().getParent().setColor('r');
                        z = z.getParent().getParent();
                    }
                    //case 1.2 --> z's uncle is black and z is a right child
                    else {
                        if (z == z.getParent().getRightChild()) {
                            z = z.getParent();
                            leftRotate(z);
                        }
                        //case 1.3 --> z's uncle is black and z is a left child
                        z.getParent().setColor('b');
                        z.getParent().getParent().setColor('r');
                        rightRotate(z.getParent().getParent());
                    }
                } else {
                    //Z is in its grandparent's right subtree
                    //Set y to be z's uncle
                    Node<E> y = z.getParent().getParent().getLeftChild();
                    //case 2.1 --> z's uncle is red
                    if (y.getColor() == 'r') {
                        z.getParent().setColor('b');
                        y.setColor('b');
                        z.getParent().getParent().setColor('r');
                        z = z.getParent().getParent();
                    }
                    //case 2.2 --> z's uncle is black and z is a left child
                    else {
                        if (z == z.getParent().getLeftChild()) {    //Right-Left Case
                            z = z.getParent();
                            rightRotate(z);
                        }
                        //case 2.3 --> z's uncle is black and z is a right child
                        z.getParent().setColor('b');
                        z.getParent().getParent().setColor('r');
                        leftRotate(z.getParent().getParent());
                    }
                }
            }
        }
        if (z.getParent() == nil) {
            z.setColor('b');
        }
    }

    private void fixDelete(Node<E> x) {
        while (x != root && x.getColor() == 'b') {
            //X is its Parent's Left Child
            if (x == x.getParent().getLeftChild()) {
                Node<E> w = x.getParent().getRightChild();
                //Case 1
                if (w.getColor() == 'r') {
                    w.setColor('b');
                    x.getParent().setColor('r');
                    leftRotate(x.getParent());
                    w = x.getParent().getRightChild();
                }
                //Case 2
                if (w.getLeftChild().getColor() == 'b' && w.getRightChild().getColor() == 'b') {
                    w.setColor('r');
                    x = x.getParent();
                }

                else {
                    //Case 3
                    if (w.getRightChild().getColor() == 'b') {
                        w.getLeftChild().setColor('b');
                        w.setColor('r');
                        rightRotate(w);
                        w = x.getParent().getRightChild();
                    }
                    //Case 4
                    w.setColor(x.getParent().getColor());
                    x.getParent().setColor('b');
                    w.getRightChild().setColor('b');
                    leftRotate(x.getParent());
                    x = root;
                }
            }
            //X is its Parent's Right Child
            else {
                Node<E> w = x.getParent().getLeftChild();
                //Case 1
                if (w.getColor() == 'r') {
                    w.setColor('b');
                    x.getParent().setColor('r');
                    rightRotate(x.getParent());
                    w = x.getParent().getLeftChild();
                }
                //Case 2
                if (w.getRightChild().getColor() == 'b' && w.getLeftChild().getColor() == 'b') {
                    w.setColor('r');
                    x = x.getParent();
                }

                else {
                    //Case 3
                    if (w.getLeftChild().getColor() == 'b') {
                        w.getRightChild().setColor('b');
                        w.setColor('r');
                        leftRotate(w);
                        w = x.getParent().getLeftChild();
                    }
                    //Case 4
                    w.setColor(x.getParent().getColor());
                    x.getParent().setColor('b');
                    w.getLeftChild().setColor('b');
                    rightRotate(x.getParent());
                    x = root;
                }
            }
        }
        x.setColor('b');
    }


    public boolean isRBT() {
        boolean result = false;
        int returnVal = isRBTHelper(root);
        if (returnVal != -1) {
            result = true;
        }
        return result;
    }

    private Integer isRBTHelper (Node<E> localRoot) {
        //If Subtree is empty, return 0
        int leftHeight =0;
        int rightHeight =0;
        if (localRoot == null) {
            return 0;
        }
        //Computes the Black Height of Left and Right Subtrees Recursively
        if (localRoot != nil) {
            leftHeight = isRBTHelper(localRoot.getLeftChild());
            rightHeight = isRBTHelper(localRoot.getRightChild());
        }
        int add = localRoot.getColor() == 'b' ? 1 : 0;
        if (leftHeight == -1 || rightHeight == -1 || leftHeight != rightHeight) {
            return -1;
        }
        return leftHeight + add;
    }

}


