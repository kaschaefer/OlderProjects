/**
 * Created by Kaela on 2/11/17.
 */

import java.util.Scanner;

public class TreeCompare {
    public static void main(String[] args) {
        BST<Integer> treeOne = new BST<Integer>();
        BST<Integer> treeTwo = new BST<Integer>();
        Scanner scanner = new Scanner(System.in);
        int numLinesOne = scanner.nextInt();
        for (int i = 0; i < numLinesOne; i++) {
            String current = scanner.next();
            char task = current.charAt(0);                      //Parse String, Check First Letter
            switch (task) {                                      //Switch Statement
                case 'd':                                       //Call Delete
                    int delVal = scanner.nextInt();
                    treeOne.delete(delVal);
                    break;
                case 'i':
                    int insertVal = scanner.nextInt();
                    treeOne.insert(insertVal);
                    break;
            }
        }
        int numLinesTwo = scanner.nextInt();
        for (int k = 0; k < numLinesTwo; k++) {
            String current = scanner.next();
            char task = current.charAt(0);                      //Parse String, Check First Letter
            switch (task) {                                      //Switch Statement
                case 'd':                                       //Call Delete
                    int delVal = scanner.nextInt();
                    treeTwo.delete(delVal);
                    break;
                case 'i':
                    int insertVal = scanner.nextInt();
                    treeTwo.insert(insertVal);
                    break;
            }
        }
        scanner.close();

        //Call Tree Compare
        if (compareTrees(treeOne.getRoot(), treeTwo.getRoot())) {
            System.out.print("The trees have the same shape.");
        } else {
            System.out.print("The trees do not have the same shape.");
        }

    }

    public static boolean compareTrees(Node<Integer> firstTree, Node<Integer> secondTree) {
        if (firstTree == null && secondTree == null) {
            return true;
        }
        if (firstTree == null || secondTree == null) {
            return false;
        }
        if (!compareTrees(firstTree.getLeftChild(), secondTree.getLeftChild())) {
            return false;
        }
        if (!compareTrees(firstTree.getRightChild(), secondTree.getRightChild())) {
            return false;
        }
        return true;
    }

}


