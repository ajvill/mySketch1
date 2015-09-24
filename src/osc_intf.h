//
//  osc_intf.h
//  mySketch1
//
//  Created by Alberto Villarreal on 11/29/14.
//
//
#pragma once
#include "ofMain.h"
#include "ofxOsc.h"

enum osc_type {
    osc_receiver,
    osc_sender
};

class OSC_Intf {
    protected:
        ofxOscReceiver  receiver;
        ofxOscSender    sender;
        void setOSCtype(int, int);
    
    public:
        OSC_Intf();
        ~OSC_Intf();
        void setup(int, int);
        void update();
        void draw();
};