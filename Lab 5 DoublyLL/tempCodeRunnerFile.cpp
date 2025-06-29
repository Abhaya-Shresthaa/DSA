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

class Queue{
    public:
        Node* head;
        Queue(){
            head = NULL;
        }

        void enqueue(int val){
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

        void dequeue(){
            if(head == NULL){
                cout << "Queue is already Empty" << endl;
                return;
            }
            Node* temp = head;
            while((temp->next)-> next != NULL){
                temp = temp -> next;
            }
            Node* prev = temp;
            temp = temp -> next;
            cout << temp->data << " is dequeued." << endl;
            prev-> next = NULL;
            delete temp;
        }

        void display(){
            if(head == NULL){
                cout << "Queue is Empty" << endl;
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

    Queue sll;
    sll.enqueue(10);
    sll.enqueue(20);
    sll.enqueue(30);
    sll.display();
    sll.dequeue();
    sll.dequeue();
    sll.display();

    return 0;
}