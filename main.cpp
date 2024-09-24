#include "./dataSender.h"

int main()
{
    srand(static_cast<unsigned int>(time(0))); // Seed random number generator

   generateData();

   return 0;
}