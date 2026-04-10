//
// Created by ADMIN on 4/10/2026.
//
#include <stdio.h>
#include "io.h"
#include "waveform.h"


void loadData()
{
    char filename [50];
    printf("Enter your log file name");
    scanf("%s" , filename);

    FILE *logFile =fopen(filename , "r");
    char line [256];
    int counter = 0 ;

    for (int i =1 ; i<1000 ; i ++)
    {
        fgets (line , sizeof(line) , filename );
        sscanf(line ,"%f,%f,%f,%f,%f,%f,%f,%f" ,
               &records[i].time,
               &records[i].phaseA,
               &records[i].phaseB,
               &records[i].phaseC,
               &records[i].current,
               &records[i].frequency,
               &records[i].powerFactor,
               &records[i].percentage,

               )
    }
    fclose(logFile);

}

