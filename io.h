//
// Created by ADMIN on 4/10/2026.
//

#ifndef ACWAVEFORM_IO_H
#define ACWAVEFORM_IO_H


#include "waveform.h"

int  loadData(struct WaveformSample records[]);
void printAllrow(struct WaveformSample *records , int size);
#endif //ACWAVEFORM_IO_H
