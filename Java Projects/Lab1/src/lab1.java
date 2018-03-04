/**
 * Created by Kaela on 1/20/17.
 */
import java.util.Scanner;

public class lab1 {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);   // Create a Scanner that reads system input
        int numLines = scanner.nextInt();
        int i =0;
        if (!(numLines==0)) {
            String current;
            while (i < numLines) {                  //Loop over the scanner's input
                current = scanner.next();
                if (isPalindrome(current)) {                    //For each line of the input, send it to isPalindrome()
                    System.out.println("This is a Palindrome.");  //If isPalindrome returns true, print "This is a Palindrome."
                }
                else {
                    System.out.println("Not a Palindrome.");      //Otherwise print "Not a Palindrome."
                }
                i++;
            }
        }
        scanner.close();
    }

    public static boolean isPalindrome(String s) {
        Queue<Character> theQueue = new Queue<Character>();
        Stack<Character> theStack = new Stack<Character>();
        int length = (s.length());
        int currentChar = 0;
        while (currentChar < length) {      //Create a stack and a Queue of chars that represents the passed in string
            theQueue.enqueue(s.charAt(currentChar));
            theStack.push(s.charAt(currentChar));
            currentChar++;
        }
        //Compare your Queue and Stack to see if the input String was a Palindrome or not
        int counter = length/2;     //This will ensure that we only compare l/2 chars in the stack to 1/2 chars in the queue
        boolean result = true;
        while (counter > 0 && result) {        //
            Node<Character> tempQueueNode = theQueue.dequeue();
            Node<Character> tempStackNode = theStack.pop();
            if (tempQueueNode.getData() != tempStackNode.getData()) {
                result = false;
            }
            counter--;
        }
        return result;
    }
}

