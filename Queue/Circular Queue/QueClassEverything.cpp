#include<iostream>
using namespace std;

class Queue{
private:
    int qSize, *items, front, rear;

public:
    Queue(int maxSize){
        int qSize = maxSize;
        items = new int[qSize];
        front = -1;
        rear = -1;
    }
    bool isFull(int queSize){
        int qSize = queSize;
        if(front == 0 && rear == qSize-1){
            return true;
        }
        return false;
    }
    bool isEmpty(){
        if(front == -1){
            return true;
        }else{
            return false;
        }
    }
    void EnQueue(int newItem, int queSize){
        int qSize = queSize;
        if(isFull(qSize)){
            cout<<"Can't Enqueue, The Queue is already full."<<endl;
        }else{
            if(front == -1) front = 0;
            cout<<"Size = "<<qSize<<endl;
            rear = (rear+1)%qSize;
            items[rear] = newItem;
            cout<<endl<<newItem<<" is inserted"<<endl;
        }
    }
    void DeQueue(int queSize){
        int qSize = queSize;
        if(isEmpty()){
            cout<<"Can't DeQueue, The Queue is already Empty."<<endl;
        }else{
            cout<<"Item DeQueued: "<<items[front]<<endl;
            if (front >= rear) {
                front = -1;
                rear = -1;
            }else{
                front = (front+1)%qSize;
            }
        }
    }
    void printQueue(int queSize){
        int qSize = queSize;
        if(isEmpty())cout<<"The queue is empty"<<endl;
        else{
            cout<<"Queue: "<<endl;
            for(int i=front; i<=rear; i=(i+1)%qSize){
                cout<<items[i]<<" ";
            }cout<<endl;
        }
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
            que.EnQueue(value,maxSize);
        }else if(choose == 2){
            que.DeQueue(maxSize);
        }else if(choose == 3){
            que.peek();
        }else if(choose == 4){
            break;
        }else{
            cout<<"Invalid Input, please enter 1, 2, 3 or 4."<<endl;
        }
        que.printQueue(maxSize);
    }
}

