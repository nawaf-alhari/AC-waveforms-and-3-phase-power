#include <stdio.h>
#include "io.h"
#include "waveform.h"
int main( )
{
    int counter=0;
    int clippingA =0;
            int clippingB =0 ; int clippingC = 0;
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


    double peak_to_peak_A = calculate_peak_to_peak(records, counter, 'a');
    double peak_to_peak_B = calculate_peak_to_peak(records, counter, 'b');
    double peak_to_peak_C = calculate_peak_to_peak(records, counter, 'c');

    printf("peak to peak for phase A = %lf\n",peak_to_peak_A);
    printf("peak to peak for phase B = %lf\n",peak_to_peak_B);
    printf("peak to peak for phase C = %lf\n",peak_to_peak_C);


    double dc_offest_A = calculate_dc_offset(records, counter, 'a');
    double dc_offest_B = calculate_dc_offset(records, counter, 'b');
    double dc_offest_C = calculate_dc_offset(records, counter, 'c');

    printf("Dc offset phase A = %lf\n",dc_offest_A);
    printf("Dc offset phase B = %lf\n",dc_offest_B);
    printf("Dc offset phase C = %lf\n",dc_offest_C);

    check_phase_tolerance (  rms_phaseA , rms_phaseB , rms_phaseC);

    clippingA=  get_data_clipping(records,counter , 'a');
    clippingB=  get_data_clipping(records,counter , 'b');
    clippingC=  get_data_clipping(records,counter , 'c');

    printf("Clipping A = %d \n",clippingA);
    printf("Clipping B = %d\n",clippingB);
    printf("Clipping C = %d\n",clippingC);

    generateResultFile("result.txt",rms_phaseA,rms_phaseB , rms_phaseC , peak_to_peak_A, peak_to_peak_B , peak_to_peak_C , dc_offest_A
                      , dc_offest_B , dc_offest_C , clippingA , clippingB , clippingC  );

    return 0;
}
