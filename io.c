//
// Created by ADMIN on 4/10/2026.
//
#include <stdio.h>
#include <malloc.h>
#include "io.h"
#include "waveform.h"//


 WaveformSample  *  loadData(int * counter)//
{
    char filename [50];
    printf("Enter your log file name");
    scanf("%s" , filename);

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
