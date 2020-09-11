#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){

    ofSetVerticalSync(true);
    ofBackground(255, 255, 255);
    ofSetLogLevel(OF_LOG_VERBOSE);
    
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
    midiIn.setVerbose(true);
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){

    ofBackground(0);
    ofSetColor(244, 132, 179);
    
    int circleSize = 2;
    int circleCount = 80;
    float phaseChange = 0.1;
    
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
                        circleSize = ofMap(message.value, 0, 127, 0, 200);
                        break;
                    case 71:
                        circleCount = ofMap(message.value, 0, 127, 0, 200);
                        break;
                    case 76:
                        phaseChange = ofMap(message.value, 0, 127, 0, 2);
                    default:
                        ofLog() << "Unimplemented MIDI Control Change";
                }
                ofLog() << message.control << " // " << message.value;
                
            }
        }
    }
    
    // DNA Twist
    for(int i = 0; i < circleCount; i++) {
        ofDrawCircle(i*20, ofGetWidth()/2+sin(ofGetElapsedTimef()*i*phaseChange)*50, circleSize);
    }
    
    for(int i = 0; i < circleCount; i++) {
        ofDrawCircle(i*20, ofGetWidth()/2+sin(ofGetElapsedTimef()*i*phaseChange)*100, circleSize);
    }
    
    for(int i = 0; i < circleCount; i++) {
        ofDrawCircle(i*20, ofGetWidth()/2+sin(ofGetElapsedTimef()*i*phaseChange)*200, circleSize);
    }
    
    for(int i = 0; i < circleCount; i++) {
        ofDrawCircle(i*20, ofGetWidth()/2+sin(ofGetElapsedTimef()*i*phaseChange)*250, circleSize);
    }
    
    for(int i = 0; i < circleCount; i++) {
        ofDrawCircle(i*20, ofGetWidth()/2+sin(ofGetElapsedTimef()*i*phaseChange)*300, circleSize);
    }
    
    for(int i = 0; i < circleCount; i++) {
        ofDrawCircle(i*20, ofGetWidth()/2+sin(ofGetElapsedTimef()*i*phaseChange)*350, circleSize);
    }
}

void ofApp::newMidiMessage(ofxMidiMessage& msg) {

    // add the latest message to the message queue
    midiMessages.push_back(msg);

    // remove any old messages if we have too many
    while(midiMessages.size() > maxMessages) {
        midiMessages.erase(midiMessages.begin());
    }
    
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    switch(key) {
        case '?':
            midiIn.listInPorts();
            break;
    }
}

//--------------------------------------------------------------
void ofApp::exit() {
    
    // clean up
    midiIn.closePort();
    midiIn.removeListener(this);
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
