#include <stdlib.h>
#include <iostream>
using namespace std;

// Create a node
struct Node {
  int data;
  struct Node* next;
};

void insertAtBeginning(struct Node** head_ref, int new_data) {
  // Allocate memory to a node
  struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));

  // insert the data
  new_node->data = new_data;
  new_node->next = (*head_ref);

  // Move head to new node
  (*head_ref) = new_node;
}

// Insert a node after a node
void insertAfter(struct Node* prev_node, int new_data) {
  if (prev_node == NULL) {
  cout << "the given previous node cannot be NULL";
  return;
  }

  struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
  new_node->data = new_data;
  new_node->next = prev_node->next;
  prev_node->next = new_node;
}

// Insert at the end
void insertAtEnd(struct Node** head_ref, int new_data) {
  struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
  struct Node* last = *head_ref; /* used in step 5*/

  new_node->data = new_data;
  new_node->next = NULL;

  if (*head_ref == NULL) {
  *head_ref = new_node;
  return;
  }

  while (last->next != NULL) last = last->next;

  last->next = new_node;
  return;
}

// Delete a node
void deleteNode(struct Node** head_ref, int key) {
  struct Node *temp = *head_ref, *prev;

  if (temp != NULL && temp->data == key) {
  *head_ref = temp->next;
  free(temp);
  return;
  }
  // Find the key to be deleted
  while (temp != NULL && temp->data != key) {
  prev = temp;
  temp = temp->next;
  }

  // If the key is not present
  if (temp == NULL) return;

  // Remove the node
  prev->next = temp->next;

  free(temp);
}

// Search a node
bool searchNode(struct Node** head_ref, int key) {
  struct Node* current = *head_ref;

  while (current != NULL) {
  if (current->data == key) return true;
  current = current->next;
  }
  return false;
}

// Sort the linked list
void sortLinkedList(struct Node** head_ref) {
  struct Node *current = *head_ref, *index = NULL;
  int temp;

  if (head_ref == NULL) {
  return;
  } else {
  while (current != NULL) {
    // index points to the node next to current
    index = current->next;

    while (index != NULL) {
    if (current->data > index->data) {
      temp = current->data;
      current->data = index->data;
      index->data = temp;
    }
    index = index->next;
    }
    current = current->next;
  }
  }
}
void traverse(struct Node* head) {
        Node* current = head;
        while (current) {
            cout << current->data << " ";
            current = current->next;
        }
        cout <<endl;
    }

// Print the linked list
void printList(struct Node* node) {
  while (node != NULL) {
  cout << node->data << " ";
  node = node->next;
  }
}

// Driver program
int main() {
  struct Node* head = NULL;

  while(true){
    int choose;
    cout<<"\nChoose Option\n1.Insert\n2.Delete\n3.Traverse\n4.Search\n5.Sort: "<<endl;
    cin>>choose;
    if(choose == 1){
        cout<<"1.Insert beginning\n2.Insert at middle\n3.Insert at end: "<<endl;
        int choose1;
        cin>>choose1;
        if(choose1 == 1){
            cout<<"Input value to insert at beginning: ";
            int value;
            cin>>value;
            insertAtBeginning(&head,value);
        }else if(choose1 == 2){
            cout<<"Input value to insert at middle: ";
            int value;
            cin>>value;
            insertAfter(head,value);
        }else if(choose1==3){
            cout<<"Input value to insert at end: ";
            int value;
            cin>>value;
            insertAtEnd(&head,value);
        }else{
            cout<<"Invalid input, please enter value from 1, 2 or 3 "<<endl;
        }
        cout<<"List after inserted an element: ";
        printList(head);
        cout<<endl;
    }else if(choose == 2){
        int key;
        cout<<"Input the delete key: ";
        cin>>key;
        deleteNode(&head, key);
            cout<<"List After delete a node: ";
            printList(head);
    }else if(choose == 3){
        traverse(head);
    }else if(choose == 4){
        cout<<"Enter search item: ";
        int searchItem;
        cin>>searchItem;
        if(searchNode(&head, searchItem)) cout<<searchItem<<" is found"<<endl;
        else cout<<searchItem<<" not found"<<endl;
    }else if(choose == 5){
        sortLinkedList(&head);
        cout<<"Sorted List: ";
        printList(head);
    }
  }
}
