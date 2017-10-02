#include <stdio.h>
#include <stdlib.h>

typedef struct{

  // Start your Q4.1 code
  
  int totalNetNodes;          // first # in network.c
  int totalNodeConnections;   // second # in network.c

  int* pt_numConnections;   // counts connections of each node, respectively
  int* pt_source;           // array of pair first entries 
  int* pt_dest;             // array of pair second entries
  double *pt_pageRank;     
  // End your Q4.1 code

}Network;


Network networkReader(char* filename){

  // Start your Q4.2 code
  int n = 0;
  Network a;

  /* open file with name file name for reading */
  FILE *pt_file = fopen(filename, "r");
  
  
  fscanf(pt_file, "%d,%d,", &a.totalNetNodes, &a.totalNodeConnections);
  
  /* set up storage for array */
  int maxCombinations  =  a.totalNetNodes * a.totalNodeConnections;
  a.pt_numConnections = (int*) malloc(a.totalNetNodes * sizeof(int));
  a.pt_source = (int*) malloc(maxCombinations * sizeof(int));
  a.pt_dest = (int*) malloc(maxCombinations * sizeof(int));
  
  // setup char array for using fgets() to read csv
  char temp[maxCombinations + 1];
  
  /* loop through array and read size ints */
  while (fgets(temp, sizeof(temp), pt_file) != NULL){
  //
    /* read each pair of integers into the n'th integer slot
       after the start of the array data store */
    fscanf(pt_file, "%d,%d,", a.pt_source+n, a.pt_dest+n);
    a.pt_numConnections[*(a.pt_source+n)]++;
    n++;

    //if... else if... to check correct files
  }

  /* close file when done */
  fclose(pt_file);

  return a;
  // End your Q4.2 code

}

int main(int argc, char** argv){

  // Reads the input filename of the data file
  char* filename = argv[1];

  // Reads the input of the node number, stores in i
  int i = atoi(argv[2]);

  
  // Start your Q4.3 code
  Network mainNet = networkReader(filename);

  printf("Node %d is connected to %d nodes.\n Those nodes are:\n",
	 i, *(mainNet.pt_numConnections+i)); 
  
  for (int index=0; index < mainNet.totalNetNodes; index++){

    /* if the n'th entry of the source array matches i,
       the print the n'th entry of the destination array*/
    if (*(mainNet.pt_source+index) == i){
      printf("%d\n", *(mainNet.pt_dest+index));
    }
  }


  // End your Q4.3 code
}
