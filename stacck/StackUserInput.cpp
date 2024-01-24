#include<iostream>
using namespace std;

int size=0;

struct stack
{
    int *items;
    int top;
};

typedef struct stack st;
void createEmptyStack(st *s, int maxSize){
    s->top = -1;
    s->items = new int[maxSize];
}
bool isEmpty(st *s)
{
    if(s->top == -1){
        cout<<"The stack is already empty"<<endl;
        return true;
    }else return false;
}
bool isFull(st *s, int maxSize)
{
    if(s->top == maxSize-1){
        cout<<"The stack is already full"<<endl;
        return true;
    }else return false;
}
void push(st *s,int maxSize, int newItem)
{
    if(isFull(s, maxSize)){

    }else{
        s->top++;
        s->items[s->top] = newItem;
    }
    size++;
}
void pop(st *s)
{
    if(isEmpty(s)){

    }else{
        cout << "Item popped= " << s->items[s->top];
        s->top++;
    }
    size--;
    cout<<endl;
}

void printStack(st *s)
{
    cout<<"Stack: ";
    for(int i=0; i<size; i++){
        cout<<s->items[i]<<" ";
    }
    cout<<endl;
}

int main()
{
    int ch;
    st *s = (st *)malloc(sizeof(st));
    cout << "Enter the desired size of the stack: ";
    int max;
    cin >> max;

    createEmptyStack(s, max);
    int n, i=0;
    cout<<"Enter your desired input in stack: ";
    while(i<max){
        cin>>n;
        if(n != 0){
            push(s, max, n);
        }
        i++;
    }
    cout<<"After pushing in: \n";
    printStack(s);

    return 0;
}
