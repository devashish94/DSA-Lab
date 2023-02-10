package LinkedList.SingleLinkedList;

class Node {
    public int data;
    String value;
    Node next;
}

public class SingleLinked {
    private Node head;
    private Node tail;
    int length;

    /* prints the linked list from start to end and adds a null in the end, to show the end of the list */
    public void show() {
        // check for the list empty
        if (head == null) {
            System.out.println("null");
            return;
        }
        if (head.next == null) {
            if (head.value == null) {
                System.out.println(getFirst() + " -> null");
                return;
            }
        }
        Node temp = head;
        while (temp != null) {
            if (temp.value == null) {
                System.out.print(temp.data + " -> ");
            }
            else System.out.print(temp.value + " -> ");
            temp = temp.next;
        }
        System.out.println("null");
    }

    /* Prints the linked list using a given head */
    public void show(Node val) {
        Node firstNode = val;
        while (firstNode != null) {
            System.out.print(firstNode.data + " -> ");
            firstNode = firstNode.next;
        }
        System.out.println("null");
    }

    /* Returns the node at the specific index */
    public Node getNode(int index) {
        Node node = head;
        int count = 0;
        while (count != index && node.next != null) {
            count++;
            node = node.next;
        }
        return node;
    }

    /* Returns the reference of the head node */
    public Node getHead() {
        Node temp = head;
        return temp;
    }

    /* Returns the First element of the Linked List */
    public int getFirst() {
        return head.data;
    }

    /* Returns the Last element of the Linked List */
    public int getLast() {
        return tail.data;
    }

    /* Prints the data at the given index  */
    public int get(int index) {
        // check if list is empty
        if (head == null) {
            System.out.println("List empty");
            return 404;
        }
        if (index == 0) {
            return getFirst();
        }
        if (index == length) {
            return getLast();
        }
        // check if list index out of bounds
        if (index > length - 1 || index < 0) {
            return 404;
        }

        // traverse to the required index
        Node temp = head;
        int count = 0;
        while (count != index && temp.next != null) {
            count++;
            temp = temp.next;
        }
        return temp.data;
    }

    /* Adds element before the first node */
    public void addFirst(int data) {
        Node node = new Node();
        node.data = data;
        node.next = head;
        head = node;
        if (tail == null) {
            tail = head;
        }
        length++;
    }

    /* Adds the received integer data in the end of the linked list */
    public void add(int data) {
        Node node = new Node();
        node.data = data;
        node.next = null;
        length++;

        // if list was empty then after creating the first node set head to that new node
        if (head == null) {
            head = node;
            tail = head;
            return;
        }
        /* if the list was NOT empty then
        *  set the next in tail to the new node
        *  and set the tail to the new node */
        tail.next = node;
        tail = node;
    }

    /* Adds the received String data in the end of the linked list */
    public void add(String data) {
        Node node = new Node();
        node.value = data;
        node.next = null;
        length++;

        //if list was empty then after creating the first node set head to that new nodes location
        if (head == null) {
            head = node;
            tail = node;
            return;
        }
        /* if the list was NOT empty then
         *  set the next in tail to the new node
         *  and set the tail to the new node */
        tail.next = node;
        tail = node;
    }

    /* Adds a node at a particular index provided as a parameter */
    public void add(int index, int data) {
        Node node = new Node();
        node.data = data;

        if (index == 0) {
            addFirst(data);
            return;
        }
        if (index == length) {
            add(data);
            return;
        }
        // check if list is empty
        if (head == null) {
            System.out.println("List is empty");
            return;
        }
        // check if list index out of bounds
        if (index > length - 1 || index < 0) {
            System.out.println("List index out of bounds");
            return;
        }
        // traverse to the required index
        Node forward = head;
        int count = 0;
        while (count != index - 1 && forward.next != null) {
            count++;
            forward = forward.next;
        }
        if (forward == tail) {
            tail = forward.next;
        }
        node.next = forward.next;
        forward.next = node;
        length++;
    }

    /* Removes the First Node */
    public void removeFirst() {
        if (head == null) {
            System.out.println("List is Empty.");
            tail = null;
            return;
        }
        head = head.next;
        /* Adjust tail pointer if there was only one element
        *  in the linked list and we deleted that too */
        if (head == null) {
            /* I checked head for null again because in the previous
            *  line, I moved the head to the next location so it should
            *  be null now */
            tail = null;
        }
        length--;
    }

    /* Removes the Last node */
    public void removeLast() {
        if (head == null) {
            System.out.println("List is Empty");
            tail = null;
            return;
        }
        tail = getNode(length - 2);
        tail.next = null;
        length--;
    }

    /* Removes the node on the specified index */
    public void remove(int index) {
        if (head == null) {
            System.out.println("List is Empty");
            return;
        }
        if (index == 0) {
            removeFirst();
            return;
        }
        if (index == length - 1) {
            removeLast();
            return;
        }
        if (index < 0 || index >= length) {
            System.out.println("List index out of bounds");
            return;
        }
        int count = 0;

        Node previous_node = getNode(index - 1);
        previous_node.next = previous_node.next.next;

        Node current_node = getNode(index);
        current_node = null;
        length--;
    }
    public static void main(String[] args) {
        SingleLinked list = new SingleLinked();
        for (int i = 0; i < 5; i++) {
            list.add(i, i + 1);
        }
        list.show();
        list.removeLast();
        list.removeFirst();
        System.out.println(list.length);
        list.remove(5);
        list.show();
    }
}
