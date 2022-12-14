/*
#include<stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node{
    char processName;
    int timeComplete;
    int timeCounter;
    struct Node *next;
    struct Node *prev; 

};


void CreateProcess(struct Node *head, char processName){
    struct Node *pntr, *maker;
    pntr = head;

    while(pntr -> next!=NULL){
        pntr = pntr -> next; 
    }
    maker = malloc(sizeof(struct Node));

    
    maker -> processName = processName;
    maker -> timeCounter = 0;
    maker -> timeComplete = 10;
    maker -> next = NULL;
    pntr -> next = maker;
    maker -> prev = pntr;
}

void print(struct Node *head){

    struct Node *pntr = head->next;
    while(pntr != NULL){
        printf("%s, %d -> ", pntr->processName, pntr -> timeCounter);
        pntr = pntr -> next;
    }
    printf("NULL\n");
}


int main(){

    struct Node *head = malloc(sizeof(struct Node));
    head -> processName = '1';
    head -> timeComplete = 0;
    head ->  timeCounter = 0;
    head -> next = NULL;
    head -> prev = NULL;
    printf("Enter The process Name: ");
    for(int i = 0; i<5; i++){
        char c;
        scanf("%c", &c);
        CreateProcess(head, c);
    }
    print(head);

    return 0;
}
*/

#include <stdio.h>
#include <stdlib.h>

// Define a node in the circular linked list
struct Node {
    int data;
    struct Node *next;
};

// Function to insert a new node into the circular linked list
void insertNode(struct Node **head, int data) {
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = newNode;

    if (*head == NULL) {
        *head = newNode;
        return;
    }

    struct Node *temp = *head;
    while (temp->next != *head)
        temp = temp->next;

    temp->next = newNode;
    newNode->next = *head;
}

// Function to implement time sharing for N processes
void timeSharing(struct Node *head, int n) {
    struct Node *temp = head;
    int timeSlot = 10;

    while (n--) {
        printf("Process %d will be completed in %dns\n", temp->data, timeSlot);
        temp = temp->next;
    }
}

// Main function
int main() {
    // Create an empty circular linked list
    struct Node *head = NULL;

    // Number of processes
    int n = 4;

    // Insert nodes into the circular linked list
    for (int i = 1; i <= n; i++)
        insertNode(&head, i);

    // Implement time sharing for N processes
    timeSharing(head, n);

    return 0;
}
