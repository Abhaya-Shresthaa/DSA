#include <iostream>
#define MAX 5
using namespace std;

template<class T>
class CircularQueue{
    private:
        T queue[MAX];
        int front, rear;
    public:
        CircularQueue(){
            front = -1;
            rear = -1;
        }
       
        bool isEmpty(){
            return (front == -1);
        }
       
        bool isFull(){
            return ((rear + 1) % MAX == front);
        }
       
        void enqueue(T item){
            if(isFull()){
                throw overflow_error("Queue Overflow: Circular queue is full.");
            }
            if(isEmpty()){
                front = 0;
            }
            rear = (rear + 1) % MAX;
            queue[rear] = item;
            cout << "Item enqueued: " << queue[rear] << endl;
        }
       
        T dequeue(){
            if(isEmpty()){
                throw underflow_error("Queue Underflow: Circular queue is empty.");
            }
            T item = queue[front];
            cout << "Item dequeued: " << queue[front] << endl;
            if(front == rear){ // Queue becomes empty after removing the last element
                front = rear = -1;
            } else {
                front = (front + 1) % MAX;
            }
            return item;
        }
       
        void display(){
            if(isEmpty()){
                cout << "Queue is empty.\n";
                return;
            }
            cout << "Circular Queue elements: ";
            // int i = front;
            // while(true){
            //     cout << queue[i] << " ";
            //     if(i == rear) break;
            //     i = (i + 1) % MAX;
            // }
            // cout << endl;
            for (int i = 0;i<MAX;i++){
                if (queue[i]){
                    cout << queue[i]<< " ";
                }
            }
        }
};


int main(){
    CircularQueue<int> cq;

    int userInput;
    int enqueueInt;
    while (true)
    {
        cout << "Enter 1 for enqueue: "<< endl;
        cout << "Enter 2 for dequeue: "<< endl;
        cout << "Enter 3 for display: "<< endl;
        cout << "Enter 4 for exit: " << endl;
        cin >> userInput;

        switch(userInput){
            case 1:
                cout << "Enter a integer to enqueue: ";
                cin >> enqueueInt;
                cq.enqueue(enqueueInt);
                break;
            case 2:
                cq.dequeue();
                break;
            case 3:
                cq.display();
                break;
            case 4:
                return 0;
            default:
                cout<< "Invalid Choice: ";

        }
    }
    // cq.enqueue(10);
    // cq.enqueue(20);
    // cq.enqueue(30);
    // cq.enqueue(40);
    // cq.enqueue(50);


    // cout << "Initial Queue: " << endl;
    // cq.display();


    // cout << "Dequeued: " << cq.dequeue() << endl;
    // cout << "After Dequeue: " << endl;
    // cq.display();


    // cq.enqueue(60);
    // cout << "After Enqueueing 60: " << endl;
    // cq.display();


    return 0;
}
