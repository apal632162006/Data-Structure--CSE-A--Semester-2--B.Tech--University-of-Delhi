import java.util.ArrayList;
import java.util.Collections;
import java.util.List;

public class PythonListADT<T> {
    private List<T> list;

    public PythonListADT() {
        this.list = new ArrayList<>();
    }

    public void append(T x) {
        list.add(x);
    }

    public void extend(Iterable<? extends T> iterable) {
        for (T item : iterable) {
            list.add(item);
        }
    }

    public void insert(int i, T x) {
        list.add(i, x);
    }

    public void remove(T x) {
        list.remove(x);
    }

    public T pop() {
        return pop(list.size() - 1);
    }

    public T pop(int i) {
        if (i < 0 || i >= list.size()) {
            throw new IndexOutOfBoundsException("Index out of range");
        }
        return list.remove(i);
    }

    public void clear() {
        list.clear();
    }

    public int index(T x) {
        return list.indexOf(x);
    }

    public int index(T x, int start) {
        return list.subList(start, list.size()).indexOf(x);
    }

    public int index(T x, int start, int end) {
        return list.subList(start, end).indexOf(x);
    }

    public int count(T x) {
        int count = 0;
        for (T item : list) {
            if (item.equals(x)) {
                count++;
            }
        }
        return count;
    }

    public void sort() {
        Collections.sort(list);
    }

    public void sort(boolean reverse) {
        if (reverse) {
            Collections.sort(list, Collections.reverseOrder());
        } else {
            Collections.sort(list);
        }
    }

    public void sort(java.util.Comparator<? super T> comparator) {
        Collections.sort(list, comparator);
    }

    public void reverse() {
        Collections.reverse(list);
    }

    public PythonListADT<T> copy() {
        PythonListADT<T> newList = new PythonListADT<>();
        newList.extend(list);
        return newList;
    }

    @Override
    public String toString() {
        return list.toString();
    }

    public static void main(String[] args) {
        PythonListADT<Integer> myList = new PythonListADT<>();
        myList.append(1);
        myList.append(2);
        myList.append(3);
        System.out.println("Original List: " + myList);
        
        myList.extend(List.of(4, 5));
        System.out.println("After extending: " + myList);
        
        myList.insert(2, 10);
        System.out.println("After inserting: " + myList);
        
        myList.remove(2);
        System.out.println("After removing: " + myList);
        
        System.out.println("Popped item: " + myList.pop());
        System.out.println("After popping: " + myList);
        
        myList.clear();
        System.out.println("After clearing: " + myList);
        
        myList.append(1);
        myList.append(2);
        myList.append(3);
        myList.append(2);
        System.out.println("Index of 2: " + myList.index(2));
        System.out.println("Count of 2: " + myList.count(2));
        
        myList.sort();
        System.out.println("After sorting: " + myList);
        
        myList.reverse();
        System.out.println("After reversing: " + myList);
        
        PythonListADT<Integer> copiedList = myList.copy();
        System.out.println("Copied list: " + copiedList);
    }
}
