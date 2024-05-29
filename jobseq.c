#include<stdio.h>
#include<conio.h>

int job(int p[] , int d[] , int n);

void main(){
    int profit;
    int p[] = {15,25,50,10};
    int d[] = {0,0,1,1};
    int n = sizeof(p)/sizeof(p[0]);
    profit = job(p , d , n);
    printf("total profit: %d", profit);
}

int job(int p[] , int d[] , int n){
    int i,j,temp,temp2,maxdeadline;
    int slot[maxdeadline+1];
    int totalprofit=0;
    for(i=0;i<n;i++){
        for(j=0;j<n-i-1;j++){
            if(p[j]<p[j+1]){        //sort in descending order
                temp=p[j];
                p[j]=p[j+1];
                p[j+1]=temp;

                temp2=d[j];
                d[j]=d[j+1];
                d[j+1]=temp2;
            }
        }
    }

    maxdeadline=d[0];

    for(i=1;i<n;i++){
        if(d[i]>maxdeadline){
            maxdeadline=d[i];
        }
    }

    for(i=0;i<=maxdeadline;i++){
        slot[i]= 0 ;
    }

    for(i=0;i<n;i++){
        for(j=maxdeadline;j>=0;j--){
            if(d[slot[j]]==0){      
                slot[j]=1;          //assigns jobs to the last possible deadline
                totalprofit=totalprofit+p[i];
                break;
            }
            else{
                d[i]=d[i]-1;
            }
        }
    }
    return totalprofit;
}