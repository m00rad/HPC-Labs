#include "Lab7.h"
using namespace std;
namespace Lab7 {
	void Lab7::Hands_On(int size, int rank, int VectorLength)
	{
		int* V1 = new int[VectorLength], * V2 = new int[VectorLength];
		int SentDataLength = VectorLength / size;
		int* RecievedDatal = new int[SentDataLength];
		int* RecievedData2 = new int[SentDataLength];
		int LocalSum = 0, FinalSum = 0;
		if (rank == 0)
		{
			for (int i = 0; i < VectorLength; i++)
			{ // you can change values of elements but you must consider that Final sum will be change too
				V1[i] = 1;
				V2[i] = 2;
			}
		}
		MPI_Scatter(V1, SentDataLength, MPI_INT, RecievedDatal, SentDataLength, MPI_INT, 0, MPI_COMM_WORLD);
		MPI_Scatter(V2, SentDataLength, MPI_INT, RecievedData2, SentDataLength, MPI_INT, 0, MPI_COMM_WORLD);
		for (int i = 0; i < SentDataLength; i++)
			LocalSum += RecievedDatal[i] * RecievedData2[i];
		printf("Local Sum =\t %d from processor %d\n", LocalSum, rank);
		MPI_Reduce(&LocalSum, &FinalSum, 1, MPI_INT, MPI_SUM, 0, MPI_COMM_WORLD);
		if (rank == 0)
		{
			for (int i = SentDataLength * size; i < VectorLength; i++)
				FinalSum += V1[i] * V2[1];
			printf("Total Sum =\t %d \n", FinalSum);
		}
	}
}