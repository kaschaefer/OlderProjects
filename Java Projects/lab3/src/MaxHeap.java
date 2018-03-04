import java.util.InputMismatchException;

public class MaxHeap<E extends Comparable> {
    private E[] myArray;
    private int maxSize;
    private int length;


    public MaxHeap(int s) {
        // Build the constructor
        maxSize = s;
        length = 0;
        myArray = (E[]) new Comparable[maxSize + 1];
        myArray[0] = null;
    }

    // helper functions
    public E[] getArray() {

        return myArray;
    }

    private int left(int index) {
        //returns index of left child
        return (index * 2);
    }

    private int right(int index) {
        //return index of right child
        return ((index * 2) + 1);
    }

    public void setArray(E[] newArray) {
        if (newArray.length > maxSize+1) {
            return;
        }
        myArray = newArray;
        length = newArray.length - 1;
    }

    public int getMaxSize() {

        return maxSize;
    }

    public void setMaxSize(int ms) {

        maxSize = ms;
    }

    public int getLength() {

        return length;
    }

    public void setLength(int l) {

        length = l;
    }

    // Other Methods
    public void insert(E data) {
        //While array is not full
        if (length != maxSize) {
            //Insert the new Val
            length++;
            int index = length;
            myArray[index] = data;
            //Maintain Heap-order property
            while (index > 1 && myArray[index].compareTo(myArray[index / 2]) == 1) {
                E temp = myArray[index / 2];
                myArray[index / 2] = myArray[index];
                myArray[index] = temp;
                index = index / 2;
            }
        }
    }

    public Comparable<E> maximum() {

        return myArray[1];
    }

    public Comparable<E> extractMax() {
        if (getLength()!=0) {
            // remove and return the max value in the heap
            Comparable<E> returnVal = myArray[1];
            //replace the max value with the last element in the array
            myArray[1] = myArray[length];
            length = length - 1;
            //Maintain the Heap Property
            heapify(1);
            //Return the max Value
            return returnVal;
        }
        else {
          return null;
        }
    }

    public void heapify(int i) {
        // helper function for reshaping the array
        int left = left(i);
        int right = right(i);
        int largest = -1;
        if (left <= length && myArray[left].compareTo(myArray[i]) == 1) {
            largest = left;
        } else {
            largest = i;
        }
        if (right <= length && myArray[right].compareTo(myArray[largest]) == 1) {
            largest = right;
        }
        if (largest != i) {
            E temp = myArray[i];
            myArray[i] = myArray[largest];
            myArray[largest] = temp;
            heapify(largest);
        }
    }

    public void buildHeap(E[] newArr) {
            //Set the Array to the New UNSORTED array
            setArray(newArr);

            //Call Heapify on floor of length/2 down to 1
            for (int i = getLength() / 2; i > 0; i--) {
                heapify(i);
            }
    }
}
