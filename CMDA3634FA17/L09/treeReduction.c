#include <stdlib.h>
#include <stdio.h>
#include "mpi.h"

double treeReduction(double val){


  int rank, size, tag;

  double *sendBuffer =
    (double*) malloc(sizeof(double));
  double *recvBuffer =
    (double*) malloc(sizeof(double));


  MPI_Comm_rank(MPI_COMM_WORLD, &rank);
  MPI_Comm_size(MPI_COMM_WORLD, &size);

  sendBuffer[0] = val;

  int alive = size;


  while (alive > 1){
    if(rank >= (alive/2)){

      int dest = rank - (alive/2);
      
      //MPI_Send to rank - (alive/2)
      MPI_Send(sendBuffer,
	       1,
	       MPI_DOUBLE,
	       dest,
	       tag,
	       MPI_COMM_WORLD);
    }
      
      if(rank < (alive/2)){
	int source = rank + (alive/2);
	
	//MPI_Recv from rank + (alive/2)
	MPI_Recv(recvBuffer,
	       1,
	       MPI_DOUBLE,
	       source,
	       tag,
	       MPI_COMM_WORLD);
		 
    
	//add incoming data to our data
	sendBuffer[0] += recvBuffer;
      }

      alive /= 2;
  }

  return sendBuffer[0];
}


int main(int argc, char** argv){

  MPI_Init(&argc, &argv);

  double val = 1;

  double reducedBal = treeReduction(val);

  int rank;

  MPI_Comm_rank(MPI_COMM_WORLD, &rank);

  MPI_Finalize;
}
