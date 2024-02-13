#include <iostream>
#include <mpi.h>
#include <stdlib.h>
#include <math.h>

int main(int argc, char* argv[])
{
    int rank, size;
    int a = 5, b = 10;

    scanf_s("%d %d", &a, &b);

    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);
    MPI_Status status;
    if (rank == 0) {

        // Summation
        MPI_Send(&a, 1, MPI_INT, 1, 0, MPI_COMM_WORLD);
        MPI_Send(&b, 1, MPI_INT, 1, 1, MPI_COMM_WORLD);

        // Difference
        MPI_Send(&a, 1, MPI_INT, 2, 2, MPI_COMM_WORLD);
        MPI_Send(&b, 1, MPI_INT, 2, 3, MPI_COMM_WORLD);

        // Product
        MPI_Send(&a, 1, MPI_INT, 3, 4, MPI_COMM_WORLD);
        MPI_Send(&b, 1, MPI_INT, 3, 5, MPI_COMM_WORLD);

        // Division
        MPI_Send(&a, 1, MPI_INT, 4, 6, MPI_COMM_WORLD);
        MPI_Send(&b, 1, MPI_INT, 4, 7, MPI_COMM_WORLD);

    }
    else if (rank == 1) {
        MPI_Recv(&a, 1, MPI_INT, 0, 0, MPI_COMM_WORLD, &status);
        MPI_Recv(&b, 1, MPI_INT, 0, 1, MPI_COMM_WORLD, &status);
        printf("Summation: %d", a + b);
    }
    else if (rank == 2) {
        MPI_Recv(&a, 1, MPI_INT, 0, 2, MPI_COMM_WORLD, &status);
        MPI_Recv(&b, 1, MPI_INT, 0, 3, MPI_COMM_WORLD, &status);
        printf("Difference: %d", a - b);
    }
    else if (rank == 3) {
        MPI_Recv(&a, 1, MPI_INT, 0, 4, MPI_COMM_WORLD, &status);
        MPI_Recv(&b, 1, MPI_INT, 0, 5, MPI_COMM_WORLD, &status);
        printf("Product: %d", a * b);
    }
    else if (rank == 4) {
        MPI_Recv(&a, 1, MPI_INT, 0, 6, MPI_COMM_WORLD, &status);
        MPI_Recv(&b, 1, MPI_INT, 0, 7, MPI_COMM_WORLD, &status);
        printf("Division: %2f", (a * 1.00) / b);
    }
    MPI_Finalize();
    return 0;
}
