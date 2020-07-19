#include <stdio.h>
#include <stdlib.h>

typedef struct {
   int *store;
   unsigned int size;
   unsigned int end;
   int (*compare)(int x, int y);
} intHeap_T;

int store(intHeap_T* heap, int value){
   int temp = 0;
   int index = 0;
   int parent=0;
   int i;
   int swapped =0;
   if (heap==NULL){return -1;}
   (heap->store)[heap->end]=value;
   if (((heap->end)+1)>(heap->size)) {return -1;}
   if (heap->end >=2) {
      while(1){
         swapped =0;
         for (i=heap->end;i>0;i--){
            index = i;
            parent = (i+1)/2-1;
            if ((heap->compare)((heap->store)[index],(heap->store)[parent])==0){
               temp = (heap->store)[parent];
               (heap->store)[parent]=(heap->store)[index];
               (heap->store)[index]=temp; 
               swapped = 1;
            }
         }
         if (swapped ==0){break;} 
      }
   }
   (heap->end) = (heap->end) + 1; 
}

int retrieve(intHeap_T* heap, int *rvalue){
   int index = 0;
   int parent =0;
   int temp= 0;
   int i=0;
   int swapped =0;
   *rvalue = (heap->store)[0];
   (heap->store)[0] = (heap->store)[heap->end];    
   for (i=0;i<=heap->end;i++){
      heap->store[i]=heap->store[i+1];
   } 
   (heap->end)=(heap->end)-1;
   if (heap->end >=2) {
      while(1){
         swapped =0;
         for (i=heap->end-1;i>0;i--){
            index = i;
            parent = (i+1)/2-1;
            if ((heap->compare)((heap->store)[index],(heap->store)[parent])==0){
               temp = (heap->store)[parent];
               (heap->store)[parent]=(heap->store)[index];
               (heap->store)[index]=temp; 
               swapped = 1;
            }
         }
         if (swapped ==0){break;} 
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

int main(void){
   intHeap_T heap;
   int r=0;
   int T[5] = {10,30,45,2,1};
   int rval;
   int i;
   heap.store=(int*)malloc(1000*sizeof(int));
   heap.size=1000;
   heap.end=0;
   heap.compare = lt;
   for (i=0;i<5;i++){
      store(&heap,T[i]);
      printf("%d",heap.store[i]);
   }
   printf("%d",heap.store[0]);
}
