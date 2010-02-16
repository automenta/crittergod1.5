/* 
 * File:   Audio.cpp
 * Author: seh
 * 
 * Created on February 15, 2010, 7:37 PM
 */

#include "Audio.h"

using namespace std;
#include <list>

#include <stdlib.h>
#include <math.h>

#define NUM_SOUNDS 2

struct sample {
    Uint8 *data;
    Uint32 dpos;
    Uint32 dlen;
} sounds[NUM_SOUNDS];

#define WAVEBUFFER 16384
SDL_AudioSpec spec;
Uint32 sound_len = WAVEBUFFER;
Uint8 *sound_buffer = new Uint8[WAVEBUFFER];
int sound_pos = 0;
int counter;

void mixaudio(void* unused, Uint8 *stream, int len) {

    Audio* audio = (Audio*) unused;

    Uint8 *waveptr;
    double pi = 3.1415;
    //double Hz = 50.0;
    //double L = 512;
    double A = 100;
    const double SR = 22050;
    //double F = 2 * pi * Hz / SR;

    
    memset(sound_buffer, 0, WAVEBUFFER*1);
//    for (unsigned z = 0; z < WAVEBUFFER; z++) {
//        //sound_buffer[z] = (Sint16) A * sin(F * (double) counter);
//        sound_buffer[z] = 0;
//    }

    SoundSource** sources = new SoundSource*[audio->sources->size()];
    unsigned s = 0;
    for (list<SoundSource*>::iterator it = audio->sources->begin(); it != audio->sources->end(); ++it) {
        sources[s++] = *it;
    }

    unsigned j;
    SoundSource *ss;
    #pragma omp parallel for private(j, ss)
    for (j=0; j < s; j++) {
        ss = sources[j];
        for (unsigned z = 0; z < WAVEBUFFER; z++) {
            sound_buffer[z] += (Sint16) (A/10) * ss->nextSample(SR);
        }        
    }

    //Do the sound loop...
    sound_pos = (sound_pos + len) % sound_len;

    waveptr = sound_buffer + sound_pos;
    SDL_MixAudio(stream, waveptr, len, SDL_MIX_MAXVOLUME);

    //sound_pos += len;

    //printf("sound %d %d %d\n", sound_pos, len, sound_len);
}

//void mixaudio2(void *unused, Uint8 *stream, int len) {
//    int i;
//    Uint32 amount;
//
//    for (i = 0; i < NUM_SOUNDS; ++i) {
//
//        int sl = 16384;
//        sounds[i].data = new Uint8[sl];
//        sounds[i].dlen = sl;
//        for (int j = 0; j < sl; j++) {
//            sounds[i].data[j] = rand() % 200;
//        }
//
//        amount = (sounds[i].dlen - sounds[i].dpos);
//        if (amount > len) {
//            amount = len;
//        }
//
//
//        SDL_MixAudio(stream, &sounds[i].data[sounds[i].dpos], amount, SDL_MIX_MAXVOLUME);
//        sounds[i].dpos += amount;
//    }
//
//    printf("sounding\n");
//}

//void PlaySound(char *file)
//{
//    int index;
//    SDL_AudioSpec wave;
//    Uint8 *data;
//    Uint32 dlen;
//    SDL_AudioCVT cvt;
//
//    /* Look for an empty (or finished) sound slot */
//    for ( index=0; index<NUM_SOUNDS; ++index ) {
//        if ( sounds[index].dpos == sounds[index].dlen ) {
//            break;
//        }
//    }
//    if ( index == NUM_SOUNDS )
//        return;
//
//    /* Load the sound file and convert it to 16-bit stereo at 22kHz */
//    if ( SDL_LoadWAV(file, &wave, &data, &dlen) == NULL ) {
//        fprintf(stderr, "Couldn't load %s: %s\n", file, SDL_GetError());
//        return;
//    }
//    SDL_BuildAudioCVT(&cvt, wave.format, wave.channels, wave.freq,
//                            AUDIO_S16,   2,             22050);
//    cvt.buf = malloc(dlen*cvt.len_mult);
//    memcpy(cvt.buf, data, dlen);
//    cvt.len = dlen;
//    SDL_ConvertAudio(&cvt);
//    SDL_FreeWAV(data);
//
//    /* Put the sound data in the slot (it starts playing immediately) */
//    if ( sounds[index].data ) {
//        free(sounds[index].data);
//    }
//    SDL_LockAudio();
//    sounds[index].data = cvt.buf;
//    sounds[index].dlen = cvt.len_cvt;
//    sounds[index].dpos = 0;
//    SDL_UnlockAudio();
//}