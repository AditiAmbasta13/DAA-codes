#include<stdio.h>
#include<conio.h>
#define MAX 100

int partition(int a[], int lb, int ub){
    int pivot, s, e, temp;
    pivot=a[lb];
    s=lb;
    e=ub;
    while(s<e){
        while(a[s]<=pivot)
            s++;
        while(a[e]>pivot)
            e--;
        if(s<e){
            //swap start and end elements
            temp = a[s];
            a[s] = a[e];
            a[e] = temp;
        }
    }
    //swap lb/pivot and a[e]
    temp = a[lb];
    a[lb] = a[e];
    a[e] = temp;
    return e;
}

void quickSort(int a[], int lb, int ub){
    int loc;
    if(lb<ub){
        loc = partition(a, lb, ub);
        quickSort(a, lb, loc-1);
        quickSort(a, loc+1, ub);
    }
}

void main(){
    int n,i,a[MAX],lb,ub;
    lb=0;
    printf("\nEnter mumber of elements in Array to Sort: ");
    scanf("%d",&n);
    ub=n-1;
    printf("\nEnter elements in Array to Sort-");
    for(i=0;i<n;i++){
        printf("\nEnter %d element: ",i+1);
        scanf("%d",&a[i]);
    }
    printf("\nOriginal Array: ");
    for(i=0;i<n;i++){
        printf("%d\t",a[i]);
    }
    quickSort(a,lb,ub);
    printf("\nSorted Array (using Quick Sort): ");
    for(i=0;i<n;i++){
        printf("%d\t",a[i]);
    }
}