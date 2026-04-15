#include <stdio.h>
#include "io.h"
#include "waveform.h"
int main( )
{
    int counter=0;
    printf("Welcome to AcWaveform mini project \n\n");
    WaveformSample * records = loadData( &counter);


   // printAllrow(records,size); to test data

    printAllrow(records , counter);
    printf("count is %d\n" ,counter);



    return 0;
}
