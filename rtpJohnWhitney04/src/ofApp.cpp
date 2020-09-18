#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    midiValue = 12.7276;
    go = false;
    time = 0.0;
    
//    float i = 0;
//    while (i < TWO_PI) {
//        r = 200;
//        float cx = ofGetWidth()/2 + cos(i) * r;
//        float cy = ofGetHeight()/2 + sin(i) * r;
//        line.addVertex(ofVec3f(cx,cy,0));
//        i += 0.005*HALF_PI*0.5;
//    }
//    line.close();

    line = line.getResampledByCount(50);
    vertices = line.getVertices();
    
    p.x = ofGetWidth()/2;
    p.y = ofGetHeight()/2;
    
    //    ofSetLogLevel(OF_LOG_VERBOSE);
    
    // print input ports to console
    midiIn.listInPorts();
    
    midiIn.openPort(1);
    //midiIn.openPort("IAC Pure Data In");    // by name
    //midiIn.openVirtualPort("ofxMidiIn Input"); // open a virtual port
    
    // don't ignore sysex, timing, & active sense messages,
    // these are ignored by default
    midiIn.ignoreTypes(false, false, false);
    
    // add ofApp as a listener
    midiIn.addListener(this);
    
    // print received messages to the console
    midiIn.setVerbose(false);
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
    
    // line.draw();
    
    // Sine Deform
    /*
    for(int k = 0; k < vertices.size(); k++) {
        
        x = wrapAround(vertices[k].x, ofGetWidth());
        vertices[k].x = x + sin(ofGetElapsedTimef() + k * 0.01);
        ofDrawCircle(vertices[k].x, vertices[k].y, 5);
    }
    */

    // Skew Wrap
//    for(int k = 0; k < vertices.size(); k++) {
////        vertices[k].x = x + vertices[k].y*0.01;
//        vertices[k].x = wrapAround(vertices[k].x, ofGetWidth());
//        vertices[k].x = vertices[k].x + 1.0+sin(ofGetElapsedTimef()*0.05)*ofMap(vertices[k].y, 200, 600, 0, 10);
//        ofDrawCircle(vertices[k].x, vertices[k].y, 4);
//    }
    
    for(unsigned int i = 0; i < midiMessages.size(); ++i) {

        ofxMidiMessage &message = midiMessages[i];
        
        stringstream text;
        string msg = ofxMidiMessage::getStatusString(message.status);
        
//        MidiStatus status;
//        int channel;        //< 1 - 16
//
//        /// message-specific values,
//        /// converted from raw bytes
//        int pitch;          //< 0 - 127
//        int velocity;       //< 0 - 127
//        int control;        //< 0 - 127
//        int value;          //< depends on message status type
        
        /*
         Arturia MiniLab mkII Knob > Control Value Map
         
         Knob #1: 112
         Knob #2: 74
         Knob #3: 71
         Knob #4: 76
         Knob #5: 77
         Knob #6: 93
         Knob #7: 73
         Knob #8: 75
         Knob #9: 114
         Knob #10: 18
         Knob #11: 19
         Knob #12: 16
         Knob #13: 17
         Knob #14: 91
         Knob #15: 79
         Knob #16: 72
         */
        
        if(message.status < MIDI_SYSEX) {
            text << "chan: " << message.channel;
            if(message.status == MIDI_CONTROL_CHANGE) {
                switch(message.control) {
                    case 74:
                        midiValue = ofMap(message.value, 0, 127, 12.4, 12.8);
                        break;
                    case 71:
//                        circleCount = ofMap(message.value, 0, 127, 0, 200);
                        break;
                    case 76:
//                        phaseChange = ofMap(message.value, 0, 127, 0, 2);
                        break;
                    case 77:
//                        noteShift = message.value;
                        break;
                    default:
                        ofLog() << "Unimplemented MIDI Control Change";
                }
                ofLog() << message.control << " // " << message.value;
                
            }
        }
    }
    
    ofDrawBitmapString("midiValue: ", 20, 20);
    ofDrawBitmapString(midiValue, 160, 20);
    
    ofDrawBitmapString("p.x: ", 20, 60);
    ofDrawBitmapString(p.x, 160, 60);
    
    ofDrawLine(400, 0, 400, ofGetHeight());
    
    
//    ofLog() << sin(ofGetElapsedTimef());
//    if(sin(ofGetElapsedTimef()) == 0) {
//        go = true;
//    }
    
//    if(go == true) {
    time += 0.1;
    if(1+sin(time) > 0 && 1+sin(time) < 0.05) {
        line.addVertex(ofVec3f(p.x, p.y, 0));
        vertices = line.getVertices();
    }
    for(int k = 0; k < vertices.size(); k++) {
    //        vertices[k].x = x + vertices[k].y*0.01;
//            vertices[k].x = wrapAround(vertices[k].x, ofGetWidth());
//            vertices[k].x = vertices[k].x + 1.0+sin(ofGetElapsedTimef()*0.05)*ofMap(vertices[k].y, 200, 600, 0, 10);
        ofSetColor(255, 0, 0);
        ofDrawCircle(vertices[k].x, vertices[k].y, 4);
    }
    ofSetColor(255, 255, 255);

    
    p.x = p.x + (1+sin(time))*midiValue;
    
    if(sin(time) > -0.05 && sin(time) < 0.05) {
        ofLog() << sin(time);
    }


//    p.x = wrapAround(p.x, ofGetWidth());
    if(p.x >= ofGetWidth()) {
        p.x = p.x-ofGetWidth();
    }
    ofDrawCircle(p.x, p.y, 2);
}

//--------------------------------------------------------------
void ofApp::newMidiMessage(ofxMidiMessage& msg) {

    // add the latest message to the message queue
    midiMessages.push_back(msg);

    // remove any old messages if we have too many
    while(midiMessages.size() > maxMessages) {
        midiMessages.erase(midiMessages.begin());
    }
    
}

//--------------------------------------------------------------
float ofApp::wrapAround(float coordinate, float max) {
    
    if (coordinate >= max) {
        coordinate = 0;
    }
    
    if (coordinate < 0) {
        coordinate += max;
    }
    
    return coordinate;
}

//--------------------------------------------------------------
void ofApp::exit() {
    
    // clean up
    midiIn.closePort();
    midiIn.removeListener(this);
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

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
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

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
