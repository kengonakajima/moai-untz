
#include "cumino.h"
#include "UntzSound.h"

UInt32 stream_callback(float* buffers, UInt32 numChannels, UInt32 length, void* userdata) {
    print("cb %f len:%d",now(), length );
    static int counter = 0;
    for(int i=0;i<length;i++) {
        buffers[i] = cos( (float)(counter) / 20.0f );
        counter++;
    }
    return length;
}
int main(int argc, char **argv ) {

    UNTZ::System::initialize( 44100, 8192, 0 );

    // sound from file
    UNTZ::Sound *snd = UNTZ::Sound::create( "./blobloblll.wav", true );
    print("sound created:%p",snd);
    snd->play();

    // sound from callback
    UNTZ::Sound *cbsnd = UNTZ::Sound::create(44100,1,stream_callback,NULL);
    cbsnd->play();
    
    while(true) {
        usleep(10*1000);
        prt(".");
    }
    return 0;
}
