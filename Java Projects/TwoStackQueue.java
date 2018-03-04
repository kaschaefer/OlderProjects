/**
 * Created by Kaela on 1/23/17.
 *
 * INSTRUCTIONS
 * Create a new public class file called TwoStackQueue, which has two stacks as member variables
 *   • The signature of this class should be the same as the Queue class.
 *      – It should have the same public methods
 *      – Each public method should match in argument types (argument number, etc), and return type.
 ∗          * Note that this is not the same as having the same methods.
 ∗          In particular, you may modify the bodies of public methods, and change add or
                    remove private methods.
 *      – Amortized complexity O(1) for each operation.
 */
public class TwoStackQueue<E> {
    private Stack<E> input;             //Stack in LIFO Order
    private Stack<E> output;            //Stack in FIFO Order

    public TwoStackQueue() {                    //Initializes the Two Stacks as Empty
        input = new Stack<E>();
        output = new Stack<E>();
    }

    public void enqueue(E newData) {     //Create a new Node on the input stack
        if (output.isEmpty()) {          //If the output stack is empty
            input.push(newData);        //Add to input stack
        }
        else {                          //Output Stack not Empty, must return all data to input stack to retain correct order
            while (!output.isEmpty()) {
                input.push(output.pop().getData());
            }
            input.push(newData);
        }
    }

    public Node<E> dequeue(){
        if (output.isEmpty()) {
            while (!input.isEmpty()) {
                output.push(input.pop().getData());         //Reverse Order From Input (LIFO) to Output (FIFO)
            }
        }
        return output.pop();
    }

    public boolean isEmpty(){ // Check if the Queue is empty
        return (output.isEmpty() && input.isEmpty());
    }

    public void printQueue() {
    // Loop through your queue and print each Node's data
        if (output.isEmpty()) {
            while (!input.isEmpty()) {
                output.push(input.pop().getData());         //Reverse Order From Input (LIFO) to Output (FIFO)
            }
        }
        output.printStack();
    }
}
