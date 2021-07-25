//randomized quick sort
//randomly generated pivot further improves time complexity
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void init_random(){
    srand(time(NULL)); //seeding random in system time
}

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

void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partitionLomuto(int a[], int low, int high){
    int pivot = a[high];
    int i, j;

    i = low; 

    for(j = low; j < high ; ++j){
        print_array(a, (high - low + 1), NULL );
        if(a[j] <= pivot){
            printf("%d %d \n", a[i], a[j]);
            swap(&a[i], &a[j]);
            ++i;
        }
    }

    swap(&a[i], &a[high]);

    return i;
}

int partitionHoares(int a[], int low, int high){
    int pivot = a[low];

    int i, j; 
    i = low - 1; 
    j = high + 1; 

    while(1){
        do{
            i++; 
        }while(a[i] < pivot); //finding uneven element at the left

        do{
            j--;
        }while(a[j] > pivot); //finding uneven element at the right

        //printf("\n %d %d \n", i, j);
        if(i >= j){
            //printf("returning \n");
            return j;
        }
        else
            swap(&a[i], &a[j]);
        
    }
    return -1; // error code 
}

int randomizingPartition(int a[], int low, int high, int type){
    //0 : Hoare's Partition, 1: Lomuto's Partition
    if(high == low)
        return high;

    int randomNo = rand()%(high - low) + low;
    swap(&a[randomNo], &a[high]);
    
    switch (type)
    {
        default:
            printf("\nEnter valid type. Setting default type as Hoares. \n");
        case 0:
            return partitionHoares(a, low, high);
        case 1:
            return partitionLomuto(a, low, high);
    }

}

void quickSort(int a[], int low, int high, int type){
    if (low < high){
        int pivot = randomizingPartition(a, low, high, type);

        quickSort(a, low, pivot, type);
        quickSort(a, pivot + 1, high, type);
    }
}

void read_array(int a[], int n, char *message){
    if(message!=NULL)
        printf(message);
    for(int i = 0; i<n ; ++i)
        scanf("%d", &a[i]);
}
int main(){

    int n;

    init_random();
    
    printf("Enter size of array : ");
    scanf("%d", &n);

    int *a_hoares = (int *)calloc(n , sizeof(int));
    int *a_lomutos = (int *)calloc(n , sizeof(int));
    read_array(a_hoares, n, "\nEnter array : \n");
    copy_array(a_hoares, a_lomutos, n);

    printf("\nHoare's Randomized Partiton : \n");
    quickSort(a_hoares, 0, n-1, 0); // randomized hoares partition 
    print_array(a_hoares, n, "\nArray after Randomized Quicksort & Hoare's Partition : \n");

    printf("\nLomuto's Randomized Partiton : \n");
    quickSort(a_lomutos, 0, n-1, 1); // randomized lomutos partition 
    print_array(a_lomutos, n, "\nArray after Lomuto's Quicksort & Hoare's Partition : \n");
}