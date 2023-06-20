#include <mpi.h>
#include <iostream>
#include <stdio.h>
using namespace std;
int main() {
	MPI_Init(NULL, NULL);
	int size, rank;
	
	MPI_Finalize();
	return 0;
}

