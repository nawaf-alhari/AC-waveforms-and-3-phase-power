cmake_minimum_required(VERSION 3.21)
project (AcWaveform C)

set(CMAKE_C_STANDARD 99)

add_executable(AcWaveform main.c waveform.c waveform.h io.c io.h)
