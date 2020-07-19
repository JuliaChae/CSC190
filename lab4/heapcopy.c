#include<stdio.h>
#include<stdlib.h>

int index = 0;

typedef struct{
   int *store;
   unsigned int size;
   unsigned int end;
} HeapType; 

int initHeap(HeapType *pHeap, int size){
   if (pHeap == NULL){return -1;}
   pHeap->store = (int *)malloc(size*sizeof(int)); 
   pHeap->size = 0; 
   pHeap->end = 0; 
}

int inorder(HeapType *pHeap, int **output, int *o_size){
   if (pHeap == NULL){ return -1;}
   (*output) = (int*)malloc(((pHeap->end)+1)*sizeof(int));
   if (output == NULL){ return -1;}
   *o_size = (pHeap->end)+1;
   inorder_help (pHeap, *output, 0);
   return 0; 
}

int preorder (HeapType *pHeap, int **output, int *o_size){
   if (pHeap == NULL){ return -1;}
   (*output)= (int*)malloc(((pHeap->end)+1)*sizeof(int));
   if (output==NULL){return -1;}
   *o_size = (pHeap->end)+1;
   preorder_help(pHeap, *output, 0);
   return 0;
}

int postorder (HeapType *pHeap, int **output, int *o_size){
   if (pHeap == NULL){ return -1;}
   (*output)= (int*)malloc(((pHeap->end)+1)*sizeof(int));
   if (output==NULL){return -1;}
   *o_size = (pHeap->end)+1;
   postorder_help(pHeap, *output, 0);

}

int inorder_help(HeapType *pHeap, int *output, int current){
   if (current > (pHeap ->end)){return 0;}
   else {
      inorder_help(pHeap, output, 2*current+1);
      output[index] = (pHeap->store)[current]; 
      index = index + 1;
      inorder_help(pHeap,output,2*current+2);
   }
}

int preorder_help(HeapType *pHeap, int *output, int current){
   if (current > (pHeap -> end)){ return 0;}
   else{
      output[index]=(pHeap->store)[current];
      index = index + 1;
      preorder_help(pHeap, output,2*current+1);
      preorder_help(pHeap, output, 2*current+2);  
   }
}

int postorder_help(HeapType *pHeap, int *output, int current){
   if (current > (pHeap -> end)){ return 0;}
   else{
      postorder_help(pHeap, output,2*current+1);
      postorder_help(pHeap, output, 2*current+2);  
      output[index]=(pHeap->store)[current];
      index = index + 1;
   }
}
int main(void){
   int heap[13] = {1,2,3,4,5,6,7,8,9,10,11,12,13};
   int *out = NULL; 
   int i=0;
   int size = 0;
   HeapType heapTest;
   heapTest.store = heap;
   heapTest.size = 13; 
   heapTest.end = 12; 
   postorder(&heapTest, &out, &size); 
   for (i=0; i<13; i++){
      printf("%d\n",out[i]); }
}
