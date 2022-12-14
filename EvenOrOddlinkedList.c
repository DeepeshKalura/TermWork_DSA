/*

    Write a C program to create two linked lists positive and negative from a Original linked list, 
    so that positive linked list contains all positive elements and negative linked list contains 
    negative elements. Positive and negative linked lists should use the node of existing original 
    linked list. 

    Made by Deepesh Kalura
*/

#include<stdio.h>
#include<stdlib.h>


struct Node{
    int data;
    struct Node *next;
};

void Create(struct Node *head, int data){
    struct Node *pntr, *maker;
    pntr = head;

    while(pntr -> next!=NULL){
        pntr = pntr -> next; 
    }
    maker = malloc(sizeof(struct Node));
    maker -> data= data;
    maker -> next = NULL;
    pntr -> next = maker;
}

void CreateEvenOdd(struct Node **even, struct Node **odd ,struct Node *head){

    struct Node *ptr = head, *temp, *ptr1 = (*odd), *ptr2 = (*even);
    

    while(ptr->next != NULL){
        if((ptr->next->data )%2 == 0){
            temp = (ptr -> next);
            ptr2->next = temp;
            // ptr1 -> next -> next = NULL;
            ptr2 = ptr2 -> next;
            
        }else{
            temp = (ptr -> next);
            ptr1 -> next = temp;
            // ptr1 -> next -> next = NULL;
            ptr1 = ptr1 -> next;

        }
        
        ptr = ptr -> next;
    }
    ptr1 -> next = NULL;
    ptr2 -> next = NULL;
}

void print(struct Node *head){

    struct Node *pntr = head->next;
    while(pntr != NULL){
        printf("%d -> ", pntr->data);
        pntr = pntr -> next;
    }
    printf("NULL\n");

    

}


int main(){
    struct Node *head = malloc(sizeof(struct Node));

    head -> data = -1;
    head -> next = NULL;

    int arr[6] = {1,2,3,4,5,6};

    for(int i = 0; i<6; i++){
        Create(head, arr[i]);
    }

    print(head);
    struct Node *evenLinkedList = malloc(sizeof(struct Node));
    struct Node *oddLinkedList = malloc(sizeof(struct Node));
    oddLinkedList -> data = -1;
    oddLinkedList -> next = NULL;

    evenLinkedList -> data = -1;
    evenLinkedList -> next = NULL;

    CreateEvenOdd(&evenLinkedList, &oddLinkedList, head);
    print(evenLinkedList);
    print(oddLinkedList);

    return 0;
}