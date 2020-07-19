#include <stdio.h>

unsigned char FSR(unsigned char x) {
   unsigned char oldbit0 = x & 0x1; /* extract bit 0 */
   unsigned char r = x >> 1;        /* shift right   */
   unsigned char newbit7 = oldbit0 << 7; /* move bit0 to the bit7 pos */
   r = r | newbit7; /* rotate the old value of bit 0 into the bit 7 pos */
   return r;
}

unsigned char prng(unsigned char x, unsigned char pattern){
   unsigned char oldbit0 = x & 0x1; /* extract bit 0 */
   unsigned char r = x >> 1;        /* shift right   */
   unsigned char newbit7 = oldbit0 << 7; /* move bit0 to the bit7 pos */
   r = r | newbit7; /* rotate the old value of bit 0 into the bit 7 pos */
   r = r ^ pattern;
   return r;
}

int crypt(char *data, unsigned int size, unsigned char password){
   unsigned char prngVal;
   int i =0;
   if (data == NULL|| password == 0x0){
      return -1;
   } 
   prngVal = password; 
   for (i=0;i<size;i++){
      prngVal = prng(prngVal,0xb8);
      data[i] = data[i] ^ prngVal;
   }
   //printf("%x\n",data);
   return 0;
}

int main(void){
   char charArray[5]="abcd";
   printf("%x\n",FSR('c'));
   printf("%x\n",prng('c',0xb8));
   printf("%d\n",crypt(charArray,4,0x1));
   printf("%s\n",charArray);
   printf("%d\n",crypt(charArray,4,0x1));
   printf("%s\n",charArray);
}
