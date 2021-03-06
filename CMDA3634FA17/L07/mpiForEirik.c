#include <stdio.h>
#include <stdlib.h>
#include <mpi.h>

int main( int argc, char **argv){

  MPI_Init(&argc, &argv);

  int message, rank, size, tag;
  MPI_Comm_rank(MPI_COMM_WORLD, &rank);
  MPI_Comm_size(MPI_COMM_WORLD, &size);

  if (rank == 0)
    MPI_Send(&message, 1, MPI_INT, rank+1, tag, MPI_COMM_WORLD);

  else {
    MPI_Recv(&message, 1, MPI_INT, rank-1, tag, MPI_COMM_WORLD);
    if (rank+1<size)
      MPI_Send(&message, 1, MPI_INT, rank+1, tag, MPI_COMM_WORLD);
  }

  
  if (rank == size-1)
    MPI_Send(&message, 1, MPI_INT, rank-1, tag, MPI_COMM_WORLD);

  else {
    MPI_Recv(&message, 1, MPI_INT, rank+1, tag, MPI_COMM_WORLD);
    if (rank+1<size)
      MPI_Send(&message, 1, MPI_INT, rank-1, tag, MPI_COMM_WORLD);
  }

  if(rank == 0)
    printf("success!");
  
  MPI_Finalize();
}
