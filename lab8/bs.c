#include <stdio.h>
#include <stdlib.h>

int bs(int *x, int size, int (*compare)(int x, int y)){
   int i = 0;
   int j = 0;
   int temp = 0; 
   int swapped =0; 
   for (i=0; i<size; i++){
      swapped = 0; 
      for (j=0;j<size-1;j++){
         if (compare(x[j],x[j+1])==1){
            temp = x[j];
            x[j]= x[j+1];
            x[j+1] = temp; 
            swapped = 1; 
         }
      }
      if (swapped == 0){
         break;
      }
   }
   return 0;
}

int lt(int x, int y){
   if (x<y){ return 1; }
   else { return 0; }
}

int gt(int x, int y){
   if (x>y){ return 1;}
   else {return 0;} 
}
 
