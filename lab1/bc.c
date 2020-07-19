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
   if (x==NULL|| return_value == NULL||*x==NULL){return -1;};
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
   int errpos = 0; 
   int openb=0;
   int closedb=0;
   llnode *input_list=NULL;

    while((scanf("%c",&value))!=EOF){
      errpos = errpos + 1;
      if (value=='(' || value=='{'|| value=='['){
         push(&input_list,value);
         openb= openb+1;
      } else if (value==')' || value=='}'|| value==']'){
         closedb = closedb + 1;
         if (pop(&input_list,&rpop) == -1){
            break;
         }
         if ((value == ')' && rpop != '(')|| (value == '}' && rpop != '{')|| (value == ']' && rpop != '[')) {
            closedb = closedb - 1;
            break;
         }
      }
   }
   if (input_list == NULL&& openb== closedb){
      printf("PASS");
   } else {
      if (input_list != NULL){ errpos = errpos -1;}
      printf("FAIL, %d",errpos);
   } 
   if ( !(rvalue==0) ) { printf("ERR: llnode_print returned an error\n"); }
   return 0;
}
