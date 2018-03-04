/**
 * Created by Kaela on 1/20/17.
 */
public class Stack<E> {
    private Node<E> top;

    public Stack(){
        top = null;                                     // We want to initialize our Stack to be empty
    }
    public void push(E newData){
        Node<E> newNode = new Node<E>(newData, top);    //Create a new node w/ newData and next node is top
        top = newNode;                                  // Push this new node onto the stack
    }
    public Node<E> pop() {
        Node<E> temp = null;
        if (!isEmpty()) {                            // Hint: Return null on a empty stack
            temp = top;                              // Return the Node that currently represents the top of the stack
            top = temp.getNext();                    // Update top
        }
        return temp;
    }
    public boolean isEmpty(){                        //Check if the Stack is empty
        return (top == null);
    }
    public void printStack(){                       // Loop through your stack and print each Node's data
        Node<E> current = top;
        while (current != null) {
            System.out.println(current.getData());
            current = current.getNext();
        }
    }
}
