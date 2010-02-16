/* 
 * File:   SoundGenerator.h
 * Author: seh
 *
 * Created on February 16, 2010, 8:56 AM
 */

#ifndef _SOUNDGENERATOR_H
#define	_SOUNDGENERATOR_H

class SoundSource {
public:
    SoundSource() {

    }
    
    virtual double nextSample(int sampleRate) {
        return 0;
    }

    virtual ~SoundSource() {

    }
private:

};

#endif	/* _SOUNDGENERATOR_H */

