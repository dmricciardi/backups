#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/* Author: Domenic Ricciardi */

typedef struct{

  // Start your code
  int nodes;
  int maxConnects;
  int* pt_connectCount;
  int* pt_source;
  int* pt_dest;  

  //double* pt_pageRank;
  double* pt_oldPageRank;
  double* pt_newPageRank;
  // End your code

}Network;


Network networkReader(char* filename){

  // Start your code
  Network g;
  int i, j, temp;
  FILE *fp;
  int source;
  int dest;
  int count=0;

  fp = fopen(filename, "r");
  fscanf(fp, "%d,", &g.nodes);
  temp = fscanf(fp, "%d,", &g.maxConnects);

  g.pt_connectCount = (int*)calloc(g.nodes, sizeof(int));
  g.pt_source = (int*)calloc(g.nodes * g.maxConnects, sizeof(int));
  g.pt_dest = (int*)calloc(g.nodes * g.maxConnects, sizeof(int));

  //g.pt_pageRank = (double*)calloc(g.nodes, sizeof(double));
  g.pt_oldPageRank = (double*)calloc(g.nodes, sizeof(double));
  g.pt_newPageRank = (double*)calloc(g.nodes, sizeof(double));
 
  // Check if fscanf has read to the End of File
  do{
    temp = fscanf(fp, "%d,%d,", &source, &dest);     
    if(temp==EOF) break;
    g.pt_source[count]=source;
    g.pt_dest[count]=dest;
    g.pt_connectCount[g.pt_source[count]]++;
    count++;
  }while(temp != EOF);

  fclose(fp);

  return g;
  // End your code
}

double computeDiff(Network net){

  int i;
  double diff = 0.0;

  for(i = 0; i < net.nodes; i++){
    diff += pow(net.pt_newPageRank[i] - net.pt_oldPageRank[i], 2);
  }

  diff = sqrt(diff);
  return diff;

}

double updatePageRank(Network net, double d){
  /* Q3.2 Code */

  int numConnects, srcNode, i, j;
  double con, temp;

  // con serves as the constant starting value for new Page Ranks
  con = (1 - d) / net.nodes;

  // numConnects counts how many connections exist
  numConnects = 0;
  
  for (i = 0; i < net.nodes; i++){
    
    numConnects += net.pt_connectCount[i];
    net.pt_oldPageRank[i] = net.pt_newPageRank[i];
    net.pt_newPageRank[i] = con;
  }
 
  for (j = 0; j < numConnects; j++){

    srcNode = net.pt_source[j];
    temp = net.pt_oldPageRank[srcNode] / net.pt_connectCount[srcNode];
    net.pt_newPageRank[net.pt_dest[j]] += d*temp;
    
  }

  return computeDiff(net);

  /* End Q3.2 Code */
}

void computePageRank(Network net, double tol, double d){

  int i;
  double diffNorm = 0.0;
  int count = 0;

  // initialize all page ranks
  for (i = 0; i < net.nodes; i++){
    net.pt_newPageRank[i] = 1.0/net.nodes;
    net.pt_oldPageRank[i] = 1.0/net.nodes;
  }
  
  while (diffNorm >= tol || count == 0){

    diffNorm = updatePageRank(net, d);
    count++;

    //printf("After %d iterations, diffNorm = %f\n", count, diffNorm);
  }
  
}

int main(int argc, char** argv){

  // Reads the filename of the data file
  char* filename = argv[1];

  // Reads the input of the node number, stores in i
  int i = atoi(argv[2]);

  // Read the inputs for d and tol, respectively
  double d = atof(argv[3]);
  double tol = atof(argv[4]);

  //Start your code
  
  Network network_t = networkReader(filename);

  // Compute Page Rank and Print Results
  computePageRank(network_t, tol, d);
  printf("The pageRank of node %d is:\n%lf \n", i, network_t.pt_newPageRank[i]);
  
  return 0;
}
