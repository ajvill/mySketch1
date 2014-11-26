#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    movies.movie_init("movies/video-2011-05-29-15-49-03.mp4");
 
}

//--------------------------------------------------------------
void ofApp::update(){
    movies.update();
}

//--------------------------------------------------------------
void ofApp::draw(){
    
    //bool mPlayer_loopState = movies.m->mbehav->loopON;
    
    movies.draw( (ofGetWidth()/2 - movies.width/2), (ofGetHeight()/2 - movies.height/2));
    
    // Show the movie player stats
    string info = "FPS:  "+ofToString(ofGetFrameRate(),1)+" \n";
    info += "Frames in Movie:  "+ofToString(movies.total_frames, 1)+" \n";
    info += "App Timer:  "+ofToString(ofGetElapsedTimeMillis()/1000, 1)+" s, "+ofToString(ofGetElapsedTimeMillis())+" ms\n";
    info += "Frame:  "+ofToString(movies.movie.getCurrentFrame(), 1)+" \n";
    info += "Left Mark:  "+ofToString(movies.frameL_loc, 1)+" \n";
    info += "Right Mark:  "+ofToString(movies.frameR_loc, 1)+" \n";
    
    if ( movies.isLoopOn() == false) {
        info += "Loop State:  "+ofToString("0", 1)+" \n";
    }
    else {
         info += "Loop State:  "+ofToString("1", 1)+" \n";
    }
    
    ofSetColor(255);
    ofDrawBitmapString(info, 20, 20);
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    
    // Sets a left frame mark
    if( key == 'a' ){
        movies.setLeftTic();
    }
    
    // Sets a right frame mark
    if( key == 'd' ){
        movies.setRightTic();
    }
    
    // Turns On looping
    if( key == 'q' ){
        movies.setLoopON();
    }
    
    // Turns On/Off Looping Between Marks
    if ( key == 'z'){
        movies.setLoopOFF();
    }
    

    // FIX THESE!!!!!!!
    // Play Video in Reverse
    if ( key == 'r'){
        movies.setReverse();
    }
    
    // Play Video in Forward/Normal Speed
    if ( key == 'f'){
        movies.setForward();
    }
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
