#include "lab3_A.c"

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
