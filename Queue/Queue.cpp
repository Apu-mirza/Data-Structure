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

void printQueue(que* q) {
    for (int i = q->front; i <= q->rear; i++) {
        cout << q->items[i] << " ";
    }
    cout << endl;
}

int main() {
    que* q = new que;
    createEmptyQueue(q, 5);
    EnQueue(q, 1);
    EnQueue(q, 2);
    EnQueue(q, 3);
    EnQueue(q, 4);
    EnQueue(q, 5);
    cout << "Queue after enqueued: ";
    printQueue(q);
    DeQueue(q);
    cout << "Queue after dequeued: ";
    printQueue(q);

    delete[] q->items; // Free the allocated memory
    delete q; // Free the structure

    return 0;
}
