/*
This is a 4-processor MPI example. It uses gather to collect the results from the individual process. 

The correct output is: 
0 0 204 204 408 408 612 612 
*/

#include <stdio.h>
#include "mpi.h"
int main( int argc, char **argv )
{
     int a[2][8], b[8], cpart[2], ctotal[8];
     int rank, size, i, k, root;
     MPI_Init( &argc, &argv );
     MPI_Comm_rank( MPI_COMM_WORLD, &rank );
     MPI_Comm_size( MPI_COMM_WORLD, &size );
     root = 1;
     if (size != 4) {
        printf("Error!:# of processors must be equal to 4\n");
        printf("Programm aborting....\n");
        MPI_Abort(MPI_COMM_WORLD, 1);
     }

     for (i=0;i<2;i++){
       for (k=0;k<8;k++) a[i][k] = rank*(k+1);
     }

   /* for (i=0;i<2;i++){
       for (k=0;k<8;k++) {
          if(k<7) printf("%d ",a[i][k]);
          if(k==7) printf("%d\n",a[i][k]);
       }
     }*/

     for (k=0;k<8;k++) b[k] = k+1;

     for (i=0;i<2;i++){
       cpart[i] = 0;
       for (k=0;k<8;k++) cpart[i]=cpart[i]+a[i][k]*b[k];
     }

   // printf("%d %d\n",cpart[0],cpart[1]);

 //change recieve size from 8 to 2 because the root recieve only 2 intiger data every loop
     MPI_Gather(&cpart,2,MPI_INT,&ctotal,2,MPI_INT,root,MPI_COMM_WORLD);
     if (rank == root) {
     for (k=0;k<8;k++) {
       if(k<7) printf("%d ",ctotal[k]);
        if(k==7) printf("%d\n",ctotal[k]);
     }
     }
     MPI_Finalize();
     return 0;
}
