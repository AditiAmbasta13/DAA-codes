#include<stdio.h>
int main(){
   int start[] = {1 , 5 , 12};
   int finish[] = {10, 13, 23};
   int activities = sizeof(start)/sizeof(start[0]);
   int i, j;
   printf ("Following activities are selected \t");
   i = 0;
   printf("%d\t", i);
   for (j = 1; j < activities; j++){
      if (start[j] >= finish[i]){
         printf ("%d ", j);
         i = j;
      }
   }
   return 0;
}