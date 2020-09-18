#pragma once

#include "ofMain.h"
#include "ofxMidi.h"

class ofApp : public ofBaseApp, public ofxMidiListener {

	public:
		void setup();
		void update();
		void draw();
        void exit();

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
		
        float wrapAround(float coordinate, float max);
        float x = 400;
        float y = 400;
        float r = 200;
        ofPolyline line;
        vector<glm::vec3> vertices;
    
        ofPoint p;
        float speed;
        float midiValue = 4.2517;
        bool go = false;
        float time = 0.0;
    
        // MIDI In
        void newMidiMessage(ofxMidiMessage& eventArgs);
        
        ofxMidiIn midiIn;
        std::vector<ofxMidiMessage> midiMessages;
        std::size_t maxMessages = 10; // max number of messages to keep track of
};
