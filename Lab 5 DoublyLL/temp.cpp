#include <iostream>
using namespace std;

class Node{
    public:
        Node* next;
        int coeff;
        int power;
        Node(int co, int po){
            coeff = co;
            power = po;
            next = NULL;
        }
};

class Equations{
    public:
        Node* head;
        Equations(){
            head = NULL;
        }

        // void addVal(int co, int po){
        //     Node* newNode = new Node(co, po);
        //     if(head == NULL){
        //         head = newNode;
        //         return;
        //     }
        //     else{
        //         newNode ->next = head;
        //         head = newNode;
        //     }
        // }

        void addVal(int co, int po){
            Node* newNode = new Node(co, po);
            if(head == NULL){
                head = newNode;
                return;
            }
            Node* temp = head;
            while(temp->next != NULL){
                temp = temp->next;
            }
            temp -> next = newNode;
        }

        void display(){
            if(head == NULL){
                cout << "Equations is Empty" << endl;
                return;
            }
            Node* temp = head;
            while(temp != NULL){
                cout << temp->coeff << " x^" << temp->power ;
                temp = temp -> next;
                if(temp != NULL){
                    cout << " + ";
                }
            }
            cout << endl;
        }

        
};

Equations addEq(Equations &eqn1, Equations &eqn2){
    Node* temp1 = eqn1.head;
    Node* temp2 = eqn2.head;
    Equations final;
    while(temp1 != NULL && temp2 != NULL){
        if(temp1->power == temp2 -> power){
            final.addVal(temp1->coeff+temp2->coeff, temp1->power);
            temp1 = temp1->next;
            temp2 = temp2->next;

        }
        else if(temp1->power < temp2 -> power){
            final.addVal(temp1->coeff, temp1->power);
            temp1 = temp1->next;
        }
        else if(temp1->power > temp2 -> power){
            final.addVal(temp2->coeff, temp2->power);
            temp2 = temp2->next;
        }
    }
    while(temp1 != NULL){
        final.addVal(temp1->coeff, temp1->power);
        temp1 = temp1->next;
    }

    while(temp2 != NULL){
        final.addVal(temp2->coeff, temp2->power);
        temp2 = temp2->next;
    }
    return final;
}

int main(){

    Equations e1, e2, final;

    e1.addVal(10,2);
    e1.addVal(20,3);
    e1.addVal(30,4);
    e1.display();
    e2.addVal(5,3);
    e2.addVal(10,4);
    e2.addVal(15,5);
    e2.display();
    final = addEq(e1,e2);
    final.display();
    return 0;
}