#include<stdio.h>
#include<stdlib.h>
#include"lab3_A.c"

int main(void) {
   int value=0;
   bstNode *root = NULL;
   while (scanf("%d",&value) != EOF) {
      add_bst(&root,value);
   }
   printTreeInOrder(root);
   return 0;
}



