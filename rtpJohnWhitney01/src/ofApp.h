#pragma once

#include "ofMain.h"
#include "ofxMidi.h"

class ofApp : public ofBaseApp, public ofxMidiListener {

	public:
		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void mouseEntered(int x, int y);
		void mouseExited(int x, int y);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
		
        void exit();
        
        // MIDI In
        void newMidiMessage(ofxMidiMessage& eventArgs);
        
        ofxMidiIn midiIn;
        std::vector<ofxMidiMessage> midiMessages;
        std::size_t maxMessages = 15; // max number of messages to keep track of
    
        // MIDI Out
        ofxMidiOut midiOut;
        int channel;
        
        unsigned int currentPgm;
        int note, velocity;
        int pan, bend, touch, polytouch;
    
        int circleCount;
};
