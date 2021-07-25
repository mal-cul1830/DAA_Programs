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
                swap(a[i], a[i + gap])
                swapped = true;
            }
        }
    }
}