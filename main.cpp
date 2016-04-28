
#include "cumino.h"
#include "UntzSound.h"

int main(int argc, char **argv ) {

    UNTZ::System::initialize( 44100, 8192, 0 );
    UNTZ::Sound *snd = UNTZ::Sound::create( "./blobloblll.wav", true );

    print("sound created:%p",snd);

    snd->play();

    while(true) {
        usleep(10*1000);
        prt(".");
    }
    return 0;
}
