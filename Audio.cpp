/* 
 * File:   Audio.cpp
 * Author: Gab
 * 
 * Created on 24 de Janeiro de 2013, 02:06
 */

#include <Plus.hpp>

namespace Plus {
    namespace Audio {
        /*
         * Setups MIDI
         */
        void setup_midi(){
            // TODO
        }

        /*
         * Play BGM
         * 
         * @param std::string BGM Filename
         * @param uchar Volume (0-100)
         * @param pitch Pitch (0-100)
         * @param long Position in milliseconds
         */
        void bgm_play(std::string filename, unsigned char volume, unsigned char pitch, long pos){
            // TODO
        }

        /*
         * Stops BGM
         */
        void bgm_stop(){
            // TODO
        }

        /*
         * Fade and stop BGM
         * 
         * @param long Fade duration in milliseconds
         */
        void bgm_fade(long time){
            // TODO
        }

        /*
         * Get BGM progress
         * 
         * @return ulong BGM position in milliseconds
         */
        unsigned long bgm_pos(){
            // TODO
            return 0;
        }

        /*
         * Play BGS
         * 
         * @param std::string BGS Filename
         * @param uchar Volume (0-100)
         * @param pitch Pitch (0-100)
         * @param long Position in milliseconds
         */
        void bgs_play(std::string filename, unsigned char volume, unsigned char pitch, long pos){
            // TODO
        }

        /*
         * Stops BGS
         */
        void bgs_stop(){
            // TODO
        }

        /*
         * Fade and stop BGS
         * 
         * @param long Fade duration in milliseconds
         */
        void bgs_fade(long time){
            // TODO
        }

        /*
         * Get BGS progress
         * 
         * @return ulong BGS position in milliseconds
         */
        unsigned long bgs_pos(){
            // TODO
            return 0;
        }

        /*
         * Play ME
         * 
         * @param std::string BGM Filename
         * @param uchar Volume (0-100)
         * @param pitch Pitch (0-100)
         */
        void me_play(std::string filename, unsigned char volume, unsigned char pitch){
            // TODO
        }

        /*
         * Stops ME
         */
        void me_stop(){
            // TODO
        }

        /*
         * Fade and stop ME
         * 
         * @param long Fade duration in milliseconds
         */
        void me_fade(long time){
            // TODO
        }


        /*
         * Play SE
         * 
         * @param std::string SE Filename
         * @param uchar Volume (0-100)
         * @param pitch Pitch (0-100)
         */
        void se_play(std::string filename, unsigned char volume, unsigned char pitch){
            // TODO
        }

        /*
         * Stops SE
         */
        void se_stop(){
            // TODO
        }
    };
};
