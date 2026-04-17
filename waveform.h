//
// Created by ADMIN on 4/10/2026.
//
#ifndef ACWAVEFORM_WAVEFORM_H
#define ACWAVEFORM_WAVEFORM_H
// 1- Define a WaveformSample struct
typedef struct  {
    double time ;
    double phaseA;
    double phaseB;
    double phaseC;
    double current;
    double frequency;
    double powerFactor;
    double percentage;
}WaveformSample;


double calculate_rms (WaveformSample * records , int count , char voltage_phase );

double calculate_peak_to_peak (WaveformSample * records , int count , char voltage_phase );


#endif //ACWAVEFORM_WAVEFORM_H
