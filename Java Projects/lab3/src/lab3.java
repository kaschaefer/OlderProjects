/**
 * Created by Kaela on 2/17/17.
 */

import java.util.Scanner;

public class lab3 {
    public static void main(String[] args) throws Exception {
        Scanner scanner = new Scanner(System.in);
        //Get number of lines
        int numLines = scanner.nextInt();
        //Create Priority Queue
        pQueue<Integer> priorityQueue = new pQueue<Integer>(numLines);
        int i = 0;
        while (!(numLines == 0) && i < numLines && scanner.hasNext()) {
            //Get Next Task
            String current = scanner.next();
            char task = current.charAt(0);
            switch (task) {
                case 'e':
                    //Call extractMax
                    System.out.println(priorityQueue.extractMax());
                    break;
                case 'm':
                    //Call maximum
                    System.out.println(priorityQueue.maximum());
                    break;
                case 'i':
                    //Call Insert
                    if (current.charAt(1) == 'n') {
                        priorityQueue.insert(scanner.nextInt());
                    }
                    //Call isEmpty
                    else {
                        if (priorityQueue.isEmpty()) {
                            System.out.println("Empty");
                        } else {
                            System.out.println("Not Empty");
                        }
                    }
                    break;
                case 'p':
                    //Call print
                    priorityQueue.print();
                    break;
                case 'b':
                    //Get Input for the array
                    String input;
                    //Making Sure the Scanner Still has Input
                    if (scanner.hasNextLine()) {
                        input = scanner.nextLine();
                        input = input.replaceAll("\\[", "").replaceAll("\\]", "");
                        input = input.replaceAll(" ", "");
                    }
                    else {
                        //The scanner is empty, something went wrong.
                        break;
                    }

                    String[] inputs = input.split(",");
                    Integer[] inputVals = new Integer[inputs.length + 1];
                    for (int k = 0; k < inputs.length; k++) {
                        inputVals[k+1] = Integer.parseInt(inputs[k]);
                    }
                    priorityQueue.build(inputVals);
                    break;
            }
            i++;
        }
        scanner.close();
    }
}