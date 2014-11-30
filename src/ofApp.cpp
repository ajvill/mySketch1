#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    // Log set level
    ofSetLogLevel(OF_LOG_NOTICE);
    
    // OSC interface setup
    hosttype = osc_receiver;
    osc_if.setup(hosttype);
    
    // osc_receiver
    if (hosttype == osc_receiver) {
        // Movies setup
        movies.setup("movies/NYC.mp4");
        //movies.setup("movies/redVid.mp4");
        //movies.setup("movies/vid1.mp4");
        //movies.setup("movies/vid2.mp4");
        //movies.setup("movies/vid3.mp4");
        //movies.setup("movies/vid4.mp4");
        //movies.setup("movies/leaves.mp4");
        //movies.setup("movies/fingers.mov");
    }
    // osc_sender
    else {
        
    }
    
}

//--------------------------------------------------------------
void ofApp::update(){
    
    osc_if.update();
    // osc_receiver
    if (hosttype == osc_receiver) {
        
        movies.update();
    }
    // osc_sender
    else {
        
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    
    osc_if.draw();
    // osc_receiver
    if (hosttype == osc_receiver) {
        
        movies.draw( (ofGetWidth()/2 - movies.width/2), (ofGetHeight()/2 - movies.height/2));
        
        // Show the movie player stats
        string info = "FPS:  "+ofToString(ofGetFrameRate(),1)+" \n";
        info += "Frames in Movie:  "+ofToString(movies.total_frames, 1)+" \n";
        info += "App Timer:  "+ofToString(ofGetElapsedTimeMillis()/1000, 1)+" s, "+ofToString(ofGetElapsedTimeMillis())+" ms\n";
        info += "Frame:  "+ofToString(movies.current_frame, 1)+" \n";
        info += "Left Mark:  "+ofToString(movies.markA_loc, 1)+" \n";
        info += "Right Mark:  "+ofToString(movies.markB_loc, 1)+" \n";
        
        if ( movies.isLoopOn() == false) {
            info += "Loop State:  "+ofToString("0", 1)+" \n";
        }
        else {
             info += "Loop State:  "+ofToString("1", 1)+" \n";
        }
        
        ofSetColor(255);
        ofDrawBitmapString(info, 20, 20);
    }
    // osc_sender
    else {
        
    }
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
   
    // osc_receiver
    if (hosttype == osc_receiver) {
        
        // Sets a left frame mark
        if( key == 'a' ){
            //ofLogNotice() << "!!!!!! Key Pressed: MarkA set !!!!!!";
            movies.setMarkA();
        }
        
        // Sets a right frame mark
        if( key == 'd' ){
            movies.setMarkB();
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
    // osc_sender
    else {
        
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
