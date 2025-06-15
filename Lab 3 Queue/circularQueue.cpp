#include <iostream>
#define MAX 5


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
                throw std::overflow_error("Queue Overflow: Circular queue is full.");
            }
            if(isEmpty()){
                front = 0;
            }
            rear = (rear + 1) % MAX;
            queue[rear] = item;
        }
       
        T dequeue(){
            if(isEmpty()){
                throw std::underflow_error("Queue Underflow: Circular queue is empty.");
            }
            T item = queue[front];
            if(front == rear){ // Queue becomes empty after removing the last element
                front = rear = -1;
            } else {
                front = (front + 1) % MAX;
            }
            return item;
        }
       
        void display(){
            if(isEmpty()){
                std::cout << "Queue is empty.\n";
                return;
            }
            std::cout << "Circular Queue elements: ";
            int i = front;
            while(true){
                std::cout << queue[i] << " ";
                if(i == rear) break;
                i = (i + 1) % MAX;
            }
            std::cout << std::endl;
        }
};


int main(){
    CircularQueue<int> cq;


    cq.enqueue(10);
    cq.enqueue(20);
    cq.enqueue(30);
    cq.enqueue(40);
    cq.enqueue(50);


    std::cout << "Initial Queue: " << std::endl;
    cq.display();


    std::cout << "Dequeued: " << cq.dequeue() << std::endl;
    std::cout << "After Dequeue: " << std::endl;
    cq.display();


    cq.enqueue(60);
    std::cout << "After Enqueueing 60: " << std::endl;
    cq.display();


    return 0;
}
