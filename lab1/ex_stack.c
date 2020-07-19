#include <stdio.h> 
#include <stdlib.h>
/*int init(intlist *l, int len);
int add_to_end(intlist *l, int val);
int add_to_start(intlist *l, int val);
int insert_after(intlist *l, int insert_val, int val);
*/
struct intlist {
   int *x;
   int end;
   int len;
};
typedef struct intlist intlist;

int init(intlist *l, int len){
   if (l==NULL){ return -1;}
   (l->x) = (int *)malloc(len * sizeof(int));
   if ((l->x) == NULL) { return -1; }
   l->end = -1;
   l->len=len;
   return 0;
}

int  add_to_end(intlist *l, int val){
   if (l==NULL){return -1;}
   (l->x)[(l->end)+1] = val;
   l->end = 0;
   return 0;
}

int add_to_start (intlist *l, int val){
   int *copy = NULL;
   int i = 0;
   if (l==NULL){return -1;}
   copy = (int *) malloc(((l->end)+1)* sizeof(int));
   for (i = 0; i < (l->end)+1; i++){
      copy[i] = (l->x)[i];  
   }  
   (l->x)[0] = val;
   for (i=0; i< (l->end)+1; i++){
      if ( i+1 > (l->end)-1){ return -1;}
      (l->x)[i+1] = copy[i];
   }
   return 0;
}

int insert_after(intlist *l, int insert_val, int val){
   int i =0;
   int index = 1; 
   int *copy = NULL; 
   for (i=0; i<(l->end)+1; i++){
      index = index;
      if ((l->x)[i] == insert_val){ break; } 
      if (i == (l-> end) && (l->x)[i] != insert_val){return -1;} 
   }
   copy = (int *)malloc(((l->end)-index +1)*sizeof(int));
   for (i = index; i<(l->end)+1; i++){
      copy[i-index] = (l->x)[i];
   } 
   (l->x)[index] = val;
   for (i= index; i< (l->end)+1; i++){
      if (i+1 >(l->end)-1){ return -1;}
      (l->x)[i+1] = copy[i-index];
   }
   return 0;  
}

int push(intlist *l, int val){
   if (l==NULL){return -1;}
   if (l->end != (l->len) -1){
      (l->x)[(l->end)+1] = val;      
      l->end = (l->end)+1;
      l->len = (l->len) + 1;
      return 0;
   } else{
      return -1;}
}

int pop(intlist *l){
   if (l==NULL){return -1;}
   if (l->end!=-1){
      (l->end) = (l->end) -1;
      return (l->x)[(l->end)-1];
   } else{
      return -1;
   }
}

int main(void){
}
