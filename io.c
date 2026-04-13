//
// Created by ADMIN on 4/10/2026.
//
#include <stdio.h>
#include "io.h"
#include "waveform.h"


int  loadData(struct WaveformSample records [])
{
    char filename [50];
    printf("Enter your log file name");
    scanf("%s" , filename);

    FILE *logFile =fopen(filename , "r");

    if (logFile== NULL)
    {
        printf("File not exist. \n\n");
        return -1;
    }
    char line [256];
    int counter = 0 ;

    fgets(line,sizeof (line) , logFile); // to avoid read the header

  while(fgets(line,sizeof (line) , logFile) && counter < 1000)
  {
      sscanf(line ,"%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf" ,
             &records[counter].time,
             &records[counter].phaseA,
             &records[counter].phaseB,
             &records[counter].phaseC,
             &records[counter].current,
             &records[counter].frequency,
             &records[counter].powerFactor,
             &records[counter].percentage);
      counter++;
  }

    fclose(logFile);
  return counter;

}

//for testing purpose only
void printAllrow(struct WaveformSample *records , int size)
{
    for( int i =0 ; i < 1000 ;i++)
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
