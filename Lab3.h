#pragma once
#include <mpi.h>
#include <iostream>
#include <stdio.h>

namespace Lab3 {
    class Lab3
    {
    public:
        void Hands_On(int Size, int Rank);
        void Hello(int Size, int Rank);
    };
}