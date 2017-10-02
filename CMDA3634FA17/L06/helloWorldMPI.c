#include <stdio.h>
#include <stdlib.h>
#include "mpi.h"

int main(int argc, char **argv){

  /* initialize MPI as soon as you enter your main function */
  MPI_Init(&argc, &argv);

  int rank, size;
  MPI_Comm_rank(MPI_COMM_WORLD, &rank);
  MPI_Comm_size(MPI_COMM_WORLD, &size);

  int dataCount = 10;
  int sourceRank = 0, destRank = size-1;
  int tag = 999;
  if(rank==sourceRank){
    int* dataOut =
      (int*) malloc(dataCount*sizeof(int));

    for(int n=0; n<dataCount; ++n){
      dataOut[n] = 2*n;
    }

    MPI_Send(dataOut, dataCount, MPI_INT, destRank, tag,  MPI_COMM_WORLD);

    free(dataOut);
  }

  if(rank==destRank){
    /* receive message */
    MPI_Status status;

    int* dataIn =
      (int*) malloc(dataCount*sizeof(int));

    for(int n=0; n<dataCount; ++n){
      dataOut[n] = 2*n;
    }

  }
 
  printf("hello world from process %0d/%0d\n", rank, size-1);

  
  /* all instances of this MPI program must enter 
     the "finalize" function before exiting */
  MPI_Finalize();
  exit(0);
  return 0;
}
