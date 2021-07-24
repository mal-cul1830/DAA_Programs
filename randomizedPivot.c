//randomized quick sort
//randomly generated pivot further improves time complexity
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void init_random(){
    srand(time(NULL)); //seeding random in system time
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
        if(a[j] <= pivot){
            swap(a[i], a[j]);
            ++i;
        }
    }

    swap(a[i], a[high]);

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
            j--
        }while(a[j] > pivot); //finding uneven element at the right

        if(i >= j)
            return j;
        else
            swap(a[i], a[j]);
        
    }
    return -1; // error code 
}

int randomizingPartition(int a[], int low, int high, int type = 0){
    //0 : Hoare's Partition, 1: Lomuto's Partition
    if(high == low)
        return high;

    int randomNo = rand()%(high - low) + low;
    swap(a[randomNo], a[high]);
    
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

void quickSort(int a[], int low, int high, ){
    if (low < high){
        int pivot = randomizingPartition(arr, low, high);

        quickSort(a, low, pivot);
        quickSort(a, pivot + 1, high);
    }
}
int main(){
    init_random();
    
}