#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){

}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){

    float x_origin = 400;
    float y_origin = 400;
    float angle = ofGetElapsedTimef() * 5;
    float radius = 100 + 200 * sin(ofGetElapsedTimef() * 10.0);
    
    float x = x_origin + radius * cos(angle);
    float y = y_origin + radius * sin(angle);
    
    trail.addVertex(x, y);
    if(trail.size() > 200) {
        trail.getVertices().erase(trail.getVertices().begin());
    }
    
    trail.close();
//    trail.draw();
    
    ofPath closed;
    auto vs = trail.getVertices();
    for(int i = 0; i < trail.size(); i++) {
        closed.lineTo(vs.at(i));
    }
    closed.setFilled(true);
    closed.setFillColor(ofColor::skyBlue);
    closed.draw();
    
//    ofDrawCircle(x, y, 5);
    
    
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
