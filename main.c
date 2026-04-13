#include <stdio.h>
#include "io.h"
#include "waveform.h"
#define  size 1000
int main( )
{

    printf("Welcome to AcWaveform mini project \n\n");
    struct WaveformSample records[size];
  int count=  loadData(records);

   // printAllrow(records,size); to test data
    printf("connt is %d" ,count);



    return 0;
}
