public class List<T> {
    private class Node {
        T data;
        Node next;

        public Node(T val) {
            data = val;
            next = null;
        }
    }

    private Node head;

    public List() {
        head = null;
    }

    public void insert(T val) {
        Node newNode = new Node(val);
        newNode.next = head;
        head = newNode;
    }

    public void display() {
        Node current = head;
        while (current != null) {
            System.out.print(current.data + " ");
            current = current.next;
        }
        System.out.println();
    }
}