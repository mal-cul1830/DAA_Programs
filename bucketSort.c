#include<stdlib.h>
#include<stdio.h>

//bucket sort 
struct node{
    float key;
    struct node *next;
};
typedef struct node *Node;

void print_array(int a[], int n, char *message){
    if(message!=NULL)
        printf(message);

    int i; 

    for(i = 0; i< n-1 ; ++i)
        printf("%d , ", a[i]);
    printf("%d\n", a[i]);
}

void copy_array(int source[], int destination[], int n){
    int i;
    for(i = 0; i < n ; ++i)
        destination[i] = source[i];

    printf("Array copy done. \n");
}

Node createNode(float val){
    Node newNode = (Node)malloc(sizeof(struct node));
    newNode->key = val;
    newNode->next = NULL;
    return newNode;
}

Node add(Node head, float val){
    Node newNode = createNode(val);
    Node temp = head;
    while(temp->next!=NULL)
        temp = temp->next;
    temp->next = newNode;

    return head;
}

void printList(Node head){
    Node temp = head;
    printf("\n Printing list : \n");
    while(temp!=NULL){
        printf("%d -> ");
    }
    printf("NULL \n");
}

void bucketSort(float a[], int n){
    Node buckets[n];
    int index; 
    for(int i = 0 ; i<n; ++i){
        index = a[i]*n;

        add(buckets[index%n], a[i]);
        printList(buckets[index%n]);
    }
}

int main(){
    
}