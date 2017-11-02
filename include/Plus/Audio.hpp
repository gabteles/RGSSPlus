#ifndef PLUS_AUDIO_HPP
#define	PLUS_AUDIO_HPP

namespace Plus {
    class _MAudio {
        public:
            void setupMidi();

            void bgmPlay(std::string filename, unsigned char volume, unsigned char pitch, long pos);
            void bgmStop();
            void bgmFade(long time);
            unsigned long bgmPos();

            void bgsPlay(std::string filename, unsigned char volume, unsigned char pitch, long pos);
            void bgsStop();
            void bgsFade(long time);
            unsigned long bgsPos();

            void mePlay(std::string filename, unsigned char volume, unsigned char pitch);
            void meStop();
            void meFade(long time);

            void sePlay(std::string filename, unsigned char volume, unsigned char pitch);
            void seStop();
    };
};

#endif	/* PLUS_AUDIO_HPP */

