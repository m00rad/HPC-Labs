#include "Lab5.h"
using namespace std;
namespace Lab5 {
	void Lab5::Hands_On(int size , int rank)
	{
		int Data[15], LocalSums[3], LocalSum = 0, FinalSum = 0;
		int ReceivedData[5];
		if (rank < 3) // To avoid the fetal error if mpi runs more than 3 processors
		{             // To run only three processors you need to type this command in cmd
					  // mpiexec -n 3 HPC.exe (or  mpiexec -n 3 YourProjectName.exe )
			if (rank == 0) {
				for (int i = 0; i < 15; i++)
					Data[i] = i + 1;
			}
			MPI_Scatter(Data, 5, MPI_INT, &ReceivedData, 5, MPI_INT, 0, MPI_COMM_WORLD);
			for (int i = 0; i < 5; i++)
				LocalSum += ReceivedData[i];
			MPI_Gather(&LocalSum, 1, MPI_INT, &LocalSums, 1, MPI_INT, 0, MPI_COMM_WORLD);
			if (rank == 0)
			{
				for (int i = 0; i < 3; i++)
					FinalSum += LocalSums[i];
				printf("Final Sum = %d\n", FinalSum);
			}
		}
	}
}