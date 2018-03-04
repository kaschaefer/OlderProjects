public class pQueue<E extends Comparable> {
    private MaxHeap myHeap;

    public pQueue(int s) {
        myHeap = new MaxHeap(s);
    }

    public void insert(E data) {

        myHeap.insert(data);
    }

    public Comparable<E> maximum() {

        return myHeap.maximum();
    }

    public Comparable<E> extractMax() {

        return myHeap.extractMax();
    }

    public boolean isEmpty() {

        return (myHeap.getLength() == 0);
    }

    public void build(E[] arr) {

        myHeap.buildHeap(arr);
    }


    public void print() {
        System.out.print("Current Queue: ");
        //If the array is empty, do not try to print it
        if (isEmpty()) {
            System.out.print("is empty.");
            System.out.println();
        } else {
            //Get array
            Comparable[] temp = myHeap.getArray();
            //Print each element
            for (int i = 1; i <= myHeap.getLength(); i++) {
                if (i == myHeap.getLength()) {
                    System.out.print(temp[i]);
                    System.out.println();
                } else {
                    System.out.print(temp[i] + ",");
                }
            }

        }
    }
}