//randomized quick sort
//randomly generated pivot further improves time complexity
#include<stdio.h>
#include<stdlib.h>

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

void quickSort(int a[], int low, int high, ){
    if (low < high){
        int pivot = partitionLomuto(arr, low, high);

        quickSort(a, low, pivot);
        quickSort(a, pivot + 1, high);
    }
}
int main(){
    
}