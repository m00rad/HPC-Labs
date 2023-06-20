#include "Lab3.h"
#include <mpi.h>
#include <iostream>
#include <stdio.h>
using namespace std;
namespace Lab3 {
	void Lab3::Hands_On(int Size, int Rank)
	{
		int x, y;
		MPI_Status Status;
		if (Rank == 0)
		{
			x = 10;
			MPI_Send(&x, 1, MPI_INT, 1, 0, MPI_COMM_WORLD);
			MPI_Recv(&y, 1, MPI_INT, 1, 0, MPI_COMM_WORLD, &Status);
			printf("ping  %d\n", y);
		}
		else if (Rank == 1)
		{
			y = 5;
			MPI_Recv(&x, 1, MPI_INT, 0, 0, MPI_COMM_WORLD, &Status);
			MPI_Send(&y, 1, MPI_INT, 0, 0, MPI_COMM_WORLD);
			printf("pong  %d\n", x);
		}
	}
	void Lab3::Hello(int Size, int Rank)
	{
		char procrssor_name[MPI_MAX_PROCESSOR_NAME];
		int name;
		MPI_Get_processor_name(procrssor_name, &name);
		printf("Hello my name is %s with rank %d out of %d processors \n",procrssor_name,Rank,Size);
	}
}
