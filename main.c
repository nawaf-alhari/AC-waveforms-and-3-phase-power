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

    double rms_phaseA = calculate_rms(records,counter,'a');
    double rms_phaseB = calculate_rms(records,counter,'b');
    double rms_phaseC = calculate_rms(records,counter,'c');

    printf("RMS for phase A is %lf\n" ,rms_phaseA);
    printf("RMS for phase B is %lf\n" ,rms_phaseB);
    printf("RMS for phase C is %lf\n" ,rms_phaseC);




    return 0;
}

