/* -*- c++ -*- */

#define FFT_PEAKFINDER_API

%include "gnuradio.i"           // the common stuff

//load generated python docstrings
%include "fft_peakfinder_swig_doc.i"

%{
#include "fft_peakfinder/peakfinder.h"
%}

%include "fft_peakfinder/peakfinder.h"
GR_SWIG_BLOCK_MAGIC2(fft_peakfinder, peakfinder);
