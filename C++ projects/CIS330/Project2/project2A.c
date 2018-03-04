
#include <stdlib.h>
#include <stdio.h>

int main(){
   int *A =  malloc(sizeof(int)*21);
   int *B[3] = {A,A+7,A+14};
A[0]=0;
A[1]=1;
A[2]=1;
A[3]=2;
A[4]=3;
A[5]=5;
A[6]=8; 
A[7]=13;
A[8]=21;
A[9]=34;
A[10]=55;
A[11]=89;
A[12]=144;
A[13]=233;
A[14]=377;
A[15]=610;
A[16]=987;
A[17]=1597;
A[18]=2584;
A[19]=4181;
A[20]=6765;
   printf("*A = %d\n", *A);
   printf("B[1][3] = %d\n", B[1][3]);
   printf("*(A=4) = %d\n", *(A+4));
   printf("(A+6) = %p\n", (A+6));
   printf("B[2][0]-B[1][6] = %d\n", B[2][0]-B[1][6]);
   printf("B[2][0]-B[1][7] = %d\n", B[2][0]-B[1][7]);
   printf("(A+6)-(A+3) = %ld\n",(A+6)-(A+3));
   printf("*(A+6)-*(A+2) = %d\n",*(A+6)-*(A+2));
   printf("A[5]-*(A+4) = %d\n", A[5]-*(A+4));
   printf("(A+9)-B[0] = %ld\n", (A+9)-B[0]);
   printf("B[0] = %p\n", B[0]);
   printf("B[2][2]-A[15] = %d\n",B[2][2]-A[15]);
   printf("&(B[2][3])-&(A[15]) = %ld\n", &(B[2][3])-&(A[15]));
   printf("*(&A[6]) = %d\n", *(&A[6]));


   return 0;
}
