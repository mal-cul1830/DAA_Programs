#include<stdlib.h>
#include<stdio.h>

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

