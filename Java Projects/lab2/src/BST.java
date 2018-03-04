/**
 * Created by Kaela on 2/10/17.
 */
public class BST<E extends Comparable<E>> {
    private Node<E> root;
    public BST(){
        root = null;
    }
    public Node<E> getRoot(){
        return root;
    }

    public void insert(E data){
        Node<E> newNode = new Node<E>(data);
        if (root == null) {                 // Make sure to check if anything is in the tree
            root = newNode;
        }
        else {                              //The Tree Is Not Empty
            Node<E> current = root;
            while (current != null && newNode.getParent() == null) {      //TODO: Decide while loop condition
                int difference = current.getData().compareTo(data);
                if (difference > 0) {                       //Data is Less than Current Node's Key
                    if (current.getLeftChild() == null) {    //Current Does Not Have a Left Child
                        current.setLeftChild(newNode);
                        newNode.setParent(current);
                    }
                    else {
                        current = current.getLeftChild();    //Current = Current's Left Child
                    }
                }
                else if (difference < 0) {
                    if (current.getRightChild() == null) {    //Current Does Not Have a Right Child
                        current.setRightChild(newNode);
                        newNode.setParent(current);
                    } else {
                        current = current.getRightChild();    //Current = Current's Right Child
                    }
                }
            }

        }
    }

    public Node<E> find(E data) {
        // Search the tree for a node whose data field is equal to data
        Node<E> current = root;
        boolean found = false;
        while (!found && current != null) {
            int difference = current.getData().compareTo(data);
            if (difference > 0) {                       //Data is Less than Current Node's Key, Go Left
                current = current.getLeftChild();
            }
            else if (difference < 0) {
                current = current.getRightChild();      //Data is More than Current's Key, Go Right
            }
            else if (difference == 0) {
                found = true;
            }
        }
        return current;
    }

    public void delete(E data){
        Node<E> delNode = find(data);
        Node<E> delNodeParent = delNode.getParent();

        if (delNode != null) {                                                      //Only Delete if Found
            boolean isLeftChild = false;
            if (delNodeParent != null && delNodeParent.getData().compareTo(data) > 0) {                      //Is delNode a Left Child of Parent?
                isLeftChild = true;
            }

            if (delNode.getLeftChild() == null && delNode.getRightChild() == null) {    //delNode is a leaf
                if(delNode == root) {                                               //delNode is Root
                    root = null;
                }
                else if (isLeftChild) {                                                  //delNode is Left Child
                    delNodeParent.setLeftChild(null);
                }
                else {                                                               //delNode is Right Child
                    delNodeParent.setRightChild(null);
                }
            }

            else if (delNode.getRightChild() == null) {                      //delNode only has Left Child
                if (delNode==root) {                                        //delNode is Root
                    root = delNode.getLeftChild();
                }
                else if (isLeftChild) {                                           //delNode is Left Child
                    delNodeParent.setLeftChild(delNode.getLeftChild());
                }
                else {                                                      //delNode is Right Child
                    delNodeParent.setRightChild(delNode.getLeftChild());
                }
            }

            else if (delNode.getLeftChild() == null) {                      //delNode only has Right Child
                if (delNode == root) {
                    root = delNode.getRightChild();                         //delNode is Root
                }
                else if (isLeftChild) {                                          //delNode is Left Child
                    delNodeParent.setLeftChild(delNode.getRightChild());
                }
                else {                                                      //delNode is Right Child
                    delNodeParent.setRightChild(delNode.getRightChild());
                }
            }

            else {                                                          //delNode has 2 Children
                Node<E> successor = findSuccessor(delNode);
                if (delNode == root) {                                      //delNode is Root
                    root = successor;
                }
                else if (isLeftChild) {                                     //delNode is LeftChild
                    delNodeParent.setLeftChild(successor);                  //Connect Parent of delNode to Successor
                }
                else {
                    delNodeParent.setRightChild(successor);
                }
                successor.setLeftChild(delNode.getLeftChild());             //Connect Successor to delNode's left child
            }
        }
    }

    private Node<E> findSuccessor(Node<E> delNode) {
        Node<E> successorParent = delNode;
        Node<E> successor = delNode;
        Node<E> current = delNode.getRightChild();
        while (current != null) {
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

    public void traverse(String order, Node<E> top) {
        if (top != null){
            switch (order) {
                case "preorder":
                    preOrder(root);
                    System.out.println();
                    break;
                case "inorder":
                    inOrder(root);
                    System.out.println();
                    break;
                case "postorder":
                    postOrder(root);
                    System.out.println();
                    break;
            }
        }
    }

    private void inOrder(Node<E> localRoot) {
        if (localRoot!=null) {
            inOrder(localRoot.getLeftChild());
            System.out.print(localRoot.getData() + " ");
            inOrder(localRoot.getRightChild());
        }
    }

    private void preOrder(Node<E> localRoot) {
        if (localRoot!=null) {
            System.out.print(localRoot.getData() + " ");
            preOrder(localRoot.getLeftChild());
            preOrder(localRoot.getRightChild());
        }
    }

    private void postOrder(Node<E> localRoot) {
        if (localRoot != null) {
            postOrder(localRoot.getLeftChild());
            postOrder(localRoot.getRightChild());
            System.out.print(localRoot.getData() + " ");
        }
    }
}