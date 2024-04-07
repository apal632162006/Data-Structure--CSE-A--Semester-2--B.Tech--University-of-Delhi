class PythonList {
    constructor() {
        this.items = [];
    }

    append(x) {
        this.items.push(x);
    }

    extend(iterable) {
        this.items.push(...iterable);
    }

    insert(i, x) {
        this.items.splice(i, 0, x);
    }

    remove(x) {
        const index = this.items.indexOf(x);
        if (index !== -1) {
            this.items.splice(index, 1);
        }
    }

    pop(i) {
        if (i === undefined) {
            return this.items.pop();
        } else {
            return this.items.splice(i, 1)[0];
        }
    }

    clear() {
        this.items = [];
    }

    index(x, start = 0, end = this.items.length) {
        return this.items.slice(start, end).indexOf(x);
    }

    count(x) {
        let count = 0;
        for (const item of this.items) {
            if (item === x) {
                count++;
            }
        }
        return count;
    }

    sort(key = null, reverse = false) {
        this.items.sort((a, b) => {
            if (key) {
                a = key(a);
                b = key(b);
            }
            if (a < b) return reverse ? 1 : -1;
            if (a > b) return reverse ? -1 : 1;
            return 0;
        });
    }

    reverse() {
        this.items.reverse();
    }

    copy() {
        return Object.assign(new PythonList(), this);
    }
}

// Example usage:
const myList = new PythonList();
myList.extend([1, 2, 3]);
console.log(myList.items);  // Output: [1, 2, 3]
myList.append(4);
console.log(myList.items);  // Output: [1, 2, 3, 4]
myList.remove(2);
console.log(myList.items);  // Output: [1, 3, 4]
console.log(myList.pop());  // Output: 4
console.log(myList.items);  // Output: [1, 3]
myList.clear();
console.log(myList.items);  // Output: []
