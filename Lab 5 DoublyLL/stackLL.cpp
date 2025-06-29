#include <iostream>
using namespace std;

class Node{
    public:
        Node* next;
        int data;
        Node(int val){
            data = val;
            next = NULL;
        }
};

class Stack{
    public:
        Node* head;
        Stack(){
            head = NULL;
        }

        void push(int val){
            Node* newNode = new Node(val);
            if(head == NULL){
                head = newNode;
                return;
            }
            else{
                newNode ->next = head;
                head = newNode;
            }
        }

        void pop(){
            if(head == NULL){
                cout << "Stack is already Empty" << endl;
                return;
            }
            Node* temp = head;
            head = head -> next;
            temp -> next = NULL;
            delete temp;
        }

        void display(){
            if(head == NULL){
                cout << "Stack is Empty" << endl;
                return;
            }
            Node* temp = head;
            while(temp != NULL){
                cout << temp->data << " | " ;
                temp = temp -> next;
            }
            cout << endl;
        }
};

int main(){

    Stack sll;
    sll.push(10);
    sll.push(20);
    sll.push(30);
    sll.display();
    sll.pop();
    sll.display();
    sll.push(40);
    sll.display();

    return 0;
}