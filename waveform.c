//
// Created by ADMIN on 4/10/2026.
//

#include "waveform.h"

#include <math.h>

WaveformSample records[1000];// not needed

double calculate_rms (WaveformSample * records , int count , char voltage_phase )
{

    double total = 0 ;
    for ( int i =0 ; i < count ; i++) // from 0 -- 999
    {
        if (voltage_phase =='a')
        {
            double voltA = (records+i)->phaseA;
            double squareA = voltA * voltA;
            total = total + squareA;
        }
        else if (voltage_phase =='b' )
        {
            double voltB = (records+i)->phaseB;
            double squareB = voltB * voltB;
            total = total + squareB;
        }
        else if (voltage_phase =='c' )
        {
            double voltC = (records+i)->phaseC;
            double squareC = voltC * voltC;
            total = total + squareC;
        }

    }
    double mean = total / count ;
    double rms = sqrt(mean);
    return rms;
}

