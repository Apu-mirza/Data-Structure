#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int value) : data(value), next(nullptr) {}
};

class LinkedList {
public:
    Node* head;

    LinkedList() : head(nullptr) {}

    void insertAtBeginning(int value) {
        Node* newNode = new Node(value);
        newNode->next = head;
        head = newNode;
    }

    void display() {
        Node* current = head;
        while (current != nullptr) {
            cout << current->data << " -> ";
            current = current->next;
        }
        cout << "nullptr" << endl;
    }
};

int main() {
    LinkedList linkedList;

    while (true) {
        cout << "\nLinked List Operations:" << endl;
        cout << "1. Insert at the beginning" << endl;
        cout << "2. Display" << endl;
        cout << "3. Exit" << endl;

        int choice;
        cout << "Enter your choice (1/2/3): ";
        cin >> choice;

        if (choice == 1) {
            int data;
            cout << "Enter the element to insert at the beginning: ";
            cin >> data;
            linkedList.insertAtBeginning(data);
            cout << data << " inserted at the beginning." << endl;
        } else if (choice == 2) {
            cout << "Current Linked List:" << endl;
            linkedList.display();
        } else if (choice == 3) {
            cout << "Exiting..." << endl;
            break;
        } else {
            cout << "Invalid choice. Please enter a valid option." << endl;
        }
    }

    return 0;
}
