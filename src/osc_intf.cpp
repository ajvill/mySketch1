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

void OSC_Intf::setOSCtype(short type){
    
    //osc_type t;
    cout <<"setOSCtype called.\n";
}
 
void OSC_Intf::setup(){
    cout << "OSC setup called.\n";
}

void OSC_Intf::update(){
    cout << "OSC update called. \n";
}

void OSC_Intf::draw(){
    cout << "OSC draw called.\n";
}
