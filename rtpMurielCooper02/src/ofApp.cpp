#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
//    font.load("00Cryonix.ttf", 100, true, true, true);
//    font.load("digit.ttf", 100, true, true, true);
    font.load("AgendaBoldCondensed.ttf", 200, true, true, true);
    
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
    
//    ofTranslate(0, -600, 300);
    ofTranslate(-200, 0, 100);
    
    // Each Letter
    for(int i = 0; i < paths.size(); i++) {
        paths[i].setPolyWindingMode(OF_POLY_WINDING_ODD);
        vector < ofPolyline > lines = paths[i].getOutline();
//        ofRotateYDeg(sin(ofGetElapsedTimef())*30);
        // Each Path
        for(int j = 0; j < lines.size(); j++) {
            
            lines[j].setClosed(true);
            lines[j] = lines[j].getResampledBySpacing(4);
            lines[j] = lines[j].getSmoothed(mouseX*0.01);
            
            // Each Point
            for(int k = 0; k < lines[j].size(); k++) {
                
                lines[j][k].x = lines[j][k].x + ofSignedNoise(ofGetElapsedTimef()*0.6)*k*0.4;
                lines[j][k].y = lines[j][k].y + ofSignedNoise(ofGetElapsedTimef()*0.2)*k*0.3;
                lines[j][k].z = lines[j][k].z + ofSignedNoise(ofGetElapsedTimef()*0.4)*k*0.5;
                
//                lines[j][k].z = lines[j][k].z + sin(ofGetElapsedTimef())*k*mouseY*0.01;
//                ofDrawCircle(lines[j][k], 2);
            }
            
            lines[j].draw();
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
