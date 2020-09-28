#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){

    font.load("framd.ttf", 50);
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){

    ofBackground(255);
    ofSetColor(255, 0, 0);
    ofDrawLine(ofGetWidth()/2, 0, ofGetWidth()/2, ofGetHeight());
    ofDrawLine(0, ofGetHeight()/2, ofGetWidth(), ofGetHeight()/2);
    
    ofRectangle originalRectangle = font.getStringBoundingBox("SANDS", 0,0);
    ofPoint diffFromStart = originalRectangle.getPosition() - ofPoint(0,0);
    
        ofSetColor(0);
        ofDrawBitmapString("diffFromStart", diffFromStart);
    
    // setup the target
    ofRectangle target (300,300,mouseX-300, mouseY-300);
    
        ofSetColor(0);
        ofDrawBitmapString("target", mouseX-300, mouseY-300);
    
    ofNoFill();
    ofSetLineWidth(3);
    ofSetColor(0,255,0);
    ofDrawRectangle(target);
    
    // scale to the target
    ofRectangle scaled = originalRectangle;
    scaled.scaleTo(target);
    ofSetColor(0,0,255);
    ofDrawRectangle(scaled);
    
        ofSetColor(0);
        ofDrawBitmapString("diffFromStart", scaled.getBottomLeft());
    
    // figure out how much we need to move and scale
    ofPoint diff = scaled.getPosition() - originalRectangle.getPosition();
    float scale = (float)scaled.getWidth() / (float)originalRectangle.getWidth();
    
    // move and scale and draw
    ofPushMatrix();
    ofSetColor(255);
    ofTranslate(diff.x, diff.y);
    ofTranslate(diffFromStart + ofPoint(0,scaled.getHeight()));
    ofScale(scale, scale);
    
    
    vector < ofPath > paths = font.getStringAsPoints("SANDS");
    
    // Each Letter //
    for(int i = 0; i < paths.size(); i++) {
        paths[i].setPolyWindingMode(OF_POLY_WINDING_ODD);
        vector < ofPolyline > lines = paths[i].getOutline();

        // Each Path //
        for(int j = 0; j < lines.size(); j++) {
            
            lines[j].setClosed(true);
//            lines[j] = lines[j].getResampledBySpacing(2);
//            lines[j] = lines[j].getSmoothed(5);
            
            // Each Point //
            for(int k = 0; k < lines[j].size(); k++) {
                
                // lines[j][k].z = lines[j][k].z + sin(ofGetElapsedTimef())*k*mouseY*0.01;
                ofSetColor(255, 0, 0);
                // ofDrawCircle(lines[j][k].x, lines[j][k].y, 2);
                // ofDrawCircle(lines[j][k], 2);
            }
            
            ofPushMatrix();
            
            for(int m = 0; m < mouseY/100; m++) {
                
                // ofTranslate(ofGetWidth()/2, ofGetHeight()/2);
                lines[j].draw();
                // ofScale(mouseX/500.0, mouseY/500.0);
                // ofScale(mouseX/500.0);
            }
            ofPopMatrix();
            
        }
        
        // paths[i].draw();
    }
    ofSetColor(ofColor::black);
     font.drawString("SANDS", 0,0);

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
