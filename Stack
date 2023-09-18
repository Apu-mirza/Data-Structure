#include<iostream>

using namespace std;

#define MAX 10
int size = 0;

struct stack{
    int items[MAX];
    int top;
};

typedef struct stack st;

void createEmptyStack(st *s)
{
    s->top = -1;
}

int isFull(st *s)
{
    if(s->top == MAX-1){
        return 1;
    }else return 0;
}

int isEmpty(st *s)
{
    if(s->top == -1)
        return 1;
    else return 0;
}

void push(st *s, int n)
{
    if(isFull(s)){
        cout<<"Stack Full"<<endl;
    }else
    {
        s->top++;
        s->items[s->top] = n;
    }
    size++;
}

void pop(st *s)
{
    if(isEmpty(s)){
        cout<<"The stack is already empty"<<endl;
    }else{
        cout<<"item popped: "<<s->items[s->top];
        s->top--;
    }
    cout<<endl;
    size--;
}

void printStack(st *s)
{
    cout<<"Stack : ";
    for(int i=0; i<size; i++){
        cout<<s->items[i]<<" ";
    }
    cout<<endl;

}


int main()
{
    int ch;
    st *s = (st *)malloc(sizeof(st));
    int arr[100];

    createEmptyStack(s);

    for(int i=0; i<size; i++){
        cin>>arr[i];
        push(s, arr[i]);
    }

    /*push(s, 1);
    push(s, 4);
    push(s, 3);
    push(s, 2);
    push(s, 8);*/

    printStack(s);

    pop(s);
    cout<<"Stack after popping out: ";
    printStack(s);

}
