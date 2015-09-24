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

void OSC_Intf::setOSCtype(int hosttype, int oscport){
    
    cout <<"setOSCtype called.\n";
    if (hosttype == osc_receiver){
        receiver.setup(oscport);
    } else {
        cout <<"osc sender type\n";
    }
}
 
void OSC_Intf::setup(int hosttype, int oscport){
    cout << "OSC setup called.\n";
    setOSCtype(hosttype, oscport);
}

void OSC_Intf::update(){

}

void OSC_Intf::draw(){
    
}
