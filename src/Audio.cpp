#include <Plus.hpp>

namespace Plus {
    _MAudio Audio;

    /*
     * Setups MIDI
     *
     * @return void
     */
    void _MAudio::setupMidi(){
        // TODO
    }

    /*
     * Play BGM
     *
     * @param std::string BGM Filename
     * @param unsigned char Volume (0-100)
     * @param unsigned char Pitch (0-100)
     * @param long Position in milliseconds
     */
    void _MAudio::bgmPlay(std::string filename, unsigned char volume, unsigned char pitch, long pos){
        // TODO
    }

    /*
     * Stops BGM
     */
    void _MAudio::bgmStop(){
        // TODO
    }

    /*
     * Fade and stop BGM
     *
     * @param long Fade duration in milliseconds
     */
    void _MAudio::bgmFade(long time){
        // TODO
    }

    /*
     * Get BGM progress
     *
     * @return unsigned long BGM position in milliseconds
     */
    unsigned long _MAudio::bgmPos(){
        // TODO
        return 0;
    }

    /*
     * Play BGS
     *
     * @param std::string BGS Filename
     * @param unsigned char Volume (0-100)
     * @param unsigned char Pitch (0-100)
     * @param long Position in milliseconds
     */
    void _MAudio::bgsPlay(std::string filename, unsigned char volume, unsigned char pitch, long pos){
        // TODO
    }

    /*
     * Stops BGS
     */
    void _MAudio::bgsStop(){
        // TODO
    }

    /*
     * Fade and stop BGS
     *
     * @param long Fade duration in milliseconds
     */
    void _MAudio::bgsFade(long time){
        // TODO
    }

    /*
     * Get BGS progress
     *
     * @return ulong BGS position in milliseconds
     */
    unsigned long _MAudio::bgsPos(){
        // TODO
        return 0;
    }

    /*
     * Play ME
     *
     * @param std::string BGM Filename
     * @param unsigned char Volume (0-100)
     * @param unsigned char Pitch (0-100)
     */
    void _MAudio::mePlay(std::string filename, unsigned char volume, unsigned char pitch){
        // TODO
    }

    /*
     * Stops ME
     */
    void _MAudio::meStop(){
        // TODO
    }

    /*
     * Fade and stop ME
     *
     * @param long Fade duration in milliseconds
     */
    void _MAudio::meFade(long time){
        // TODO
    }


    /*
     * Play SE
     *
     * @param std::string SE Filename
     * @param unsigned char Volume (0-100)
     * @param unsigned char Pitch (0-100)
     */
    void _MAudio::sePlay(std::string filename, unsigned char volume, unsigned char pitch){
        // TODO
    }

    /*
     * Stops SE
     */
    void _MAudio::seStop(){
        // TODO
    }
};
