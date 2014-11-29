//#pragma once
#include "moviePlayer.h"

//Constructor / Destructors
MoviePlayer::MoviePlayer() {
  
    // create space for mPlayer helpers
    mPlayer_direc_flags *direc = new mPlayer_direc_flags;
    mPlayer_marks_flags *marks = new mPlayer_marks_flags;
    //mPlayer_marks_flags *marks = (mPlayer_marks_flags *) malloc(sizeof(struct mPlayer_marks_flags));
    mPlayer_behav_flags *behave = new mPlayer_behav_flags;
    mflags = new mPlayer;
    
    mflags->mdirec = direc;
    mflags->mmarks = marks;
    mflags->mbehav = behave;
    current_frame = 0;
}

MoviePlayer::~MoviePlayer(){
    delete mflags->mdirec;
    delete mflags->mmarks;
    delete mflags->mbehav;
    delete mflags;
}

/***********************************
 Functions that setup stuff
***********************************/
void MoviePlayer::movie_init(string file) {
    
    // Initial config info
    movie.loadMovie(file);
    setLoopOFF();
    setForward();
    mflags->mmarks->markA_flag &= ~MARK_A;
    mflags->mmarks->markB_flag &= ~MARK_B;
    
    // Save the Width and Height and other Stuff
    width = movie.getWidth();
    height = movie.getHeight();
    movie.setVolume(0.0f);  //Silencio por favor
    total_frames = movie.getTotalNumFrames();
}

void MoviePlayer::setLoopON() {
    mflags->mbehav->loopON_flag |= LOOP_ON;
    movie.stop();
    movie.setFrame(frameA_loc);
    movie.play();
}

void MoviePlayer::setLoopOFF() {
    mflags->mbehav->loopON_flag &= ~LOOP_ON;
    movie.stop();
    movie.setFrame(movie.getCurrentFrame());
    movie.play();
}

void MoviePlayer::setForward() {
    mflags->mdirec->direc_flag |= FORWARD;
    movie.stop();
    movie.setSpeed(1);
    movie.play();
}

void MoviePlayer::setReverse(){
    mflags->mdirec->direc_flag |= REVERSE;
    movie.stop();
    movie.setSpeed(-1);
    movie.play();
}

void MoviePlayer::setMarkA(){
    mflags->mmarks->markA_flag |= MARK_A;
    frameA_loc = movie.getCurrentFrame();
}

void MoviePlayer::setMarkB(){
    mflags->mmarks->markB_flag |= MARK_B;
    frameB_loc = movie.getCurrentFrame();
}

/************************************************
 Functions that check the state of things
*************************************************/

bool MoviePlayer::isLoopOn(){
    if (mflags->mbehav->loopON_flag == LOOP_ON){
        return true;
    } else return false;
}

bool MoviePlayer::isForwardDirec(){
    if (mflags->mdirec->direc_flag == FORWARD){
        return true;
    } else return false;
}

bool MoviePlayer::isReverseDirec(){
    if (mflags->mdirec->direc_flag == REVERSE) {
        return true;
    } else return false;
}

bool MoviePlayer::isMarkASet(){
    if (mflags->mmarks->markA_flag == MARK_A) {
        return true;
    } else return false;
}

bool MoviePlayer::isMarkBSet(){
    if (mflags->mmarks->markB_flag == MARK_B) {
        return true;
    } else return false;
}

/************************************************
    These functions are sync'd up with the App
*************************************************/
void MoviePlayer::setup(string file){
    
    // Loading Movie
    movie_init(file);
    
    // Play the movie yeah
    movie.play();
}

void MoviePlayer::update() {

    current_frame = movie.getCurrentFrame();
    movie.update();
}
    
void MoviePlayer::draw(float x, float y) {
    // FORWARD DIRECTION
    if ( isForwardDirec() ) {
        // Loop is ON
        if ( isLoopOn() ){
            if ( movie.getCurrentFrame() >= frameB_loc ) {
                movie.setFrame(frameA_loc);
                movie.draw(x, y);
            } else {
                movie.draw(x, y);
            }
        }
        // Loop IS OFF
        else {
            movie.draw(x, y);
        }
    }
    // REVERSE DIRECTION
    else {
        // Loop is ON
        if ( isLoopOn() ){
            if ( movie.getCurrentFrame() <= frameA_loc ){
                movie.setFrame(frameB_loc);
                movie.draw(x, y);
            } else {
                movie.draw(x, y);
            }
        }
        // Loop is OFF
        else {
            movie.draw(x, y);
        }
    }
}

void MoviePlayer::draw(float x, float y, float w, float h) {
    
    movie.draw(x, y, w, h);
}