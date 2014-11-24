#pragma once
#include "ofMain.h"

class MoviePlayer {
    public:
    // Room for variables
        ofVideoPlayer movie;
        int width;
        int height;
        int total_frames;
        int frameL_loc;
        int frameR_loc;
        bool loopState;
        bool reversePlay;
        bool forwardPlay;
    
    // Setters
        MoviePlayer();
        void setMovie(string file);
        void setup(string file);
        void setLeftTic();
        void setRightTic();
        void loopMark();
        void reverse();
        void forward();
    
    //  Sync'd with App
        void update();
        void draw(float x, float y);
        void draw(float x, float y, float w, float h);    
};
