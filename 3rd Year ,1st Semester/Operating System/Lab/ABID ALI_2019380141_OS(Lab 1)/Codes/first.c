

 #include <stdio.h>
 #include <stdlib.h>

 int var1;            /* a staticly allocated variable */

 int my_func (int i) {      /* a my_func sive function */
     int j = i;            /* a stack allocated variable within a my_func sive function */
     printf("my_func  call (i)%d: stack@ %lx\n", i, (long unsigned int) &j); /* fix this so it print
 s the address of j */
     if (i > 0) {
         return my_func (i-1);
     }
     return 0;
 }

 volatile int stuff = 7;          /* a statically allocarted, pre-initialized variable */

 int main (int argc, char *argv[]) {
     volatile int i = 0;          /* a stack allocated variable */
     volatile char *buf1 = malloc(10); /* dynamically allocate some stuff */
     volatile char *buf2 = malloc(10); /* and some more stuff */
     printf("Answer to the question Number 2(1)\n");
     printf("main  @ %lx\n", (long unsigned int) &main); /* fix to print address of main */
     printf("my_func  @ %lx\n", (long unsigned int) &my_func ); /* fix to print address of my_func  */
     printf("main call (i):stack@ %lx\n", (long unsigned int) &i); /* fix to get address of the s
 tack variable */
     printf("static var1: %lx\n", (long unsigned int) &var1); /* fix to get address of the static v
 ariable */
     printf("static stuff: %lx\n", (long unsigned int) &stuff); /* fix to get address of a stati
 c variable */
     printf("Heap: malloc 1: %lx\n", (long unsigned int) buf1);
     printf("Heap: malloc 2: %lx\n", (long unsigned int) buf2);
     my_func (3);
     printf("Answer to the question Number 2(2)\n");
     printf("Pointed to by argv is %s\n",argv[0]);
     printf("The value of argv is %s\n",*argv);
     printf("The value of argc is %d\n",argc);
     return 0;
 }
