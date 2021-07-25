#include<stdlib.h>
#include<stdio.h>

//bucket sort 
struct node{
    float key;
    struct node *next;
};
typedef struct node *Node;

void print_array(float a[], int n, char *message){
    if(message!=NULL)
        printf(message);

    int i; 

    for(i = 0; i< n-1 ; ++i)
        printf("%f , ", a[i]);
    printf("%f\n", a[i]);
}

void read_array(float a[], int n, char *message){
    if(message!=NULL)
        printf(message);
    for(int i = 0; i<n ; ++i){
        scanf("%f", &a[i]);
        //printf("read %f, %d \n", a[i], i);
    }
}

void copy_array(float source[], float destination[], int n){
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

void printList(Node head){
    if(head == NULL)
        return;
    Node temp = head;
    //printf("\n Printing list : \n");
    while(temp!=NULL){
        printf("%f -> ", temp->key);
        temp = temp->next;
    }
    printf("NULL \n");
}

Node add(Node head, float val){
    Node newNode = createNode(val);
    if(head == NULL){
        head = newNode;
        return head;
    }
    Node temp = head;
    while(temp->next!=NULL)
        temp = temp->next;
    temp->next = newNode;

    return head;
}

Node InsertionSort(Node head){
    Node temp, cur, t1, nodeList; 
    if(head == NULL || head->next == NULL)
        return head;
    
    nodeList = head;
    nodeList->next = NULL;
    cur = head->next;

    while(cur!=NULL){
        if(nodeList->key > cur->key){
            temp = cur;
            cur = cur->next;

            temp->next = nodeList;
            nodeList = temp;
            continue;
        }

        for(temp = nodeList ; temp->next != NULL ; temp = temp->next){
            if(temp->next->key > cur->key)
                break;
        }

        if(temp->next != NULL){
            t1 = cur;
            cur = cur->next;
            t1->next = temp->next;
            temp->next = t1;
            continue;
        }else{
            temp->next = cur;
            cur = cur->next;

            temp->next->next = NULL;
        }
        
    }
    printf("\nSorted : \n");
    printList(nodeList);
    return nodeList;
}

float *concatLists(Node a[], int n){
    int index = 0;
    float *final = (float *)malloc(n*sizeof(float));
    Node temp;
    for(int i = 0 ; i < n ; ++i ){
        temp = a[i];
        while(temp!=NULL){
            final[index++] = temp->key;
            temp = temp->next;
        }
        print_array(final, index + 1, "\n");
    }

    return final;
}



void bucketSort(float a[], int n){
    Node buckets[n];
    for(int i = 0; i<n; ++i)
        buckets[i] = NULL;
    int index; 
    for(int i = 0 ; i<n; ++i){
        index = a[i]*n;

        buckets[index%n] = add(buckets[index%n], a[i]);

        //printf("Printing list!  %d ", index%n);
        //printList(buckets[index%n]);  
    }

    for(int i = 0; i<n ; ++i){
        buckets[i] = InsertionSort(buckets[i]);
        printList(buckets[i]);
    }

    print_array(concatLists(buckets, n), n, "\nSorted Array : \n");
}

void test(){
    float arr[] = { (float)0.897, (float)0.565,
                        (float)0.656, (float)0.1234,
                        (float)0.665 };
                        
    int n = sizeof(arr)/sizeof(float);
    print_array(arr, n, "\nUnsorted Array : \n");
    bucketSort(arr, n);

}
int main(){
    int n; 
    test();
    /*printf("\nEnter size of array : ");
    scanf("%d", &n);

    float *a = (float *)calloc(n, sizeof(float));
    read_array(a, n, "\n Enter Array : \n");
    bucketSort(a, n);*/
}