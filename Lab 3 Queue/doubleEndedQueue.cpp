#include <iostream>
using namespace std;

#define SIZE 10  // Maximum size of deque

class Deque {
private:
    int arr[SIZE];
    int front, rear;

public:
    Deque() {
        front = -1;
        rear = -1;
    }

    // Check if deque is full
    bool isFull() {
        return ((front == 0 && rear == SIZE - 1) || (front == rear + 1));
    }

    // Check if deque is empty
    bool isEmpty() {
        return (front == -1);
    }

    // a. Add at beginning
    void addFront(int value) {
        if (isFull()) {
            cout << "Deque is full\n";
            return;
        }

        if (isEmpty()) {
            front = rear = 0;
        } else if (front == 0) {
            front = SIZE - 1;
        } else {
            front--;
        }
        arr[front] = value;
    }

    // b. Add at end
    void addRear(int value) {
        if (isFull()) {
            cout << "Deque is full\n";
            return;
        }

        if (isEmpty()) {
            front = rear = 0;
        } else if (rear == SIZE - 1) {
            rear = 0;
        } else {
            rear++;
        }
        arr[rear] = value;
    }

    // c. Delete from beginning
    void deleteFront() {
        if (isEmpty()) {
            cout << "Deque is empty\n";
            return;
        }

        cout << "Deleted from front: " << arr[front] << endl;
        if (front == rear) {
            front = rear = -1; // deque becomes empty
        } else if (front == SIZE - 1) {
            front = 0;
        } else {
            front++;
        }
    }

    // d. Delete from end
    void deleteRear() {
        if (isEmpty()) {
            cout << "Deque is empty\n";
            return;
        }

        cout << "Deleted from rear: " << arr[rear] << endl;
        if (front == rear) {
            front = rear = -1; // deque becomes empty
        } else if (rear == 0) {
            rear = SIZE - 1;
        } else {
            rear--;
        }
    }

    // Display the deque
    void display() {
        if (isEmpty()) {
            cout << "Deque is empty\n";
            return;
        }

        cout << "Deque elements: ";
        int i = front;
        while (true) {
            cout << arr[i] << " ";
            if (i == rear)
                break;
            i = (i + 1) % SIZE;
        }
        cout << endl;
    }
};

int main() {
    Deque dq;

    dq.addFront(10);
    dq.addFront(20);
    dq.display();

    dq.addRear(30);
    dq.addRear(40);
    dq.display();

    dq.deleteFront();
    dq.display();

    dq.deleteRear();
    dq.display();

    return 0;
}