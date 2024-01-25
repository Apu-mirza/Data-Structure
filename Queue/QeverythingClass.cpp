#include<iostream>
using namespace std;

class Queue{
private:
    int size, *items, front, rear;

public:
    Queue(int maxSize){
        int size = maxSize;
        items = new int[size];
        front = -1;
        rear = -1;
    }
    bool isFull(){
        if(front == 0 && rear == size-1){
            return true;
        }else return false;
    }
    bool isEmpty(){
        if(front == -1){
            return true;
        }else{
            return false;
        }
    }
    void EnQueue(int newItem){
        if(isFull()){
            cout<<"Can't Enqueue, The Queue is already full."<<endl;
        }else{
            if(front == -1) front = 0;
            rear++;
            items[rear] = newItem;
            cout<<endl<<newItem<<" is inserted"<<endl;
        }
    }
    void DeQueue(){
        if(isEmpty()){
            cout<<"Can't DeQueue, The Queue is already Empty."<<endl;
        }else{
            cout<<"Item DeQueued: "<<items[front]<<endl;
            if (front >= rear) {
                front = -1;
                rear = -1;
            }else{
                front++;
            }
        }
    }
    void printQueue(){
        cout<<"Queue: "<<endl;
        for(int i=front; i<=rear; i++){
            cout<<items[i]<<" ";
        }cout<<endl;
    }
    void peek(){
        if(isEmpty()){
            cout<<"Can't peek, the queue is already empty"<<endl;
        }else{
            int selected = items[front];
            cout<<"Item peeked: "<<selected<<endl;
        }
    }

};
int main()
{
    int maxSize, value;
    cout<<"Enter the size of the Queue: ";
    cin>>maxSize;
    Queue que(maxSize);
    while(true){
        cout<<"Choose: 1. Enqueue, 2.DeQueue, 3.Peek, 4.Exit: ";
        int choose;
        cin>>choose;
        if(choose == 1){
            cout<<"Enter value to Enqueue: ";
            cin>>value;
            que.EnQueue(value);
        }else if(choose == 2){
            que.DeQueue();
        }else if(choose == 3){
            que.peek();
        }else if(choose == 4){
            break;
        }else{
            cout<<"Invalid Input, please enter 1, 2, 3 or 4."<<endl;
        }
        que.printQueue();
    }
}
