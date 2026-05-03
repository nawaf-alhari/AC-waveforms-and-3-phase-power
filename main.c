#include <stdio.h>
#include "io.h"
#include "stdlib.h"
#include "waveform.h"
int main( )
{
    int counter=0;
    int clippingA =0;
    int clippingB =0 ;
    int clippingC = 0;

    WaveformSample  *records = loadData("power_quality_log.csv" ,&counter);
    printf("count is %d\n" ,counter);
    double rms_phaseA = calculate_rms(records,counter,'a');
    double rms_phaseB = calculate_rms(records,counter,'b');
    double rms_phaseC = calculate_rms(records,counter,'c');
    double peak_to_peak_A = calculate_peak_to_peak(records, counter, 'a');
    double peak_to_peak_B = calculate_peak_to_peak(records, counter, 'b');
    double peak_to_peak_C = calculate_peak_to_peak(records, counter, 'c');
    double dc_offest_A = calculate_dc_offset(records, counter, 'a');
    double dc_offest_B = calculate_dc_offset(records, counter, 'b');
    double dc_offest_C = calculate_dc_offset(records, counter, 'c');
    check_phase_tolerance (  rms_phaseA , rms_phaseB , rms_phaseC);
    clippingA=  get_data_clipping(records,counter , 'a');
    clippingB=  get_data_clipping(records,counter , 'b');
    clippingC=  get_data_clipping(records,counter , 'c');

    ExportData("result.txt",rms_phaseA,rms_phaseB , rms_phaseC , peak_to_peak_A, peak_to_peak_B , peak_to_peak_C , dc_offest_A
                      , dc_offest_B , dc_offest_C , clippingA , clippingB , clippingC  );
free(records);

    return 0;
}
