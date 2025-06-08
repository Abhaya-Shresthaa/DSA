#pragma once
#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Stack {
    int top;
    int Size;
    vector<string> elements;

public:
    Stack(int capacity) : top(-1), Size(capacity) {
        elements.resize(capacity);
    }

    bool isEmpty() const {
        return top == -1;
    }
    bool isFull() const {
        return top == Size - 1;
    }

    int size()
    {
        return top + 1;
    }

    string peek() const 
    {
        if (isEmpty()) 
        {
            cerr << "Stack is empty: Cannot peek\n";
            return '\0';
        } 
        return elements[top];
    }
    

    void push(string ch) {
        if (isFull()) {
            cerr << "Stack overflow: Cannot push\n";
            return;
        }
        elements[++top] = ch;
    }

    string pop() {
        if (isEmpty()) {
            cerr << "Stack underflow: Cannot pop from empty stack\n";
            return '\0';
        }
            // return the top element, then decrement top
            return elements[top--];
        }

    void display() const {
        if (isEmpty()) {
            cerr << "Stack Empty, nothing to display!\n";
            return;
        }
        cout << "Stack Contents: ";
        for (int i = 0; i <= top; i++) {
            cout << elements[i]<<" ";
        }
        cout << endl;
    }
};
