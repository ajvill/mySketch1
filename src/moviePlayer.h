#pragma once
#include "ofMain.h"

// Class definition
class MoviePlayer {
    private:
        #define MARK_A      (1<<0)
        #define MARK_B      (1<<1)
        #define LOOP_ON     (1<<2)
        #define FORWARD     (1<<3)
        #define REVERSE     (1<<4)

    protected:
        /*******************************************
         Stucts and other stuff
         *******************************************/
        struct mPlayer_marks_flags {
            // Marks
            unsigned short markA_flag;
            unsigned short markB_flag;
        };
        struct mPlayer_behav_flags {
            // Behavioral State
            unsigned short loopON_flag;
        };
        struct mPlayer_direc_flags {
            //Direction
            unsigned short direc_flag;
        };
        struct mPlayer {
            struct mPlayer_marks_flags *mmarks;
            struct mPlayer_behav_flags *mbehav;
            struct mPlayer_direc_flags *mdirec;
        };
        mPlayer *mflags;
        ofVideoPlayer movie;
    
        /******************************************
         Protected Functions
        ******************************************/
        void movie_init(string file);
    
    public:
        /*******************************************
             Direct Access - Variables
        *******************************************/
        unsigned int width;
        unsigned int height;
        unsigned int total_frames;
        unsigned int markA_loc;
        unsigned int markB_loc;
        unsigned int current_frame;
    
        /******************************************
               Public Functions
        ******************************************/
        // Constructor/Destructor
        MoviePlayer();
        ~MoviePlayer();
    
        // Setters and checkers
        void setForward();
        void setLoopON();
        void setLoopOFF();
        void setReverse();
        void setMarkA();
        void setMarkB();
    
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
