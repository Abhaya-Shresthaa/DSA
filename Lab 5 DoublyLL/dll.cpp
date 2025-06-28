#include<iostream>
using namespace std;

class Node{
  public:
    Node* next;
    Node* prev;
    int data;  
    Node(int val){
        next = prev = NULL;
        data = val;
    }
};

class List{
    public:
        Node* head;

        List(){
            head = NULL;
        }

        void pushFront(int val){
            Node* newNode = new Node(val);
            if (head == NULL){
                head = newNode;
            }
            else{
                newNode -> next = head;
                head -> prev = newNode;
                head = newNode;
            }
        }

        void pushBack(int val){
            Node* newNode = new Node(val);
            if (head == NULL){
                head = newNode;
            }
            else{
                Node* temp = head;
                while(temp -> next != NULL){
                    temp = temp -> next;
                }
                temp -> next = newNode;
                newNode -> prev = temp;
            }
        }

        void popFront(){
            if(head == NULL){
                cout << "List is empty" << endl;
                return;
            }
            else{
                Node* temp = head;
                head = head -> next;
                if(head != NULL){
                    head -> prev = NULL;
                }
                temp -> next = NULL;
                delete temp;
                
            }
        }

        void popEnd(){
            if(head == NULL){
                cout << "List is empty" << endl;
                return;
            }
            else{
                Node* temp = head;
                Node* prev = temp;
                while(temp->next != NULL){
                    temp = temp -> next;
                }
                prev = temp -> prev;
                prev -> next = NULL;
                temp -> prev = NULL;
                delete temp;
            }
        }
};

int main(){


    return 0;
}