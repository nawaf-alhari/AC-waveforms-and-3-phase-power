//
// Created by ADMIN on 4/10/2026.
//

#ifndef ACWAVEFORM_IO_H
#define ACWAVEFORM_IO_H


#include "waveform.h"

WaveformSample  * loadData(int * counter);

void printAllrow( WaveformSample *records , int size);

void generateResultFile(char *filename , double rms_phaseA ,double rms_phaseB , double rms_phaseC , double peak_to_peak_A , double peak_to_peak_B ,
                        double peak_to_peak_C,double dc_offest_A , double dc_offest_B , double dc_offest_C , int clippingA , int clippingB , int clippingC );
#endif //ACWAVEFORM_IO_H

