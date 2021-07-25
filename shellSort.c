#include<stdlib.h>
#include<stdio.h>
#include<math.h>

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

    printf("Array copy done. \n");
}

int gapCalc(int n, int d){
    int gap = floor(n/pow(2, d));
    return gap;
}


void shellSort(int a[], int n){
    int gap, i, j, temp, d = 1;

    while(gap = gapCalc(n, d)){
        for(i = gap; i < n; ++i){
            temp = a[i];
            
            for(j = i; j >= gap && a[j - gap] > temp ; j -= gap)
                a[j] = a[j-gap];
            
            a[j] = temp;
        }
        ++d;
    }

    print_array(a, n, "\nFinal, Sorted Array (Shell Sort) : \n");
}