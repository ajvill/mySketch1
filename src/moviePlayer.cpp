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
    mflags->mdirec->paused &= ~PAUSED;
    
    // Save the Width and Height and other Stuff
    width = movie.getWidth();
    height = movie.getHeight();
    movie.setVolume(0.0f);  //Silencio por favor
    total_frames = movie.getTotalNumFrames();
}

void MoviePlayer::setLoopON() {
    mflags->mbehav->loopON_flag |= LOOP_ON;
    movie.stop();
    movie.setFrame(markA_loc);
    movie.play();
}

void MoviePlayer::setLoopOFF() {
    mflags->mbehav->loopON_flag &= ~LOOP_ON;
    movie.stop();
    movie.setFrame(movie.getCurrentFrame());
    movie.play();
}

void MoviePlayer::setForward() {
    mflags->mdirec->direc &= ~REVERSE;
    mflags->mdirec->direc |= FORWARD;
    movie.stop();
    movie.setSpeed(1);
    movie.play();
}

void MoviePlayer::setReverse(){
    mflags->mdirec->direc &= ~FORWARD;
    mflags->mdirec->direc |= REVERSE;
    movie.stop();
    movie.setSpeed(-1);
    movie.play();
}

void MoviePlayer::setMarkA(){
    mflags->mmarks->markA_flag |= MARK_A;
    markA_loc = movie.getCurrentFrame();
}

void MoviePlayer::setMarkB(){
    mflags->mmarks->markB_flag |= MARK_B;
    markB_loc = movie.getCurrentFrame();
}

void MoviePlayer::setPaused() {
    cout << "->     Inside the setPaused() function" << endl;
    if ( !isPaused() ) {
        cout << "Video is not paused so go ahead and pause and then change the state" << endl;
        cout << "paused was set to: " << mflags->mdirec->paused << endl;
        mflags->mdirec->paused |= PAUSED;
        cout <<"paused now = " << mflags->mdirec->paused << endl;
        movie.stop();
    }
    return;
}

void MoviePlayer::setPausedOff() {
    cout << "->     Inside the setPausedOff() function" << endl;
    if ( isPaused() ) {
        cout << "paused set to true, paused = " << mflags->mdirec->paused <<endl;
        cout << "paused set to true" << endl;
        mflags->mdirec->paused &= ~PAUSED;
        if (mflags->mdirec->direc == FORWARD) {
            cout << "direction of video is forward" << endl;
            setForward();
        } else {
            cout << "direction of video is reverse" << endl;
            setReverse();
        }
        return;
    }
    cout << "paused set to false, paused = " << mflags->mdirec->paused << ", bye!" <<endl;
    return;
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
    if (mflags->mdirec->direc == FORWARD){
        return true;
    } else return false;
}

bool MoviePlayer::isReverseDirec(){
    if (mflags->mdirec->direc == REVERSE) {
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

bool MoviePlayer::isPaused() {
    cout << "->     Inside isPaused() paused = " << mflags->mdirec->paused << endl;
    if (mflags->mdirec->direc == PAUSED) {
        cout << "Returning true" << endl;
        return true;
    } else {
     cout<<"Return false" << endl;
     return false;
    }
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
            // The marks are equal to each other so just play 
            if ( (markA_loc >= markB_loc) &&
                 (mflags->mmarks->markB_flag != MARK_B) ) {
                movie.draw(x, y);
            }
            else if ( movie.getCurrentFrame() >= markB_loc ) {
                movie.setFrame(markA_loc);
                movie.draw(x, y);
            }
            // Nothing special just play
            else {
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
            // The marks are equal to each other just play, in reverse
            if (markA_loc == markB_loc) {
                movie.draw(x, y);
            }
            else if ( movie.getCurrentFrame() <= markA_loc ){
                movie.setFrame(markB_loc);
                movie.draw(x, y);
            }
            // Just play it
            else {
                movie.draw(x, y);
            }
        }
        // Loop is OFF just play
        else {
            movie.draw(x, y);
        }
    }
}

void MoviePlayer::draw(float x, float y, float w, float h) {
    
    movie.draw(x, y, w, h);
}