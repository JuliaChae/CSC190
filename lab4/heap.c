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
   if (size<=0){ return -1;}
   pHeap->store = (int *)malloc(size*sizeof(int)); 
   pHeap->size = size; 
   pHeap->end = -1; 
}

int inorder(HeapType *pHeap, int **output, int *o_size){
   index = 0;
   if (pHeap == NULL){ return -1;}
   (*output) = (int*)malloc(((pHeap->end)+1)*sizeof(int));
   if (output == NULL){ return -1;}
   *o_size = (pHeap->end)+1;
   if (pHeap->end == -1) { return 0; }
   inorder_help (pHeap, *output, 0);
   return 0; 
}

int preorder (HeapType *pHeap, int **output, int *o_size){
   index =0;
   if (pHeap == NULL){ return -1;}
   (*output)= (int*)malloc(((pHeap->end)+1)*sizeof(int));
   if (output==NULL){return -1;}
   *o_size = (pHeap->end)+1;
   if (pHeap->end == -1) { return 0; }
   preorder_help(pHeap, *output, 0);
   return 0;
}

int postorder (HeapType *pHeap, int **output, int *o_size){
   index =0;
   if (pHeap == NULL){ return -1;}
   (*output)= (int*)malloc(((pHeap->end)+1)*sizeof(int));
   if (output==NULL){return -1;}
   *o_size = (pHeap->end)+1;
   if (pHeap->end == -1) { return 0; }
   postorder_help(pHeap, *output, 0);
   return 0;

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

int addHeap(HeapType *pHeap, int key){
   int parent=0;
   int temp = 0;
   int index = 0;
   if (pHeap==NULL){return -1;}
   (pHeap->end) = (pHeap->end) + 1; 
   if (((pHeap->end)+1)>(pHeap->size)) {return -1;}
   index = (pHeap->end); 
   (pHeap->store)[pHeap->end] = key;
   while(parent != 0){
      if (index%2==1){
         parent = (index -1)/2;
      } else{
         parent = (index -2)/2; 
      }         
      if ((pHeap->store)[index]>(pHeap->store)[parent]){
         temp = (pHeap->store)[parent];
         (pHeap->store)[parent]=(pHeap->store)[index];
         (pHeap->store)[index]=temp; 
         index = parent; 
      }
   }
   return 0; 
}

int findHeap(HeapType *pHeap, int key){
   int i=0;
   int found = -1; 
   if (pHeap == NULL) { return -1;}
   for (i=0; i<(pHeap->end)+1;i++){
      if (key==(pHeap->store)[i]){ 
         found =0;
         break; }
   }
   if (found !=0){ return 0; }
   else { return 1;}
}

int delHeap(HeapType *pHeap, int *key){
   int leftC = 0;
   int rightC =0;
   int index = 0;
   int swapindex = 0;
   int temp= 0;
   *key = (pHeap->store)[0];
   //if (pHeap->end == 0){ (pHeap->end) = (pHeap->end)-1; return 0; }
   (pHeap->store)[0] = (pHeap->store)[pHeap->end];     
   (pHeap->end)=(pHeap->end)-1;
   while (1){
      if (index*2+1> (pHeap->end)) { break;}
      if (index*2+1 <=(pHeap->end)){ leftC = index*2 +1;} 
      if (index*2+2 < (pHeap->end)) { rightC = index*2 +2;} else {rightC = -1;}
      if (rightC == -1){
         swapindex = leftC;}
      else if ((pHeap->store)[leftC]>(pHeap->store)[rightC]){
         swapindex = leftC;}
      else { 
         swapindex = rightC;}
      if ((pHeap->store)[index]<(pHeap->store)[swapindex]){
         temp = (pHeap->store)[swapindex];
         (pHeap->store)[swapindex] = (pHeap->store)[index];
         (pHeap->store)[index] = temp;
         index = swapindex;
      }else {
         break; }
   }
   return 0;
}
