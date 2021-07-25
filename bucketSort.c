#include<stdlib.h>
#include<stdio.h>

//bucket sort 
struct node{
    float key;
    struct node *next;
};
typedef struct node *Node;

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