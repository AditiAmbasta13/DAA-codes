#include<stdio.h>
#include<conio.h>
#define MAX 100

void mergelist(int a[], int lb, int mid, int ub){
    
    int i=lb, j=mid+1, k=lb, b[MAX];
    while(i<=mid && j<=ub){
        if(a[i]<=a[j]){
            b[k]=a[i];
            i++;
        }
        else{
            b[k]=a[j];
            j++;
        }
        k++;
    }
    if(i>mid){
        while(j<=ub){
            b[k]=a[j];
            j++;
            k++;
        }
    }
    else{
        while(i<=mid){
            b[k]=a[i];
            i++;
            k++;
        }
    }
    for(i=lb;i<=ub;i++){
        a[i]=b[i];
    }
}

void mergeSort(int a[], int lb, int ub){

    int mid;
    if(lb<ub){
        mid = (lb+ub)/2;
        mergeSort(a,lb,mid);
        mergeSort(a,mid+1,ub);
        mergelist(a,lb,mid,ub);
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
    mergeSort(a,lb,ub);
    printf("\nSorted Array: ");
    for(i=0;i<n;i++){
        printf("%d\t",a[i]);
    }
}