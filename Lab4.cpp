#include <iostream>
#include <mpi.h>
#include "Lab4.h"

using namespace std;
namespace Lab4 {

	void Lab4::Hands_On1(int Size, int Rank)
	{
		MPI_Status Status;
		int x0 , y0;
		int Receiver = (Rank + 1) % 4;
		int Sender = ((Rank - 1) + 4) % 4;
		int Root = 0;
		if (Rank == 0) {
			x0 = 10;
			MPI_Send(&x0, 1, MPI_INT, Receiver, Root, MPI_COMM_WORLD);
			MPI_Recv(&y0, 1, MPI_INT, Sender, Root, MPI_COMM_WORLD, &Status);
			printf("%d Received Hello from %d \n", Rank, Sender);
		}
		else if (Rank < 4) {
			y0 = 10;
			MPI_Recv(&x0, 1, MPI_INT, Sender, Root, MPI_COMM_WORLD, &Status);
			printf("%d Received Hello from %d \n", Rank, Sender);
			MPI_Send(&y0, 1, MPI_INT, Receiver, Root, MPI_COMM_WORLD);
		}
		// this hands on could be implemented by the following code 
		/*
		MPI_Status Status;
		if (Rank == 0) {
			int x0 = 10, y0;
			MPI_Send(&x0, 1, MPI_INT, 1, 0, MPI_COMM_WORLD);
			MPI_Recv(&y0, 1, MPI_INT, 3, 0, MPI_COMM_WORLD, &Status);
			printf("%d Received Hello from 3 \n", Rank);
		}
		else if (Rank == 1) {
			int x1, y1 = 5;
			MPI_Recv(&x1, 1, MPI_INT, 0, 0, MPI_COMM_WORLD, &Status);
			printf("%d Received Hello from 0\n", Rank);
			MPI_Send(&y1, 1, MPI_INT, 2, 0, MPI_COMM_WORLD);
		}
		else if (Rank == 2)
		{
			int x2, y2 = 5;
			MPI_Recv(&x2, 1, MPI_INT, 1, 0, MPI_COMM_WORLD, &Status);
			printf("%d Received Hello from 1\n", Rank);
			MPI_Send(&y2, 1, MPI_INT, 3, 0, );
		}
		else if (Rank == 3)
		{
			int x3, y3 = 5;
			MPI_Recv(&x3, 1, MPI_INT, 2, 0, MPI_COMM_WORLD, &Status);
			printf("%d Received Hello from 2\n", Rank);
			MPI_Send(&y3, 1, MPI_INT, 0, 0, MPI_COMM_WORLD);
		}
		*/

	}
	void Lab4::Hands_On2(int Size, int Rank)
	{
		MPI_Status Status;
		int Data[15], LocalSum = 0, FinalSum = 0;
		int ReceivedData[5];
		if (Rank == 0) {
			int LocalSum1, LocalSum2;
			for (int i = 0; i < 15; i++)
				Data[i] = i + 1;
			MPI_Send(&Data[5], 5, MPI_INT, 1, 0, MPI_COMM_WORLD);
			MPI_Send(&Data[10], 5, MPI_INT, 2, 0, MPI_COMM_WORLD);
			for (int i = 0; i < 5; i++)
				LocalSum += Data[i];
			MPI_Recv(&LocalSum1, 1, MPI_INT, 1, 0, MPI_COMM_WORLD, &Status);
			MPI_Recv(&LocalSum2, 1, MPI_INT, 2, 0, MPI_COMM_WORLD, &Status);
			FinalSum = LocalSum + LocalSum1 + LocalSum2;
			printf("TotalSum =\t%d\n", FinalSum);
		}
		else if (Rank < 3) {
			MPI_Recv(&ReceivedData, 5, MPI_INT, 0, 0, MPI_COMM_WORLD, &Status);
			for (int i = 0; i < 5; i++) 
				LocalSum += ReceivedData[i];
			MPI_Send(&LocalSum, 1, MPI_INT, 0, 0, MPI_COMM_WORLD);
		}
	}
}
