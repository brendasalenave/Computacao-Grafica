#ifndef __AUDIO_H__
#define __AUDIO_H__

#include "gl_canvas2d.h"



class Audio{
    char        id[4];          // should always contain "RIFF"
    int     totallength;    // total file length minus 8
    char        wavefmt[8];     // should be "WAVEfmt "
    int     format;         // 16 for PCM format
    short     pcm;            // 1 for PCM format
    short     channels;       // channels
    int     frequency;      // sampling frequency
    int     bytes_per_second;
    short     bytes_by_capture;
    short     bits_per_sample;
    char        data[4];        // should always contain "data"
    int     bytes_in_data;

public:
  Audio(){

  }

  void abreArquivo(){
    char *filename= "ringtone.wav";
    FILE *wav = fopen(filename,"rb");
    if ( wav == NULL ) {
        fprintf(stderr,"Can't open input file %s", filename);
        exit(1);
    }
  }


  }


};

#endif

