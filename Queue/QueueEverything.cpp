#include<iostream>
using namespace std;

struct Queue {
    int* items;
    int front, rear, maxSize;
};

typedef struct Queue que;

void createEmptyQueue(que* q, int maxSize) {
    q->front = -1;
    q->rear = -1;
    q->maxSize = maxSize;
    q->items = new int[maxSize];
}

bool isFull(que* q) {
    return q->rear == q->maxSize - 1;
}

bool isEmpty(que* q) {
    return q->front == -1;
}

void EnQueue(que* q, int n) {
    if (isFull(q)) {
        cout << "Can't Enqueue, The Queue is already full" << endl;
    } else {
        if (isEmpty(q)) q->front = 0;
        q->rear++;
        q->items[q->rear] = n;
    }
}

void DeQueue(que* q) {
    if (isEmpty(q)) {
        cout << "Can't dequeue, the queue is already empty" << endl;
    } else {
        cout << "Item dequeued: " << q->items[q->front] << endl;
        q->front++;
    }
}
void peek(que* q){
    if(isEmpty(q)){
        cout<<"Can't peek, The Queue is already empty"<<endl;
    }else{
        cout<<q->items[q->front]<<endl;
    }
}
void printQueue(que* q) {
    cout<<"Queue: ";
    for (int i = q->front; i <= q->rear; i++) {
        cout << q->items[i] << " ";
    }
    cout << endl;
}

int main() {
    que* q = new que;
    cout<<"Enter the size of the Queue: ";
    int queSize;
    cin>>queSize;
    createEmptyQueue(q, queSize);
    while(true){
        int choose, value;
        cout<<"Choose: 1 to EnQueue, 2 to DeQueue, 3 to Peek, 4 to Exit: ";
        cin>>choose;
        if(choose == 1){
            cout<<"Enter the value to EnQueue: ";
            cin>>value;
            EnQueue(q, value);
        }else if(choose == 2){
            DeQueue(q);
        }else if(choose == 3){
            cout<<"Item Picked: ";
            peek(q);
        }else if(choose == 4) {break;}
        else{
            cout<<"Invalid Choice, please enter 0, 1, 2 or 3"<<endl;
        }
        printQueue(q);
    }

    delete[] q->items; // Free the allocated memory
    delete q; // Free the structure

    return 0;
}

