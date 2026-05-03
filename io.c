//
// Created by ADMIN on 4/10/2026.
//
#include <stdio.h>
#include <malloc.h>
#include "io.h"
#include "waveform.h"//

//WaveformSample  *  loadData(const char* filename int * counter)
 WaveformSample  *  loadData(const char* filename, int * counter)//
{
    //char filename [50];
   // printf("Enter your log file name");
   // scanf("%s" , filename);

    FILE *logFile =fopen(filename , "r");

    if (logFile== NULL)
    {
        printf("File not exist. \n\n");
        return NULL;
    }
    char line [256];
    int count = 0 ;
    fgets(line,sizeof (line) , logFile); // to avoid read the header

    while(fgets(line,sizeof (line) , logFile) ) // count how many samples we actually have
    {
        count++;
    }

    WaveformSample * records = malloc (count * sizeof ( WaveformSample)); //allocate memory depends on samples we have
    if(records == NULL)
    {
        printf("Failed");
        fclose(logFile);
        return NULL;
    }

    rewind(logFile); // to reset the cursor to the begining
    fgets(line,sizeof (line) , logFile); // to avoid read the header

    int counter2=0;
    while(fgets(line,sizeof (line) , logFile) )
  {
      sscanf(line ,"%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf" ,
             &records[counter2].time,
             &records[counter2].phaseA,
             &records[counter2].phaseB,
             &records[counter2].phaseC,
             &records[counter2].current,
             &records[counter2].frequency,
             &records[counter2].powerFactor,
             &records[counter2].percentage);
      counter2++;
  }

    fclose(logFile);
    *counter =  count;
  return records;

}

//for testing purpose only
void printAllrow( WaveformSample *records , int counter)
{
    for( int i =0 ; i < counter ;i++)//
    {
       printf("%f,%f,%f,%f,%f,%f,%f,%f \n" ,
              records[i].time,
              records[i].phaseA,
              records[i].phaseB,
              records[i].phaseC,
              records[i].current,
              records[i].frequency,
              records[i].powerFactor,
              records[i].percentage);


    }
}

void ExportData(char *filename , double rms_phaseA ,double rms_phaseB , double rms_phaseC , double peak_to_peak_A , double peak_to_peak_B ,
                        double peak_to_peak_C,double dc_offest_A , double dc_offest_B , double dc_offest_C , int clippingA , int clippingB , int clippingC )
{
    FILE * outfile = fopen(filename,"w");
    // print RMS values for phases
    fprintf(outfile , "RMS Voltages : \n");
    fprintf(outfile , "Phase A : %lf V \n" , rms_phaseA);
    fprintf(outfile , "Phase B : %lf V \n" , rms_phaseB);
    fprintf(outfile , "Phase C : %lf V \n" , rms_phaseC);
// print tolerance for lall phases

    fprintf(outfile , "RMS Tolerance : \n");
    double max_tolerance = 230 + (0.1 * 230); //253;
    double min_tolerance = 230 - (0.1 * 230); //207;

    if ( rms_phaseA >= min_tolerance && rms_phaseA <=max_tolerance)
    {
        fprintf(outfile,"Phase A : %lf --> is in accepted tolerance \n" ,rms_phaseA);
    }
    else
    {
        fprintf(outfile,"Phase A : %lf -->  is out of accepted tolerance \n",rms_phaseA);

    }

    if ( rms_phaseB >= min_tolerance && rms_phaseB <=max_tolerance)
    {
        fprintf(outfile,"Phase B :  %lf -->    is in accepted tolerance \n",rms_phaseB);
    }
    else
    {
        fprintf(outfile,"Phase B  :   %lf --> is out of accepted tolerance \n" ,rms_phaseB);

    }

    if ( rms_phaseC >= min_tolerance && rms_phaseC <=max_tolerance)
    {
        fprintf(outfile,"Phase C  : %lf -->  is in accepted tolerance \n",rms_phaseC);
    }
    else
    {
        fprintf(outfile,"Phase C   :   %lf -->  is out of accepted tolerance \n",rms_phaseC);

    }

// print V peak to peak for all phases :
    fprintf(outfile , "VPP voltages : \n");
    fprintf(outfile , "VPP A : %lf V \n" , peak_to_peak_A);
    fprintf(outfile , "VPP B : %lf V \n" , peak_to_peak_B);
    fprintf(outfile , "VPP C : %lf V \n" , peak_to_peak_C);
// Print DC offset for all phases :
    fprintf(outfile , "DC offset voltages : \n");
    fprintf(outfile , "DC offset A: %lf V \n" , dc_offest_A);
    fprintf(outfile , "DC offset B : %lf V \n" , dc_offest_B);
    fprintf(outfile , "DC offset C : %lf V \n" , dc_offest_C);
    //clipping for all phases :
    fprintf(outfile , "Clipping : \n");
    fprintf(outfile , "Clipping A: %d V \n" , clippingA);
    fprintf(outfile , "Clipping B : %d V \n" , clippingB);
    fprintf(outfile , "Clipping C : %d V \n" , clippingC);

    fclose(outfile);
}
