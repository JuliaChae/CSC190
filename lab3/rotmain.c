#include <stdio.h>
#include <stdlib.h>
#include "avlrot.c"

int main(void) {
   avlNode *root=NULL;
   add_avl(&root,4);
   add_avl(&root,3);
   add_avl(&root,9);
   add_avl(&root,7);
   add_avl(&root,10);
   add_avl(&root,6);
   add_avl(&root,8);
   printf("%d\n", isAVL(&root));
   printLevelOrder(root);
   printf("\n");
   dblrotate(&root,0);
   printLevelOrder(root);
}


