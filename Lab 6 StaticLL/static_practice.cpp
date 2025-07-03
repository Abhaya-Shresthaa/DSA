#include<iostream>
using namespace std;

#define MAX 10
struct Node{
    int data;
    int next;
}node[MAX];

int list = -1;
int avail = 0;

//sabai nodes lo next ma incremental value
void initializeNodes(){
    for( int i = 0; i < MAX; i++){
        node[i].next = i+1;
    }
    node[MAX-1].next = -1;
    list = -1;
    avail = 0;
}

//create or link a node from here
int getNode(){
    if(avail == -1){
        cout << "Overflow";
        return -1;
    }
    int index = avail;
    avail = node[avail].next;
    return index;
}

// deleting a node (node ko next ma avail halera avail lai index ma point garni)
void freeNodes(int index){
    node[index].next =avail;
    avail = index;
}

void insertBeg(int val){
    int index = getNode();
    if (index == -1) exit(1); //exit if full;
    node[index].data = val;

    //checks if empty
    if( list == -1){
        list = index;
        node[index].next = -1;
    }
    else{
        node[index].next = list;
        list = index;
    }
}

void insertEnd(int val){
    int index = getNode();
    if (index == -1) exit(1);
    node[index].data = val;
    node[index].next = -1;
    if( list == -1){
        list = index;
    }
    else{
        int temp = list;
        while(node[temp].next != -1){
            temp = node[temp].next;
        }
        node[temp].next = index;
        
    }
}

void insetAtSpecific(int val, int specificVal){
    int index = getNode();
    if(index == -1) exit(1);

    int temp = list;
    while(temp != -1 && node[temp].data != specificVal){
        temp = node[temp].next;
    }
    if(temp == -1){
        cout << "Specific val not found"<< endl;
        exit(1);
    }
    node[index].data = val;
    node[index].next = node[temp].next;
    node[temp].next = index;
}

void deleteBeg(){
    if(list == -1){
        cout << "underFlow"<<endl;
        exit(1);
    }
    if(node[list].next == -1){
        freeNodes(list);
        list = -1;
        cout << "list is empty now";
        initializeNodes();
        return;
    }
    int temp = list;
    list = node[list].next;
    freeNodes(temp);
}

void deletEnd(){
    if(list == -1){
        cout << "underFlow"<<endl;
        exit(1);
    }
    if(node[list].next == -1){
        freeNodes(list);
        list = -1;
        cout << "list is empty now";
        initializeNodes();
        return;
    }
    int temp = list;
    while (node[node[temp].next].next != -1){
        temp = node[temp].next;
    }
    int lastNode = node[temp].next;
    node[temp].next = -1;
    freeNodes(lastNode);


}

void display(){
        int temp = list;
        while(temp != -1){
            cout << node[temp].data << " => " ;
            temp = node[temp].next;
        }
        cout << "NULL" << endl;
}


int main(){
    initializeNodes();
    insertBeg(10);
    insertBeg(20);
    insertEnd(30);
    insertEnd(40);
    insertEnd(50);
    insetAtSpecific(60,40);
    display();
    deleteBeg();
    deletEnd();
    display();
    return 0;
}