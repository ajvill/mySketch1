#pragma once
#include "ofMain.h"

#define MARKA       (1<<0)
#define MARKB       (1<<1)
#define LOOP_ON     (1<<2)
#define FORWARD     (1<<3)
#define REVERSE     (1<<4)

// Class definition
class MoviePlayer {
    public:
    // Room for variables
        ofVideoPlayer movie;
        int width;
        int height;
        int total_frames;
        int frameL_loc;
        int frameR_loc;

    // structs for data mgmt
        struct mPlayer_ctrl {
            // Controls
            unsigned int ctrl;
        };
    
        struct mPlayer_behav {
            // Behavioral State
            unsigned int loopON;
        };
    
        struct mPlayer_direc {
            //Direction
            unsigned int direc;
        };
    
        struct mPlayer {
            struct mPlayer_direc *mdirec;
            struct mPlayer_behav *mbehav;
            struct mPlayer_ctrl  *mctrl;
        };
    
    // data class object
        mPlayer *m;
    
    // Constructor/Destructor
        MoviePlayer();
        ~MoviePlayer();
    
    // Setters and checkers
        void movie_init(string file);
        void setForward();
        void setLoopON();
        void setLoopOFF();
        void setReverse();
        inline void setLeftTic() { frameL_loc = movie.getCurrentFrame(); }
        inline void setRightTic() { frameR_loc = movie.getCurrentFrame(); }
    
    // State tests
        bool isLoopOn();
        bool isForwardDirec();
        bool isReverseDirec();
        bool isMarkASet();
        bool isMarkBSet();
    
    //  Sync'd with App
        void setup(string file);
        void update();
        void draw(float x, float y);
        void draw(float x, float y, float w, float h);
};
