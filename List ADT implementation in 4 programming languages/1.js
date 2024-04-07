class List {
    constructor() {
        this.head = null;
    }

    insert(val) {
        let newNode = {
            data: val,
            next: null
        };

        newNode.next = this.head;
        this.head = newNode;
    }

    display() {
        let current = this.head;
        while (current !== null) {
            process.stdout.write(current.data + " ");
            current = current.next;
        }
        process.stdout.write('\n');
    }
}