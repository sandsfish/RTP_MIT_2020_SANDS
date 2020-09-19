#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){

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
    
    ofBackground(255);
    
    ofSetColor(0);
    ofSetLineWidth(5);
    ofFill();
    
    ofPushMatrix();
    ofScale(1,-1);
    
    vector < ofPath > paths = font.getStringAsPoints("SANDS");
    
    ofTranslate(-200, 0, 1000);
    
    // Each Letter
    for(int i = 0; i < paths.size(); i++) {
        paths[i].setPolyWindingMode(OF_POLY_WINDING_ODD);
        vector < ofPolyline > lines = paths[i].getOutline();

        // Each Path
        for(int j = 0; j < lines.size(); j++) {
            
            lines[j].setClosed(true);
            lines[j] = lines[j].getResampledBySpacing(2);
            lines[j] = lines[j].getSmoothed(mouseX*0.01);
            
            // Each Point
            for(int k = 0; k < lines[j].size(); k++) {
                
                // lines[j][k].z = lines[j][k].z + sin(ofGetElapsedTimef())*k*mouseY*0.01;
                // ofDrawCircle(lines[j][k], 2);
            }
            
            ofPushMatrix();
            
            for(int m = 0; m < mouseY/10; m++) {

                ofTranslate(250, 0);
                lines[j].draw();
                ofScale(mouseX/500., mouseY/500., 1);
            }
            ofPopMatrix();
            
        }
        
        // paths[i].draw();
    }
    ofPopMatrix();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
//    cam.reset();
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
