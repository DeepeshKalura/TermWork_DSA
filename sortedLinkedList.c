#include <stdio.h>
#include <stdlib.h>

// Define a node in the linked list
struct Node {
  struct Node* prev;
  int data;
  struct Node* next;
};

// Function to create a new node
struct Node* createNode(int data) {
  struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
  newNode->data = data;
  newNode->next = NULL;
  newNode->prev = NULL;
  return newNode;
}

// Function to insert a new node in the linked list
void insertNode(struct Node** head, int data) 
{
  struct Node* current = *head;
  struct Node* newNode = createNode(data);

  // If the linked list is empty, set the new node as the head
  if (*head == NULL) {
    *head = newNode;
     return;
  }

  // If the new node is smaller than the head, set it as the new head
  if (current->data > data) {
    newNode->next = current;
    current->prev = newNode;
    *head = newNode;
    return;
  }

  // Find the correct position to insert the new node
  while (current->next != NULL && current->next->data < data) 
  {
    current = current->next;
  }

  // Insert the new node
  newNode->next = current->next;
  if (current->next != NULL) {
    current->next->prev = newNode;
  }
  current->next = newNode;
  newNode->prev = current;
}

// Function to print the linked list
void printList(struct Node* head) {
  struct Node *ptr = head;
  while (ptr != NULL) {
    printf("%d -> ", ptr->data);
    ptr = ptr -> next;
  }
  printf("NULL\n");
}

int main(){

    struct Node *head;

    int arr[6] ={10,3,7,8,9,2};

    for(int i = 0; i<6; i++){
        insertNode(&head, arr[i]);
    }
    printList(head);
    return 0;
}