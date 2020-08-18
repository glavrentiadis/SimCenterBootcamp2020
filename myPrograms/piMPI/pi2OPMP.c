#include <stdio.h>
#include <time.h>
#include <omp.h>

static int long numSteps = 1000000000;

int main(int argc, char **argv) {

  double pi   = 0;
  double stepSize = 1.0/(double) numSteps;
  
#pragma omp parallel reduction(+:pi)
  {
    int tid = omp_get_thread_num();
    int numT = omp_get_num_threads();

    for (int i=tid; i<numSteps; i+=numT) {
      double x = (i+0.5)*stepSize;
      pi += 4./(1.+x*x);
    }
  }
  
  pi *= stepSize;
  
  printf("PI = %16.14f\n",pi);
  return 0;
}
