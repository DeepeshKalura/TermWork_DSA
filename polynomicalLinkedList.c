#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    int degree;
    struct Node *next;
};

void Create(struct Node *head, int data, int degree){
    struct Node *pntr, *maker;
    pntr = head;

    while(pntr -> next!=NULL){
        pntr = pntr -> next; 
    }
    maker = malloc(sizeof(struct Node));
    maker -> data= data;
    maker -> degree = degree;
    maker -> next = NULL;
    pntr -> next = maker;
}

void print(struct Node *head){

    struct Node *pntr = head->next;
    while(pntr != NULL){
        printf("%dx(deg(%d)) + ", pntr->data, pntr -> degree);
        pntr = pntr -> next;
    }
    printf("0 = 0\n");

}

struct Node *SumTwoPoly(struct Node *head1, struct Node *head2){

    struct Node *temp = malloc(sizeof(struct Node)), *ptr1 = head1->next, *ptr2 = head2->next;
    struct Node * head, *ptr;
    head -> data = -1;
    head -> next = NULL;
    ptr = head;
    while(ptr1!=NULL){
        while(ptr2!=NULL){
            if(ptr1->degree == ptr2->degree){
                Create(head, ptr1->data+ptr2->data, ptr1->degree);
            }
            ptr2 = ptr2 -> next;
        }
        ptr2 = head2 -> next;
        ptr1 = ptr1 -> next;
    }
        return head;

}

int main(){

    struct Node *head1 = malloc(sizeof(struct Node));

    head1 -> data = -1;
    head1 -> next = NULL;

    struct Node *head2 = malloc(sizeof(struct Node));

    head2 -> data = -1;
    head2 -> next = NULL;

    int fdata[6] = {1,2,3,4,5,6};
    int fdegree[6] = {6,5,4,3,2,1}; 
    for(int i = 0; i<6; i++){
        Create(head1, fdata[i],fdegree[i]);
    }

    print(head1);

    int sdata[6] ={2,4,6,8,10,12};
    int sdegree[6] = {6,5,4,3,2,1};

    for(int i = 0; i<6; i++){
        Create(head2, sdata[i], sdegree[i]);
    }
    print(head2);

    printf("Sum of These Two Polynomial are:    \n");

    struct Node *sum = malloc(sizeof(struct Node));

    sum -> data = -1;
    sum -> next = NULL;
    
    sum = SumTwoPoly(head1, head2);

    print(sum);
    return 0;
}