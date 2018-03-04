/**
 * Created by Kaela on 1/20/17.
 */
public class Queue<E> {
    private Node<E> head;
    private Node<E> tail;

    public Queue() {                    //Initializes the Queue as Empty
        head = null;
        tail = null;
    }
    public void enqueue(E newData) {    //Create a new node whose data is newData and whose next node is null
        Node<E> newNode = new Node<E>(newData, null);
        if (isEmpty()) {                // Update head and tail
            head = newNode;
        } else {
            tail.setNext(newNode);
        }
        tail = newNode;
    }
    public Node<E> dequeue(){       //Return the current head and update head to head.next
        Node<E> temp = null;
        if (!isEmpty()) {
            temp = head;
            head = temp.getNext();
        }
        return temp;
    }
    public boolean isEmpty(){ // Check if the Queue is empty
        return (head == null);
    }

    public void printQueue(){       // Loop through your queue and print each Node's data
        Node<E> current = head;
        while (current != null) {
            System.out.println(current.getData());
            current = current.getNext();
        }
    }
}
