//
// Created by ADMIN on 4/10/2026.
//

#include "waveform.h"
#include <stdio.h>
#include <math.h>

//WaveformSample records[1000];// not needed

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

double calculate_peak_to_peak (WaveformSample * records , int count , char voltage_phase )
{
    double max = 0;
    double min = 0;
        switch (voltage_phase)
        {
            case 'a' :       max = records->phaseA;
                             min = records->phaseA;
                              break;
            case 'b' :        max = records->phaseB;
                              min = records->phaseB;
                               break;
            case 'c' :        max = records->phaseC;
                              min = records->phaseC;
                               break;
        }
    for (int i = 0; i < count; i++)
    {
        if (voltage_phase == 'a')
        {
            double voltA = (records + i)->phaseA;
            if (voltA > max)
            {
                max = voltA;
            }
            if (voltA < min)
            {
                min = voltA;
            }
        }
        else if (voltage_phase == 'b')
        {
            double voltB = (records + i)->phaseB;
            if (voltB > max)
            {
                max = voltB;
            }
            if (voltB < min)
            {
                min = voltB;
            }
        }
        else if (voltage_phase == 'c')
        {
            double voltC = (records + i)->phaseC;
            if (voltC > max)
            {
                max = voltC;
            }
            if (voltC < min)
            {
                min = voltC;
            }
        }
    }
    double peak_to_peak = max - min;
    return peak_to_peak;
}

double calculate_dc_offset (WaveformSample * records , int count , char voltage_phase )
{
    double total = 0 ;
    for ( int i =0 ; i < count ; i++) // from 0 -- 999
    {
        if (voltage_phase =='a')
        {
            total = total + (records+i)->phaseA;
        }
        else if (voltage_phase =='b' )
        {
            total = total + (records+i)->phaseB;

        }
        else if (voltage_phase =='c' )
        {
            total = total + (records+i)->phaseC;

        }
    }
    double mean = total / count ;
    return mean;
}

void check_phase_tolerance ( double rms_phaseA , double rms_phaseB ,  double rms_phaseC)
{
    double max_tolerance = 230 + (0.1 * 230); //253;
    double min_tolerance = 230 - (0.1 * 230); //207;

    if ( rms_phaseA >= min_tolerance && rms_phaseA <=max_tolerance)
    {
        printf("Phase A : %lf --> is in normal range \n" ,rms_phaseA);
    }
    else
    {
        printf("Phase A : %lf -->  is out of normal range \n",rms_phaseA);

    }

    if ( rms_phaseB >= min_tolerance && rms_phaseB <=max_tolerance)
    {
        printf("Phase B :  %lf -->    is in normal range \n",rms_phaseB);
    }
    else
    {
        printf("Phase B  :   %lf --> is out of normal range \n" ,rms_phaseB);

    }

    if ( rms_phaseC >= min_tolerance && rms_phaseC <=max_tolerance)
    {
        printf("Phase C  : %lf -->  is in normal range \n",rms_phaseC);
    }
    else
    {
        printf("Phase C   :   %lf -->  is out of normal range \n",rms_phaseC);

    }
}

int get_data_clipping (WaveformSample * records , int count , char voltage_phase  )
{
    int clipping_number = 0 ;
    for ( int i =0 ; i < count ; i++) // from 0 -- 999
    {
        if (voltage_phase =='a')
        {
            double voltage = (records+i)->phaseA;
            if(fabs (voltage ) >= 324.9)
            {
                clipping_number++;
            }
        }
        else if (voltage_phase =='b' )
        {
            double voltage = (records+i)->phaseB;
            if(fabs (voltage)  >= 324.9 )
            {
                clipping_number++;
            }

        }
        else if (voltage_phase =='c' )
        {
            double voltage = (records+i)->phaseC;
            if(fabs (voltage ) >= 324.9 )
            {
                clipping_number++;
            }

        }
    }
    return clipping_number;
}