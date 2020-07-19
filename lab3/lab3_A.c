#include <stdio.h>
#include <stdlib.h>

/*structure used to model binary search tree*/
struct bstNode{
   int val;
   struct bstNode *l;
   struct bstNode *r;
};
typedef struct bstNode bstNode;

/*structure used to model avl tree*/
struct avlNode{
   int balance; /* -1 Left, 0 balanced, +1 Right */
   int val;
   struct avlNode *l;
   struct avlNode *r;
};
typedef struct avlNode avlNode; 

struct qNode {
   avlNode *pval;
   struct qNode *nxt;
};
typedef struct qNode qNode;

int add_bst(bstNode **root,int val) {
   if (root == NULL) { return -1; }
   if (*root == NULL) {
      (*root) = (bstNode*)malloc(sizeof(bstNode));
      (*root) ->l=NULL;
      (*root)->r = NULL;
      (*root)->val=val;
   } else {
      if (val > ((*root)->val)){
         add_bst(&((*root)->r), val);
      }
      else if (val < ((*root)->val)){
         add_bst(&((*root)->l), val);
      }
   }
   return 0;
}

int printTreeInOrder(bstNode *root){
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

int printLevelOrder(bstNode *root){
   if (root ==NULL){
      return -1;
   }else{
      printf("%d ",root->val);
      printLevelOrder_2(root);
   }
}

int printLevelOrder_2(bstNode *root){
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
/*
int main(void) {
   bstNode *root=NULL;
   add_bst(&root,5);
   add_bst(&root,3);
   add_bst(&root,1);
   add_bst(&root,4);
   add_bst(&root,7);
   add_bst(&root,6);
   add_bst(&root,8);
   printTreeInOrder(root);
   printLevelOrder(root);
}
*/
