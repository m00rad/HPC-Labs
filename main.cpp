#include <mpi.h>
#include <iostream>
#include <stdio.h>
#include "Lab3.h"

using namespace std;
int main() {
	MPI_Init(NULL, NULL);
	int size, rank;
	MPI_Comm_size(MPI_COMM_WORLD, &size);
	MPI_Comm_rank(MPI_COMM_WORLD, &rank);
	Lab3::Lab3 lab3;
	lab3.Hello(size, rank);
	MPI_Finalize();
	return 0;
}

