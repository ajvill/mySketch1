//#pragma once
#include "moviePlayer.h"

//Constructor / Destructors
MoviePlayer::MoviePlayer() {
  
    // create space for mPlayer helpers
    mPlayer_direc *direc = new mPlayer_direc;
    mPlayer_ctrl *ctrl = new mPlayer_ctrl;
    mPlayer_behav *behave = new mPlayer_behav;
    m = new mPlayer;
    
    m->mdirec = direc;
    m->mctrl = ctrl;
    m->mbehav = behave;
    
    m->mdirec->direc |= (0<<0);
    m->mctrl->ctrl |= (0<<0);
    m->mbehav-> loopON |= (0<<0);
}

MoviePlayer::~MoviePlayer(){
    delete m->mdirec;
    delete m->mctrl;
    delete m->mbehav;
    delete m;
}

//  Functions setup
void MoviePlayer::movie_init(string file) {
    
    // Initial config info
    movie.loadMovie(file);
    setForward();
    
    // Save the Width and Height and other Stuff
    width = movie.getWidth();
    height = movie.getHeight();
    movie.setVolume(0.0f);  //Silencio por favor
    total_frames = movie.getTotalNumFrames();
}

void MoviePlayer::setLoopON() {
    m->mbehav->loopON |= LOOP_ON;
    movie.stop();
    movie.setFrame(frameL_loc);
    movie.play();
}

void MoviePlayer::setLoopOFF() {
    m->mbehav->loopON &= ~LOOP_ON;
}

void MoviePlayer::setForward() {
    m->mdirec->direc |= FORWARD;
    movie.stop();
    movie.setSpeed(1);
    movie.play();
}

void MoviePlayer::setReverse(){
    m->mdirec->direc |= REVERSE;
    movie.stop();
    movie.setSpeed(-1);
    movie.play();
}

bool MoviePlayer::isLoopOn(){
    if (m->mbehav->loopON == LOOP_ON){
        return true;
    } else return false;
}

bool MoviePlayer::isForwardDirec(){
    if (m->mdirec->direc == FORWARD){
        return true;
    } else return false;
}

bool MoviePlayer::isReverseDirec(){
    if (m->mdirec->direc == REVERSE) {
        return true;
    } else return false;
}

bool MoviePlayer::isMarkASet(){
    // DO THIS
}

bool MoviePlayer::isMarkBSet(){
    // DO THIS
}

// Functions sync'd with App
void MoviePlayer::setup(string file){
    
    // Loading Movie
    movie_init(file);
    
    // Play the movie yeah
    movie.play();
}

void MoviePlayer::update() {
    //cout <<"Update called!\n";
    movie.update();
}

void MoviePlayer::draw(float x, float y) {
    
    if ( m->mbehav->loopON == LOOP_ON){
        if ( int frame_curr = movie.getCurrentFrame() < frameR_loc ){
            movie.draw(x, y);
        } else if (int frame_curr = movie.getCurrentFrame() >= frameR_loc){
            movie.setFrame(frameL_loc);
            movie.draw(x, y);
        }
    } else {
        movie.draw(x,y);
    }
}

void MoviePlayer::draw(float x, float y, float w, float h) {
    
    movie.draw(x, y, w, h);
}
