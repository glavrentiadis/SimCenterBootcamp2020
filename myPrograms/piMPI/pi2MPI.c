#include <mpi.h>
#include <stdio.h>
#include <time.h>

static int long numSteps = 1000000000;

int main(int argc, char **argv) {

  int procID, numP;
  double pi = 0;
  double stepSize = 1.0/(double) numSteps;
  MPI_Status status;

  MPI_Init(&argc, &argv);
  MPI_Comm_size( MPI_COMM_WORLD, &numP);
  MPI_Comm_rank( MPI_COMM_WORLD, &procID);

  /*  if (procID == 0) {
    double pi0 = 0;
    for (int i=0; i<numSteps/&numP; i++){
      double x = (i + 0.5)*stepSize;
 
      pi0 += 4./(1. + x*x);
      MPI_Send(pi0, 1, MPI_INT, 1, 0, MPI_COMM_WORLD);
    } else  {
  */  
  for (int i=procID; i<numSteps; i+=numP) {
    double x = (i+0.5)*stepSize;
    pi += 4./(1.+x*x);

  }

  pi *= stepSize;
  
  if (procID == 0){
    for (int i=1; i<= numP; i++){
      MPI_Recv(&pi, 1, MPI_INT, i, 0, MPI_COMM_WORLD, &status);
    }
    printf("PI = %16.14f\n",pi);
  }else{
    MPI_Send(&pi, 1, MPI_INT, 0, 0, MPI_COMM_WORLD);
  }

  MPI_Finalize();
  return 0;
}
