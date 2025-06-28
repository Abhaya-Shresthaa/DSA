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
            }
        }
};

int main(){


    return 0;
}