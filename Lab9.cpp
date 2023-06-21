#include "Lab9.h"
using namespace std;
namespace Lab9 {
	void Lab9::Hands_On(int size, int rank)
	{
		int  Length, N;
		float LocalSum = 0, FinalSum = 0;
		MPI_Comm_size(MPI_COMM_WORLD, &size);
		MPI_Comm_rank(MPI_COMM_WORLD, &rank);
		if (rank == 0) {
			printf(" Please enter length of Summation \n");
			cin >> Length;
		}
		MPI_Bcast(&Length, 1, MPI_INT, 0, MPI_COMM_WORLD);
		N = Length / size;
		int StartLengh = (rank * N) + 1, StopLength = (rank + 1) * N;
		for (int i = StartLengh; i < StopLength; i++)
			LocalSum += 1 / (1 + (((i - .5) / Length) * ((i - .5) / Length)));
		MPI_Reduce(&LocalSum, &FinalSum, 1, MPI_FLOAT, MPI_SUM, 0, MPI_COMM_WORLD);
		if (rank == 0)
		{
			if (Length % size != 0)
			{
				StartLengh = (size * N) + 1, StopLength = Length;
				for (int i = StartLengh; i <= StopLength; i++)
					FinalSum += 1 / (1 + (((i - .5) / Length) * ((i - .5) / Length)));
			}
			float Pi = FinalSum * (4 / (double)Length);
			printf("Pi = %f \t\n", Pi);
		}
	}
}
