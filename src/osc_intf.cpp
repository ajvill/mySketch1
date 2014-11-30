//
//  osc_intf.cpp
//  mySketch1
//
//  Created by Alberto Villarreal on 11/29/14.
//
//

#include "osc_intf.h"


OSC_Intf::OSC_Intf() {
    cout <<"OSC_Intf constructor called\n";

}

OSC_Intf::~OSC_Intf() {
    
}

void OSC_Intf::setOSCtype(short hosttype){
    
    cout <<"setOSCtype called.\n";
    if (hosttype == osc_receiver){
        cout <<"osc receiver type\n";
    } else {
        cout <<"osc sender type\n";
    }
}
 
void OSC_Intf::setup(short hosttype){
    cout << "OSC setup called.\n";
    setOSCtype(hosttype);
}

void OSC_Intf::update(){

}

void OSC_Intf::draw(){
    
}
