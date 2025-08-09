#include<iostream>
using namespace std;

#define MAX 10

struct Node {
    int data;
    int next;
} node[MAX];

int head = -1;     // Points to the start of the list
int avail = 0;     // Points to the next available free node

// Initializes the node pool and sets all next pointers
void initializeList() {
    for (int i = 0; i < MAX; i++) {
        node[i].next = i + 1;
    }
    node[MAX - 1].next = -1;
    head = -1;
    avail = 0;
}

// Allocates a new node from the free list
int getNode() {
    if (avail == -1) {
        cout << "List Overflow\n";
        return -1;
    }
    int idx = avail;
    avail = node[avail].next;
    return idx;
}

// Frees a node and adds it back to the free list
void freeNode(int index) {
    node[index].next = avail;
    avail = index;
}

// Inserts a node at the beginning
void insertAtStart(int val) {
    int idx = getNode();
    if (idx == -1) exit(1);
    node[idx].data = val;
    node[idx].next = head;
    head = idx;
}

// Inserts a node at the end
void insertAtEnd(int val) {
    int idx = getNode();
    if (idx == -1) exit(1);
    node[idx].data = val;
    node[idx].next = -1;

    if (head == -1) {
        head = idx;
    } else {
        int temp = head;
        while (node[temp].next != -1) {
            temp = node[temp].next;
        }
        node[temp].next = idx;
    }
}

// Inserts a node after a specific value
void insertAfterValue(int val, int afterVal) {
    int idx = getNode();
    if (idx == -1) exit(1);

    int temp = head;
    while (temp != -1 && node[temp].data != afterVal) {
        temp = node[temp].next;
    }

    if (temp == -1) {
        cout << "Value " << afterVal << " not found\n";
        exit(1);
    }

    node[idx].data = val;
    node[idx].next = node[temp].next;
    node[temp].next = idx;
}

// Deletes the first node
void deleteFromStart() {
    if (head == -1) {
        cout << "List Underflow\n";
        exit(1);
    }
    int temp = head;
    head = node[head].next;
    freeNode(temp);
}

// Deletes the last node
void deleteFromEnd() {
    if (head == -1) {
        cout << "List Underflow\n";
        exit(1);
    }

    if (node[head].next == -1) {
        freeNode(head);
        head = -1;
        initializeList(); // Reset the list if empty
        return;
    }

    int temp = head;
    while (node[node[temp].next].next != -1) {
        temp = node[temp].next;
    }

    int last = node[temp].next;
    node[temp].next = -1;
    freeNode(last);
}

// Deletes the node after a specific value
void deleteAfterValue(int val) {
    if (head == -1) {
        cout << "List Underflow\n";
        exit(1);
    }

    int temp = head;
    while (temp != -1 && node[temp].data != val) {
        temp = node[temp].next;
    }

    if (temp == -1 || node[temp].next == -1) {
        cout << "No node to delete after value " << val << endl;
        return;
    }

    int toDelete = node[temp].next;
    node[temp].next = node[toDelete].next;
    freeNode(toDelete);
}

// Prints the current list
void printList() {
    int temp = head;
    while (temp != -1) {
        cout << node[temp].data << " => ";
        temp = node[temp].next;
    }
    cout << "NULL\n";
}

// Driver code with different values
int main() {
    initializeList();

    insertAtStart(8);
    insertAtEnd(18);
    insertAtStart(4);
    insertAtEnd(22);
    insertAfterValue(12, 18); // Insert 12 after 18
    printList(); // Expected: 4 => 8 => 18 => 12 => 22 => NULL

    deleteFromStart(); // deletes 4
    deleteFromEnd();   // deletes 22
    printList(); // Expected: 8 => 18 => 12 => NULL

    insertAfterValue(30, 12); // Insert 30 after 12
    insertAtStart(2); // Insert 2 at start
    printList(); // Expected: 2 => 8 => 18 => 12 => 30 => NULL

    deleteAfterValue(18); // deletes 12
    printList(); // Expected: 2 => 8 => 18 => 30 => NULL

    return 0;
}