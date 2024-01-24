#include <iostream>
using namespace std;

int size = 0; // Declare max as a variable

struct stack
{
    int *items;
    int top;
};

typedef struct stack st;

void createEmptyStack(st *s, int maxSize)
{
    s->top = -1;
    s->items = new int[maxSize]; // Allocate memory for the stack
}

bool isEmpty(st *s)
{
    if (s->top == -1)
    {
        cout << "The stack is empty" << endl;
        return true;
    }
    else
        return false;
}

bool isFull(st *s, int maxSize)
{
    if (s->top == maxSize - 1)
    {
        cout << "The stack is full" << endl;
        return true;
    }
    else
        return false;
}

void push(st *s, int newItem, int maxSize)
{
    if (isFull(s, maxSize))
    {
        cout << "Cannot push, the stack is full" << endl;
    }
    else
    {
        s->top++;
        s->items[s->top] = newItem;
        size++;
    }
}

void pop(st *s)
{
    if (isEmpty(s))
    {
        cout << "Cannot pop, the stack is empty" << endl;
    }
    else
    {
        cout << "Item popped= " << s->items[s->top];
        s->top--;
        size--;
    }
    cout << endl;
}

int peek(st *s)
{
    if (isEmpty(s))
    {
        cout << "Cannot peek, the stack is empty" << endl;
        return -1; // Return a sentinel value to indicate an error
    }
    else
    {
        return s->items[s->top];
    }
}

void printStack(st *s)
{
    cout << "Stack: ";
    for (int i = 0; i < size; i++)
    {
        cout << s->items[i] << " ";
    }
    cout << endl;
}

int main()
{
    int ch;
    int max;
    st *s;

    cout << "Enter the desired size of the stack: ";
    cin >> max;

    s = new st; // Allocate memory for the stack using new
    createEmptyStack(s, max);

    while (true)
    {
        cout << "Choose an operation (1: Push, 2: Pop, 3: Peek, 0: Exit): ";
        cin >> ch;

        if (ch == 0)
        {
            break;
        }
        else if (ch == 1)
        {
            int newItem;
            cout << "Enter the element to push: ";
            cin >> newItem;
            push(s, newItem, max);
        }
        else if (ch == 2)
        {
            pop(s);
        }
        else if (ch == 3)
        {
            int topElement = peek(s);
            if (topElement != -1)
            {
                cout << "Top element: " << topElement << endl;
            }
        }
        else
        {
            cout << "Invalid choice. Please enter 1, 2, 3, or 0." << endl;
        }

        printStack(s);
    }

    // Free allocated memory
    delete[] s->items;
    delete s;

    return 0;
}

