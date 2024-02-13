#include <iostream>
#include <mpi.h>
#include <stdlib.h>
#include <math.h>

int main(int argc, char* argv[])
{
    int rank, size;
    int x = 5;

    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);
    printf("Process rank: %d, Total processes: %d, x: %d, power function: %2f", rank, size, x, pow(x, rank));
    MPI_Finalize();
}
