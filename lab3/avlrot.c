#include <stdio.h>
#include <stdlib.h>
/*#include "lab3_A.c"*/

struct avlNode{
   int balance;
   int val;
   struct avlNode *l;
   struct avlNode *r;
};
typedef struct avlNode avlNode; 

int add_avl(avlNode **root,int val) {
   if (root == NULL) { return -1; }
   if (*root == NULL) {
      (*root) = (avlNode*)malloc(sizeof(avlNode));
      (*root) ->l=NULL;
      (*root)->r = NULL;
      (*root)->val=val;
   } else {
      if (val > ((*root)->val)){
         add_avl(&((*root)->r), val);
      }
      else if (val < ((*root)->val)){
         add_avl(&((*root)->l), val);
      }
   }
   return 0;
}


int isAVL(avlNode **root){
   int ldepth, rdepth=0; 
   if (root == NULL){
      return -1;
   }
   if (*root == NULL){
      return 0;
   }
   ldepth = findDepth((*root)->l);
   rdepth = findDepth((*root)->r);
   if (ldepth-rdepth != 0 && ldepth - rdepth != 1 && ldepth - rdepth != -1){
      return -1;
   }
   return 0;
}

int findDepth(avlNode *root){
   if (root == NULL){
      return 0;
   }
   if (findDepth(root->l)>findDepth(root->r)){
      return 1 + findDepth(root->l);
   }
   else{
      return 1+ findDepth(root->r); 
   }
}

int rotate(avlNode **root, unsigned int Left0_Right1){
   avlNode *newRoot=NULL; 
   avlNode *oldSucc = NULL; 
   if (root == NULL){return -1;}
   if (Left0_Right1 == 1){
      newRoot = (*root)->l;
      oldSucc = newRoot ->r;
      newRoot -> r = (*root); 
      (*root)->l = oldSucc; 
      (*root) = newRoot; 
   }
   if (Left0_Right1 == 0){
      newRoot = (*root)->r;
      oldSucc = newRoot ->l; 
      newRoot -> l = (*root); 
      (*root)->r = oldSucc; 
      (*root) = newRoot; 
   }
   return 0; 
} 

int dblrotate(avlNode **root, unsigned int MajLMinR0_MajRMinL1){
   if (root == NULL){ return -1; }
   if (MajLMinR0_MajRMinL1==1){
      rotate(&((*root)->l),0);
      rotate(root,1);
   }
   if (MajLMinR0_MajRMinL1 ==0){
      printLevelOrder((*root)->r);
      printf("%d\n");
      rotate(&((*root)->r),1);
      printLevelOrder((*root)->r);
      printf("%d\n");
      rotate(root,0);
   }
   return 0;
}

int printTreeInOrder(avlNode *root){
   if (root == NULL){
      return -1;
   }
   if ((root)->l!=NULL){
      printTreeInOrder(root->l);
   }
   printf("%d\n",root->val);
   if ((root)->r!=NULL){
      printTreeInOrder(root->r);
   }  
}

int printLevelOrder(avlNode *root){
   if (root ==NULL){
      return -1;
   }else{
      printf("%d ",root->val);
      printLevelOrder_2(root);
   }
}

int printLevelOrder_2(avlNode *root){
   if (root == NULL){
      return -1;
   }
   if ((root)->l!=NULL){
      printf("%d ",(((root)->l)->val));
   }
   if ((root)->r != NULL){
      printf("%d ",(((root)->r)->val));
   }
   if ((root)->l!=NULL){
      printLevelOrder_2(root->l);
   }
   if ((root)->r!=NULL){
      printLevelOrder_2(root->r);
   }  
}
