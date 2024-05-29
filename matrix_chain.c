#include<stdio.h>

void main(){
    int n = 5;
    int p[5] = {5, 4, 6, 2, 7};
    int m[5][5] = {0};
    int s[5][5] = {0};
    int j, min, q;
    for(int d = 1; d < n-1; d++){
        for(int i = 1; i< n-d; i++){
            j = i+d;
            min = 999999;
            for(int k = i; k<= j-1; k++){
                q = m[i][k] + m[k+1][j] + p[i-1]*p[k]*p[j];
                if(q < min){
                    min = q;    
                    s[i][j] = k;
                }
            }
            m[i][j] = min;
        }
    }
    printf("Matrix chain multiplication= %d", m[1][n-1]);
}

// #include<stdio.h>
// #include<stdlib.h>

// int memo[10][10][2];

// int MatrixChainOrder(int p[], int i, int j)
// {
//     if (i == j)
//         return 0;
//     if(memo[i][j][0] != 0){
//         return memo[i][j][1];
//     }
//     int k;
//     int min = 9999;
//     int count;
//     int k1;
//     for (k = i; k < j; k++) 
//     {
//         count = MatrixChainOrder(p, i, k) + MatrixChainOrder(p, k + 1, j) + p[i - 1] * p[k] * p[j];

//         if (count < min){
//             min = count;
//             k1 = k;
//         }
//     }
//     memo[i][j][0] = k1;
//     memo[i][j][1] = min;
//     return min;
// }

// int main(){
//     int n = 4,k,i,j;
//     int cost[] = {5,4,6,2,7};
//     int M[4][4] = {0};
//     for(i=0;i<10;i++){
//         for(j=0;j<n;j++){
//             memo[i][j][0] = 0;
//             memo[i][j][1] = 0;
//         }
//     }
//     for(i=0;i<n;i++){
//         for(j=0;j<n;j++){
//             if(j>=i){
//                 printf("%d ", MatrixChainOrder(cost, i+1, j+1));
//             }else{
//                 printf("0 ");
//             }
//         }
//         printf("\n");
//     }
//     printf("\n");printf("\n");
//     for(i=0;i<n;i++){
//         for(j=0;j<n;j++){
//             if(j>=i){
//                 printf("%d ", memo[i+1][j+1][0]);
//             }else{
//                 printf("0 ");
//             }
//         }
//         printf("\n");
//     }
//         return 0;
// }