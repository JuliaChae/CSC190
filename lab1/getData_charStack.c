#include <stdio.h>
#include <stdlib.h>

struct llnode {
   char value;
   struct llnode *next;
};
typedef struct llnode llnode;

int llnode_add_to_tail(llnode **x,char value) {
   if (x==NULL) { return -1; }
   if (*x==NULL) {
      *x = (llnode *) malloc(sizeof(llnode));
      (*x)->value = value;
      (*x)->next = NULL;
      return 0;
   } else {
      return llnode_add_to_tail(&((*x)->next),value);
   }
}

int llnode_add_to_head(llnode **x, char value){
   llnode *old_head;
   if (x==NULL) { return -1; }
   old_head = *x; 
   *x = (llnode *) malloc(sizeof(llnode));
   (*x)->value = value;
   (*x)->next = old_head;
   return 0;
}     

int push(llnode **x, char value){
   int r = 0;
   if (x == NULL){return -1;}
   r = llnode_add_to_head(x, value);
   if (r == -1){ return -1; } 
   return 0;
}

int pop(llnode **x, char *return_value){
   llnode *old_head = *x; 
   if (x==NULL|| return_value == NULL){return -1;};
   *return_value = (*x)->value;
   (*x) = (*x)->next;
   free(old_head);
   return 0;
}

int llnode_print_from_head(llnode *x) {
   if (x==NULL) { return 0; }
   else {
      printf("%c\n",x->value);
      return llnode_print_from_head(x->next);
   }
}

int llnode_print_from_tail(llnode *x) {
   if (x==NULL) { return 0; }
   else {
      if (x->next == NULL) {
         printf("%c\n",x->value);
	 return 0;
      } else {
         llnode_print_from_tail(x->next);
         printf("%c\n",x->value);
	 return 0;
      }
   }
}

int llnode_del_from_tail (llnode **x){
   if (x==NULL){ return -1; }
   if (((*x)->next)->next == NULL){
      free ((*x)->next);
      (*x)->next = NULL;
      return 0;
   }
   else {
      return llnode_del_from_tail (&((*x)->next));
   }
}

int llnode_del_from_head (llnode **x){
   if (x == NULL) { return -1;}
   else {
      llnode *temp = *x;
      *x = (*x)->next;
      free(temp);
      return 0;
   }
}

int main(void) {
   int n=0;
   char value=' ';
   char rpop = ' ';
   int rvalue=0;
   llnode *input_list=NULL;

   while (scanf("%c",&value) != EOF) {
      n=n+1;
      push(&input_list,value);
   }
   llnode_del_from_head(&input_list);
   pop(&input_list,&rpop);
   printf("popped is %c\n", rpop); 
   printf("INFO: you entered %d items\n",n-1);
   rvalue=llnode_print_from_head(input_list);
   if ( !(rvalue==0) ) { printf("ERR: llnode_print returned an error\n"); }
   return 0;
}
