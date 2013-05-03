/* 
 * File:   Audio.hpp
 * Author: Gab
 *
 * Created on 24 de Janeiro de 2013, 02:06
 */

#ifndef AUDIO_HPP
#define	AUDIO_HPP

namespace Plus {
        namespace Audio {
                void setup_midi();
        
                void bgm_play(string filename, unsigned char volume, unsigned char pitch, long pos);
                void bgm_stop();
                void bgm_fade(long time);
                unsigned long bgm_pos();
                
                void bgs_play(string filename, unsigned char volume, unsigned char pitch, long pos);
                void bgs_stop();
                void bgs_fade(long time);
                unsigned long bgs_pos();
        
                void me_play(string filename, unsigned char volume, unsigned char pitch);
                void me_stop();
                void me_fade(long time);
        
                void se_play(string filename, unsigned char volume, unsigned char pitch);
                void se_stop();
        };
};

#endif	/* AUDIO_HPP */

