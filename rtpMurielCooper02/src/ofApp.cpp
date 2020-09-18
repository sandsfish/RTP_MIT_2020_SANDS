#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    font.load("00Cryonix.ttf", 100, true, true, true);
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){

    ofEnableDepthTest();
    
    cam.enableOrtho();
    cam.begin();
    
    ofSetColor(255);
    
    ofPushMatrix();
    ofScale(1,-1);
    
    vector < ofPath > paths = font.getStringAsPoints("SANDS");
    
    ofTranslate(600, -600, -100);
    
    // Each Letter
    for(int i = 0; i < paths.size(); i++) {
        paths[i].setPolyWindingMode(OF_POLY_WINDING_ODD);
        vector < ofPolyline > lines = paths[i].getOutline();
        ofRotateYDeg(sin(ofGetElapsedTimef())*30);
        // Each Path
        for(int j = 0; j < lines.size(); j++) {
            
            lines[j] = lines[j].getResampledBySpacing(4);
            
            // Each Point
            for(int k = 0; k < lines[j].size(); k++) {
                
                lines[j][k].z = lines[j][k].z + sin(ofGetElapsedTimef()*k*0.1);
                ofDrawCircle(lines[j][k], 2);
            }
        }
        
        //        paths[i].draw();
    }
    ofPopMatrix();
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
