#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){

    ofSetBackgroundAuto(false);
    ofBackground(0,0,0);
    ofEnableAlphaBlending();
    ofSetFrameRate(150);
    ofSetVerticalSync(false);
    // ofEnableAntiAliasing();
    
    ofSetLineWidth(1);
    
    DISPLACE_AMPLITUDE = 20;
    
    noiseSpread1 = ofRandom(-1, 1);
    noiseSpread2 = ofRandom(-1, 1);
    
    int RECT_SIZE = 600;
    ofSetRectMode(OF_RECTMODE_CENTER);
    glm::vec2 center = glm::vec2(ofGetWidth()/2, ofGetHeight()/2);
    r.setFromCenter(center, RECT_SIZE, RECT_SIZE);
}

//--------------------------------------------------------------
void ofApp::update(){

    // Initialize Verticies To Original Rectangle Location
    line.clear();
    line.addVertex(r.getTopLeft());
    line.addVertex(r.getTopRight());
    line.addVertex(r.getBottomRight());
    line.addVertex(r.getBottomLeft());
    line.addVertex(r.getTopLeft());
    line.setClosed(true);
    line.close();
    
    int SUBDIVISION_COUNT = 1000;
    line = line.getResampledByCount(SUBDIVISION_COUNT);
    vertices = line.getVertices();
    
    noiseSpread1 = 0.0;
    noiseSpread2 = 0.05;
    
    // Add noise to vertices
    for (int i = 0; i < vertices.size(); i++) {
        
        noiseSpread1 += 0.05;
        noiseSpread2 += 0.03;
        
        DISPLACE_AMPLITUDE = ofSignedNoise(0.03*ofGetElapsedTimef()/20)*800.0;
        // DISPLACE_AMPLITUDE = 200;
        vertices[i].x = vertices[i].x + ofSignedNoise(i*0.03, (ofGetElapsedTimef()*0.05)+noiseSpread1)*DISPLACE_AMPLITUDE;
        vertices[i].y = vertices[i].y + ofSignedNoise(i*0.05, (ofGetElapsedTimef()*0.08)+noiseSpread2)*DISPLACE_AMPLITUDE;
    }
}

//--------------------------------------------------------------
void ofApp::draw() {

    // ofBackground(0);
    
    // Draw Line Segments
    for (int i = 0; i < vertices.size(); i++)
    {
        // DEBUG MODE: Draw red circle around point & label with coordinates
        // ofSetColor(255, 0, 0, 180);
        // ofDrawCircle(vertices[i], 4);
        // ofDrawBitmapString(vertices[i], vertices[i].x + 20, vertices[i].y);
        
        // Draw current line segment
        if(i < vertices.size()-1)
        {
            ofSetColor(ofColor::grey);
            // Flowing Color:
            // ofSetColor(255*ofNoise(ofGetElapsedTimef()*0.005*i), 255*ofNoise(ofGetElapsedTimef()*0.002*i+10), 255*ofNoise(ofGetElapsedTimef()*0.007*i+20));
            
            ofEnableAlphaBlending();
            ofSetColor(255,255,255,2);
            ofDrawLine(vertices[i], vertices[i+1]);
            ofDisableAlphaBlending();
            
        }
    }
    
    // Draw Final Line Segment To Close Shape
    
    // Flowing Color:
    // ofSetColor(255*ofNoise(ofGetElapsedTimef()*0.5), 255*ofNoise(ofGetElapsedTimef()*0.2+10), 255*ofNoise(ofGetElapsedTimef()*0.7+20));
    
    // ofSetColor(ofColor::grey);
    ofEnableAlphaBlending();
    ofSetColor(255,255,255,2);
    ofDrawLine(vertices[vertices.size()-1], vertices[0]);
    ofDisableAlphaBlending();
    
    // Draw Straight
    // ofSetColor(ofColor::white);
    // line.draw();
    
    // Draw Smoothed
    // ofSetColor(ofColor::powderBlue);
    // line.getSmoothed(5,0).draw();
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
    ofBackground(0);
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
