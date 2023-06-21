#include <iostream>
#include <mpi.h>
#include "Lab3.h"
#include "Lab4.h"
#include "Lab5.h"
#include "Lab6.h"
#include "Lab7.h"
#include "Lab9.h"

using namespace std;
int main() {
	MPI_Init(NULL, NULL);
	int size, rank;
	MPI_Comm_size(MPI_COMM_WORLD, &size);
	MPI_Comm_rank(MPI_COMM_WORLD, &rank);
	Lab4::Lab4 lab4;
	lab4.Hands_On2(size, rank);
	MPI_Finalize();
	return 0;
}

