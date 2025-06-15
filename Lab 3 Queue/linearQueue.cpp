#include <iostream>
#define MAX 5
using namespace std;
template <class T>
class Queue{
    private:
        T queue[MAX];
        int front, rear;
    public:
        Queue(){
            front = -1;
            rear = -1;
        }
        void enqueue(T item){
            if(isFull()){
                std::cout << "Queue is full" << std::endl;
                return;
            }
            if(isEmpty()){
                front = rear = 0;
            }
            else{
                rear++;
            }
            queue[rear] = item;
            std::cout << "Item enqueued: " << queue[rear] << std::endl;
        }


        void dequeue(){
            if(isEmpty()){
                std::cout<< "Queue is empty, nothing to dequeue" << std::endl;
                return;
            }
            std::cout << "Item dequeued: "<< queue[front] << std::endl;
            if(front == rear){
                front = rear = -1;
            }
            else{
                front++;
            }
        }
        void display(){
            printf("front = %d\t back = %d\n", front, rear);
            if(isEmpty()){
                cout << "Queue is empty" << endl;
                return;
            }


            cout << "The elements of queue are: " << endl;
            for(int i = front; i <= rear; i++){
                cout << queue[i] << " "; // Fix applied here
            }
            cout << endl;
        }


        inline bool isEmpty(){
            return(front == -1 && rear == -1);
        }


        inline bool isFull(){
            return(rear == MAX - 1);
        }
};
int main(){
    Queue<std::string> tasks;
    int userInput;
    string enqueueString;
    while (true)
    {
        cout << "Enter 1 for enqueue: "<< endl;
        cout << "Enter 2 for dequeue: "<< endl;
        cout << "Enter 3 for display: "<< endl;
        cout << "Enter 4 for exit: " << endl;
        cin >> userInput;

        switch(userInput){
            case 1:
                cout << "Enter a string to enqueue: ";
                cin >> enqueueString;
                tasks.enqueue(enqueueString);
                break;
            case 2:
                tasks.dequeue();
                break;
            case 3:
                tasks.display();
                break;
            case 4:
                return 0;
            default:
                cout<< "Invalid Choice: ";

        }
    }
    
    return 0;
}
