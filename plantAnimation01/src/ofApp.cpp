#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){

    // leaf01.load("coffee_leaf1.png");
    // leaf01.load("pistons.png");
    //leaf01.load("all_flowers.jpg");
    //leaf01.load("bubly_cherry.png");
    leaf01.load("amethyst.png");
    
    ofEnableBlendMode(ofBlendMode::OF_BLENDMODE_SCREEN);
    ofEnableAlphaBlending();
    
    //leaf01.resize(leaf01.getWidth()+50, leaf01.getHeight()+50);
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){

    ofBackground(255);
    
    float speedMultiplier = ofMap(ofGetMouseX(), 0.0, ofGetWidth(), 0.0, 2.0); //4.0);  <--- From first set of iterations, want to dial this back
    
    float phase = 0;
    
    /*
    for(int i = 0; i < mouseY/10; i++) {
        
        phase += 0.05;
    
        float rotateNoise = ofSignedNoise(ofGetElapsedTimef()*0.1*phase) * mouseX/10;
        
        //leaf01.resize(leaf01.getWidth()+rotateNoise, leaf01.getHeight()+rotateNoise);
        
//        ofSetColor(i*1.5, i*1.3, i*1.7);
        
        ofPushMatrix();
            ofTranslate(ofGetWidth()/2, ofGetHeight()/2 - leaf01.getWidth()/2);
        
        ofRotateDeg(rotateNoise * i * 0.01 *PI);
        ofScale(rotateNoise/10); //----
            leaf01.draw(0,0);
        ofPopMatrix();

    }*/
    
    
    for(int i = 0; i < mouseY/10; i++) {
        
        phase += 0.01;
        
        if(i % 2 == 0) {
            ofTranslate(i*10, 0);
        } else {
            ofTranslate(-i*10, 0);
        }
        
        ofPushMatrix();
            ofTranslate(ofGetWidth()/2, ofGetHeight()/2);
            ofRotateDeg(ofGetElapsedTimef()*PI*i*phase*speedMultiplier);
            leaf01.draw(0,0);
        
        ofPopMatrix();
        
        ofPushMatrix();
            ofTranslate(ofGetWidth()/2, ofGetHeight()/2);
            ofRotateDeg(ofGetElapsedTimef()*PI*i*speedMultiplier*-1.0);
            leaf01.draw(0,0);
        ofPopMatrix();
    }
    
    
    /* for(int i = 0; i < mouseY/10; i++) {
        ofPushMatrix();
            ofTranslate(ofGetWidth()/2, ofGetHeight()/2);
            ofRotateDeg(ofGetElapsedTimef()*PI*i*speedMultiplier);
            leaf01.draw(0,0);
        ofPopMatrix();
    } */
    
    
    
    /*
    ofPushMatrix();
        ofTranslate(ofGetWidth()/2, ofGetHeight()/2);
        ofRotateDeg(ofGetElapsedTimef()*PI*3*speedMultiplier);
        leaf01.draw(0,0);
    ofPopMatrix();
    
    ofPushMatrix();
        ofTranslate(ofGetWidth()/2, ofGetHeight()/2);
        ofRotateDeg(ofGetElapsedTimef()*PI*6*speedMultiplier);
        leaf01.draw(0,0);
    ofPopMatrix();
    
    ofPushMatrix();
        ofTranslate(ofGetWidth()/2, ofGetHeight()/2);
        ofRotateDeg(ofGetElapsedTimef()*PI*9*speedMultiplier);
        leaf01.draw(0,0);
    ofPopMatrix();
    */
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){
    //cout << x << "/" << y;
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
