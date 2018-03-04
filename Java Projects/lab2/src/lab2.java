/**
 * Created by Kaela on 2/10/17.
 */
import java.util.Scanner;
public class lab2 { public static void main(String[] args) {
    BST<Integer> theTree = new BST<>();
    Scanner scanner = new Scanner(System.in);
    int numLines = scanner.nextInt();
    int i =0;
    while (!(numLines==0) && i <numLines) {
        String current = scanner.next();                           //Get Next Line
        char task = current.charAt(0);                      //Parse String, Check First Letter
        switch(task) {                                      //Switch Statement
            case 'd':                                       //Call Delete
                int delVal = scanner.nextInt();
                theTree.delete(delVal);
                break;
            case 'f':                                       //Call Find
                int findVal = scanner.nextInt();
                theTree.find(findVal);
                break;
            case 'i':
                if (current.charAt(2) == 's') {             //Call Insert
                 int insertVal = scanner.nextInt();
                 theTree.insert(insertVal);
                }
                else {                                      //Call Inorder
                    theTree.traverse("inorder", theTree.getRoot());
                }
                break;
            case 'p':
                if (current.charAt(1) == 'r') {             //Call Preorder
                    theTree.traverse("preorder", theTree.getRoot());
                }
                else {                                      //Call Postorder
                    theTree.traverse("postorder", theTree.getRoot());
                }
                break;
        }
        i++;
    }
    scanner.close();
} }