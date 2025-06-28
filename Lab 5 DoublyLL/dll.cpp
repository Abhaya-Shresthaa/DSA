#include<iostream>
using namespace std;

class Node{
    public:
    Node* next;
    Node* prev;
    int data;
    Node(int val): data(val), next(NULL){}
};

class DoublyList{
    public:
    Node* head;
    Node* tail;

    DoublyList(){
        head = tail = NULL;
    }

    void pushFront(int val){
        Node* newNode = new Node(val);

        if(head == NULL){
            head = tail =newNode;
        }
        else {
            newNode-> next = head;
            head ->prev = newNode;
            head = newNode;
        }
    }

    void pushBack(int val){
        Node* newNode = new Node(val);
        Node* temp = head;
        if (head == NULL){
            head = tail = newNode;
        }
        else{
            newNode -> next = NULL;
            while(temp -> next != NULL){
                temp = temp -> next;
            }
            newNode -> prev = temp;
            temp ->next = newNode;
            tail = newNode;

        }
    }

    void popFront(){
        if(head == NULL){
            cout << "List is empty" << endl;
            return;
        }
        
        Node* temp = head;
        head = head -> next;

        if(head != NULL){
            head ->prev = NULL;
        }

        temp ->next = NULL;
        delete temp;
        
    }

    // without using tail 
    void popBack(){
        if(head == NULL){
            cout << "List is empty" << endl;
            return;
        }

        Node* temp = head;
        Node* prev = NULL;
        while((temp->next) != NULL){
            temp = temp->next;
        }
        prev = temp -> prev;
        prev -> next = NULL;
        temp ->prev = NULL;
        delete temp;
    }

    // using tail

    void usingTailPopBack(){

        if(head == NULL){
            cout << "List is empty" << endl;
            return;
        }

        Node* temp = tail;
        tail = tail-> prev;
        if(tail != NULL){
            tail -> next = NULL;
        }
        temp -> prev = NULL;
        delete temp;


    }

    void display(){
        Node* temp = head;
        while(temp != NULL){
            cout << temp->data << " <=> " ;
            temp = temp ->next;
        }
        cout << "NULL" << endl;
    }
};

int main(){
    DoublyList ll;
    ll.pushFront(10);
    ll.pushFront(20);
    ll.pushFront(30);
    ll.pushBack(40);
    ll.pushBack(50);
    ll.popBack();

    ll.display();

    return 0;
}