#include<stdlib.h>
#include<stdio.h>
#include<stdbool.h>

void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

void print_array(int a[], int n, char *message){
    if(message!=NULL)
        printf(message);

    int i; 

    for(i = 0; i< n-1 ; ++i)
        printf("%d , ", a[i]);
    printf("%d\n", a[i]);
}

void read_array(int a[], int n, char *message){
    if(message!=NULL)
        printf(message);
    for(int i = 0; i<n ; ++i){
        scanf("%d", &a[i]);
        //printf("read %d, %d \n", a[i], i);
    }
}

void copy_array(int source[], int destination[], int n){
    int i;
    for(i = 0; i < n ; ++i)
        destination[i] = source[i];

    //printf("Array copy done. \n");
}

int calcNextGap(int gap){
    gap = (gap*10)/1.3;
    if(gap < 1) //values of gap <= 1 indicate that the pass must be terminated 
        return 1;
    
    return gap;
}

void combSort(int a[], int n){
    int gap = n;
    bool swapped = false; //this checks is a swap occured or not 

    while( gap > 1 || swapped){
        gap = calcNextGap(gap); //calculating new gap 
        swapped = false; //checks for every iteration, hence reinitalise to false every time

        for(int i = 0; i < n - gap; ++i){
            if(a[i] > a[i + gap]){
                swap(&a[i], &a[i + gap]);
                swapped = true;//indicating that swap occured
            }
        }
    }
}

int main(){
    int n;
    printf("\nEnter size of array : ");
    scanf("%d", &n);

    int *a = (int *)calloc(n, sizeof(int));
    read_array(a, n, "\n Enter Array : \n");

    print_array(a, n, "\nUnsorted Array : \n");

    combSort(a, n);

    print_array(a, n, "\nSorted Array (Comb Sort): \n");
}

