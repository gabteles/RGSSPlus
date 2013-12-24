/* 
 * File:   Audio.cpp
 * Author: Gab
 * 
 * Created on 24 de Janeiro de 2013, 02:06
 */

#include <Plus.hpp>

namespace Plus {
    _MAudio Audio;
    
    /*
     * Setups MIDI
     * 
     * @return void
     */
    void _MAudio::setup_midi(){
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
    void _MAudio::bgm_play(std::string filename, unsigned char volume, unsigned char pitch, long pos){
        // TODO
    }

    /*
     * Stops BGM
     */
    void _MAudio::bgm_stop(){
        // TODO
    }

    /*
     * Fade and stop BGM
     * 
     * @param long Fade duration in milliseconds
     */
    void _MAudio::bgm_fade(long time){
        // TODO
    }

    /*
     * Get BGM progress
     * 
     * @return ulong BGM position in milliseconds
     */
    unsigned long _MAudio::bgm_pos(){
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
    void _MAudio::bgs_play(std::string filename, unsigned char volume, unsigned char pitch, long pos){
        // TODO
    }

    /*
     * Stops BGS
     */
    void _MAudio::bgs_stop(){
        // TODO
    }

    /*
     * Fade and stop BGS
     * 
     * @param long Fade duration in milliseconds
     */
    void _MAudio::bgs_fade(long time){
        // TODO
    }

    /*
     * Get BGS progress
     * 
     * @return ulong BGS position in milliseconds
     */
    unsigned long _MAudio::bgs_pos(){
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
    void _MAudio::me_play(std::string filename, unsigned char volume, unsigned char pitch){
        // TODO
    }

    /*
     * Stops ME
     */
    void _MAudio::me_stop(){
        // TODO
    }

    /*
     * Fade and stop ME
     * 
     * @param long Fade duration in milliseconds
     */
    void _MAudio::me_fade(long time){
        // TODO
    }


    /*
     * Play SE
     * 
     * @param std::string SE Filename
     * @param uchar Volume (0-100)
     * @param pitch Pitch (0-100)
     */
    void _MAudio::se_play(std::string filename, unsigned char volume, unsigned char pitch){
        // TODO
    }

    /*
     * Stops SE
     */
    void _MAudio::se_stop(){
        // TODO
    }
};
