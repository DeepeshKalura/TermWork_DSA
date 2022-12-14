#include <stdio.h>
#include <stdlib.h>

// Define a structure for the nodes in the linked list
struct node {
  int data;  // The data stored in the node
  struct node* prev;  // Pointer to the previous node in the list
  struct node* next;  // Pointer to the next node in the list
};

// Function to create a new node
struct node* create_node(int data) {
  // Allocate memory for the new node
  struct node* new_node = malloc(sizeof(struct node));

  // Set the data and pointers in the new node
  new_node->data = data;
  new_node->prev = NULL;
  new_node->next = NULL;

  // Return the new node
  return new_node;
}

// Function to insert a new node into the linked list in ascending order
void insert_node(struct node** head, int data) {
  // Create a new node with the given data
  struct node* new_node = create_node(data);

  // If the linked list is empty, set the new node as the head of the list
  if (*head == NULL) {
    *head = new_node;
    return;
  }

  // If the new node's data is less than or equal to the head of the list,
  // set the new node as the new

}

int main(){

    return 0;
}
