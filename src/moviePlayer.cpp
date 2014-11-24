//#pragma once
#include "moviePlayer.h"

//Constructor
MoviePlayer::MoviePlayer() {
    
    loopState = false;
    reversePlay = false;
    forwardPlay = false;
}

//  Functions setup
void MoviePlayer::setup(string file) {
    
    // Loading Movie
    setMovie(file);
    
    // Play the movie yeah
    movie.play();
}

void MoviePlayer::setMovie(string file) {
    
    movie.loadMovie(file);
    
    // Save the Width and Height and other Stuff
    width = movie.getWidth();
    height = movie.getHeight();
    movie.setVolume(0.0f);  //Silencio por favor
    total_frames = movie.getTotalNumFrames();
}

void MoviePlayer::setLeftTic() {
    
    frameL_loc = movie.getCurrentFrame();
    
}

void MoviePlayer::setRightTic() {
    
    frameR_loc = movie.getCurrentFrame();
}

void MoviePlayer::loopMark() {
    
    movie.stop();
    movie.setFrame(frameL_loc);
    movie.play();
}

void MoviePlayer::reverse(){
    movie.stop();
    movie.setSpeed(-1);
    movie.play();
}

void MoviePlayer::forward(){
    movie.stop();
    movie.setSpeed(1);
    movie.play();
}

void MoviePlayer::update() {
    
    movie.update();
}

void MoviePlayer::draw(float x, float y) {
    
    if ( loopState == false){
        movie.draw(x, y);
    } else {
        if ( int frame_curr = movie.getCurrentFrame() < frameR_loc ){
            movie.draw(x, y);
        } else if (int frame_curr = movie.getCurrentFrame() >= frameR_loc){
            movie.setFrame(frameL_loc);
        }
    }
}

void MoviePlayer::draw(float x, float y, float w, float h) {
    
    movie.draw(x, y, w, h);
}

