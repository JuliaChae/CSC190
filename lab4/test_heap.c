#include <stdio.h>
#include <stdlib.h>
#include "heap.c"

int main(void){
   int *iout=NULL;
   int *preout=NULL;
   int *postout = NULL; 
   int i,j;
   int r = 0;
   int size =0;
   int del = 0;
   HeapType heapTest;
   
   //Testing initialization 
   r = initHeap(&heapTest, 50);
   
   //Testing addition to heap 
   addHeap(&heapTest,20);
   addHeap(&heapTest,13);
   addHeap(&heapTest,10);
   addHeap(&heapTest, 12);
   addHeap(&heapTest, 8);

   printf("Printing inorder: \n");
   inorder(&heapTest, &iout, &size); 
   for (i=0; i<size; i++){
      printf("%d\n",iout[i]); }
  
   printf("\nPrinting preorder: \n");
   preorder(&heapTest, &preout, &size); 
   for (i=0; i<size; i++){
      printf("%d\n",preout[i]); }
 
   printf("\nPrinting postorder:\n");
   postorder(&heapTest, &postout, &size); 
   for (i=0; i<size; i++){
      printf("%d\n",postout[i]); }
 
   printf("\nLooking for 21. Found status: %d\n",findHeap(&heapTest, 21));
   printf("\nLooking for 13. Found status: %d\n",findHeap(&heapTest, 13));
   printf("\nLooking for 10. Found status: %d\n",findHeap(&heapTest, 10));

   //Testing deleting from heap 
   delHeap(&heapTest, &del);
   delHeap(&heapTest, &del);
   delHeap(&heapTest, &del);
   delHeap(&heapTest, &del);
   delHeap(&heapTest, &del);
   printf("\nLast value deleted was: %d\n", del);
   inorder(&heapTest, &iout, &size); 
   for (i=0; i<(heapTest.end+1); i++){
     printf("%d\n",iout[i]); }
}

