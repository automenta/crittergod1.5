/* 
 * File:   Audio.h
 * Author: seh
 *
 * Created on February 15, 2010, 7:37 PM
 */

#ifndef _AUDIO_H
#define	_AUDIO_H

using namespace std;

#include <list>

#include <stdio.h>
#include <stdlib.h>

#include "SDL/SDL.h"
#include "SDL/SDL_audio.h"

#include "SoundSource.h"

extern void mixaudio(void *unused, Uint8 *stream, int len);


class Audio {
public:

    list<SoundSource*> *sources;
    
    Audio() {
        sources = new list<SoundSource*>();
        
        if (SDL_Init( SDL_INIT_AUDIO) < 0)
            exit(-1);
        atexit(SDL_Quit);

        SDL_AudioSpec fmt;

        fmt.freq = 22050;
        fmt.format = AUDIO_S16SYS;
        fmt.channels = 1;
        fmt.samples = 8192;
        fmt.callback = mixaudio;
        fmt.userdata = this;

        /* Open the audio device and start playing sound! */
        if (SDL_OpenAudio(&fmt, NULL) < 0) {
            fprintf(stderr, "Unable to open audio: %s\n", SDL_GetError());
            exit(1);
        }

        setPlaying(true);
    }

    void setPlaying(bool b) {
        if (b)
            SDL_PauseAudio(0);
        else
            SDL_PauseAudio(1);
    }

    ~Audio() {
        SDL_CloseAudio();
    }
};

//class Audio {
//public:
//
//    ALfloat listenerPos[3];
//    ALfloat listenerVel[3];
//    ALfloat listenerOri[6];
//    ALfloat sourceOPos[3];
//    ALfloat sourceOVel[3];
//
//    // Buffers hold sound data.
//    ALuint Buffer;
//
//    // Sources are points emitting sound.
//    ALuint Source;
//
//    ALuint buffer[AUDIO_BUFFERS];
//    ALuint source[AUDIO_SOURCES];
//    ALuint environment[AUDIO_ENVIRONMENTS];
//
//    ALsizei size, freq;
//    ALenum format;
//    ALvoid *data;
//
//    Audio(int argc, char** argv) {
//
//        listenerPos[0] = 0;
//        listenerPos[1] = 0;
//        listenerPos[2] = 4;
//
//        listenerVel[0] = listenerVel[1] = listenerVel[2] = 0;
//
//        listenerOri[0] = 0;
//        listenerOri[1] = 0;
//        listenerOri[2] = 1.0;
//        listenerOri[3] = 0;
//        listenerOri[4] = 1;
//        listenerOri[5] = 0;
//
//        sourceOPos[0] = -2;
//        sourceOPos[1] = sourceOPos[2] = 0;
//
//        sourceOVel[0] = sourceOVel[1] = sourceOVel[2] = 0;
//
//        alListenerfv(AL_POSITION, listenerPos);
//        alListenerfv(AL_VELOCITY, listenerVel);
//        alListenerfv(AL_ORIENTATION, listenerOri);
//
//        alGetError(); // clear any error messages
//
//        // Generate buffers, or else no sound will happen!
//        alGenBuffers(AUDIO_BUFFERS, buffer);
//
//        if (alGetError() != AL_NO_ERROR) {
//            printf("- Error creating buffers !!\n");
//            exit(1);
//        } else {
//            printf("init() - No errors yet.");
//        }
//
//        alutInit(&argc, argv);
//        alGetError();
//
//        // Load the wav data.
//        if (loadData() == AL_FALSE) {
//            printf("unable to load audio data");
//            exit(1);
//        }
//
//        setListenerValues();
//
//        // Setup an exit procedure.
//        printf("Audio ready");
//
//        alSourcePlay(Source);
//    }
//
//    int loadData() {
//        alGenBuffers(1, &Buffer);
//
//        alGenSources(1, &Source); // Bind buffer with a source.
//
//        if (alGetError() != AL_NO_ERROR)
//            return AL_FALSE;
//
//        alSourcei(Source, AL_BUFFER, Buffer);
//        alSourcef(Source, AL_PITCH, 1.0f);
//        alSourcef(Source, AL_GAIN, 1.0f);
//        alSourcefv(Source, AL_POSITION, sourceOPos);
//        alSourcefv(Source, AL_VELOCITY, sourceOVel);
//        alSourcei(Source, AL_LOOPING, true);
//
//        return (alGetError() == AL_NO_ERROR) ? AL_TRUE : AL_FALSE;
//    }
//
//    void setListenerValues() {
//        alListenerfv(AL_POSITION, listenerPos);
//        alListenerfv(AL_VELOCITY, listenerVel);
//        alListenerfv(AL_ORIENTATION, listenerOri);
//    }
//
//    virtual ~Audio() {
//        alDeleteBuffers(1, &Buffer);
//        alDeleteSources(1, &Source);
//        alutExit();
//    }
//private:
//
//};

#endif	/* _AUDIO_H */

