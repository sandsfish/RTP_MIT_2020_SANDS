#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){

}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){

    // ofBackground(0,102,0);
    ofBackground(0);

    // easyCam.begin();
    
    ofSeedRandom(0.2);
    
    ofSetLineWidth(10);
    
    contourFinder.setMinAreaRadius(1);
    contourFinder.setMaxAreaRadius(500);
    contourFinder.setThreshold(ofGetMouseY());
    
    // *** Workflow is the key and sensible defaults are the keys ***
    // Build a template library for all the little tools you want (Maybe your own ofxPlugin since that's probably scaffolded
    // to have available every time you start a new project:
    // - Color pallettes near at hand,
    // - maybe some GUI basics,
    // - maybe some MIDI support,
    // - maybe some utilities for how much
    //      space things of a certain size are going to take up
    
    int padding = 100;
    int xOffset = 20;
    int yOffset = 20;
    int xMax = 50;
    int yMax = 50;
    int cSize = 5;
    
    int shapeArrayWidth = (xMax * xOffset - xOffset) / 2;
    int centeredStartingPoint = ofGetWidth()/2 - shapeArrayWidth;
    
    // ofTranslate(-ofGetWidth()/2, -ofGetHeight()/2);
    
    for( int y = 0; y < yMax; y++ ) {
        for(int x = 0; x < xMax; x++ ) {
            
//            float shifter = ofMap(ofGetMouseX(), 0, ofGetWidth(), 0, 30);
//            cout << ofGetFrameNum() % 5 << endl; //% shifter << endl;
            
            //int modValue = static_cast<int>(ofSignedNoise(ofGetElapsedTimef() * 0.8 ) * 20);
   
            float v = ofNoise(sin(ofGetElapsedTimef() * x * 0.00004 * mouseX), sin(ofGetElapsedTimef() * y * 0.00007) * mouseY);
            ofSetColor(v);
            
//            if( x % modValue == 0 ) {
//                ofSetColor(ofColor::aliceBlue);
//            } else {
//                ofSetColor(ofColor::aquamarine);
//            }
            
            int circleX = centeredStartingPoint + x * xOffset;
            int circleY = centeredStartingPoint + y * yOffset;
            
            //ofDrawCircle( circleX , circleY, cSize );
            
//            ofSetColor(255, 0, 0);
            // ofSetColor(25,25,255);
            ofSetColor(255);
            
            int endCapSize = 2;
            
            if(v > 0.0 && v < 0.25) {
                
                ofDrawLine( circleX, circleY, circleX+xOffset, circleY );
                
                // ofSetColor(ofColor::red);
                ofDrawCircle(circleX, circleY, endCapSize);
                ofDrawCircle(circleX+xOffset, circleY, endCapSize);
                
            } else if( v > 0.25 && v < 0.5) {
                
                ofDrawLine( circleX, circleY, circleX, circleY+yOffset );
                
                // ofSetColor(ofColor::red);
                ofDrawCircle(circleX, circleY, endCapSize);
                ofDrawCircle(circleX, circleY+yOffset, endCapSize);
                
            } else if( v > 0.5 && v < 0.75) {
                
                ofDrawLine( circleX, circleY, circleX-xOffset, circleY );
                
                // ofSetColor(ofColor::red);
                ofDrawCircle(circleX, circleY, endCapSize);
                ofDrawCircle(circleX-xOffset, circleY, endCapSize);
                
            } else if( v > 0.75 && v < 1.0){
                ofDrawLine( circleX, circleY, circleX, circleY-yOffset );
                
                // ofSetColor(ofColor::red);
                ofDrawCircle(circleX, circleY, endCapSize);
                ofDrawCircle(circleX, circleY-yOffset, endCapSize);
            }
            
        }
    }
    
    //ofBackground(255);
    ofSetColor(255, 0, 0);
    
    screen.grabScreen(0, 0, ofGetWidth(), ofGetHeight());
    contourFinder.findContours(screen);
    //contourFinder.setFindHoles(true);
    //contourFinder.draw();
    
    // Iterate over contour polylines
    for (auto contourIndex = 0; contourIndex < contourFinder.size(); ++contourIndex) {

        int smoothing = ofMap(ofGetMouseX(), 0, ofGetWidth(), 1, 10); // 8;
        int resample = 6; //ofMap(ofGetMouseY(), 0, ofGetHeight(), 1, 10); // 6;
        
        //ofFill();
        const ofPolyline contour = contourFinder.getPolylines()[contourIndex].getResampledBySpacing(resample).getSmoothed(smoothing);
        contour.draw();
    }
    
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    screen.save("./image.png");
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
