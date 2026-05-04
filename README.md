Here is my readme file where project instruction will be explained
 
# Power quality waveform analyser
-this is a C program I made for my coursework it read
the csv file and analyses the AC waveform data

## What it does 
-calculate the RMS voltage for the three phases
-calculate the peak to peak voltage for the three phases
-calculate the DC offset for the three phases
-check if voltage is within 230 +or- 10% tolerance 
-detects clipping
-export all result  to result.txt

## How to run
-first open the in Clion
-second make sure power_quality_log.csv is in the project folder
-third run the project

## Files
- main.c : run the program 
- io.c/io.h: read the csv file and write the result 
- waveform.c/waveform.h : dose all the math

## Repository 
- https://github.com/nawaf-alhari/AC-waveforms-and-3-phase-power.git
