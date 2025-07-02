#include <iostream>
using namespace std;

struct nodeType{
    int data;
    int next = -2;
}node[5];

static int avail = 0;
static int list = -1;

// int getNode(){
//     int index;
//     if(avail == -1){
//         cout << "array is full" << endl;
//         exit(1);
//     }
//     index = avail;
//     avail = node[avail].next;
//     return index;
// }

void insertAtBeg(int val){
    int index = avail;
    if(avail == -1){
        cout << "list is full" << endl;
        exit(1);
    }
    if(list == -1){
        node[index].data = val;
        avail = avail+1;
        node[index].next = -1;
        list = index;
        return;
    }
    node[index].data = val;
    if(node[avail].next != -2){
        avail = node[index].next;
    }
    else{
        if(avail == 4){
            avail = -1;
        }
        else{
            avail = avail+1;
        }
    }
    node[index].next = list;
    list = index;
}

void insertAtEnd(int val){
    int index = avail;
    if(avail == -1){
        cout << "list is full" << endl;
        exit(1);
    }
    if(list == -1){
        node[index].data = val;
        avail = avail+1;
        node[index].next = -1;
        list = index;
        return;
    }
    node[index].data = val;
    int num = list;
    while(node[num].next != -1){
        num = node[num].next;
    }
    node[num].next = index;

    if(node[avail].next != -2){
        avail = node[index].next;
    }
    else{
        if(avail == 4){
            avail = -1;
        }
        else{
            avail = avail+1;
        }
    }
    node[index].next = -1;
}

void deleteBegg(){
    if(list == -1){
        cout << "list is already empty";
        exit(1);
    }
    
    int index = list;
    list = node[list].next;
    avail = index;
}

void display(){
    int num = list;
    while(num != -1){
        cout << node[num].data<<endl;
        num = node[num].next;
    }
}

int main(){
    insertAtBeg(10);
    insertAtBeg(20); 
    insertAtEnd(30); 
    insertAtEnd(40); 
    insertAtEnd(50); 

    display();
    //cout << node[list].data << endl << node[node[list].next].data <<endl;
    //cout << node[list].next << endl << node[node[list].next].next<< endl;
    //cout << list << endl;
    return 0;
}