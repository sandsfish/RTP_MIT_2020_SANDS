#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){

}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw()
{
    int ROTATION_DEGREE = 5;
    ofColor RECT_COLOR = ofColor(62, 90, 146);
    
    ofBackground(255);
    
    ofEnableAlphaBlending();
    ofEnableBlendMode(ofBlendMode::OF_BLENDMODE_MULTIPLY);
    
    ofTranslate(ofGetWidth() / 2 + 31, ofGetHeight() / 2);
    
    int RECT_SIZE = 800;
    ofRectangle r;
    ofSetRectMode(OF_RECTMODE_CENTER);
    r.setFromCenter(0, 0, RECT_SIZE, RECT_SIZE);
    
    // Initialize Verticies To Original Rectangle Location
    ofPolyline line1;
    line1.clear();
    line1.addVertex(r.getTopLeft());
    line1.addVertex(r.getTopRight());
    line1.addVertex(r.getBottomRight());
    line1.addVertex(r.getBottomLeft());
    line1.addVertex(r.getTopLeft());
    line1.setClosed(true);
    line1.close();
    
    // ------------------------------------------------------------>
    
    RECT_SIZE = 500;
    ofRectangle r2;
    ofSetRectMode(OF_RECTMODE_CENTER);
    r2.setFromCenter(0, 0, RECT_SIZE, RECT_SIZE);
    
    // Initialize Verticies To Original Rectangle Location
    ofPolyline line2;
    line2.clear();
    line2.addVertex(r2.getTopLeft());
    line2.addVertex(r2.getTopRight());
    line2.addVertex(r2.getBottomRight());
    line2.addVertex(r2.getBottomLeft());
    line2.addVertex(r2.getTopLeft());
    line2.setClosed(true);
    line2.close();

    // ------------------------------------------------------------>
    
    RECT_SIZE = 200;
    ofRectangle r3;
    ofSetRectMode(OF_RECTMODE_CENTER);
    r3.setFromCenter(0, 0, RECT_SIZE, RECT_SIZE);
    
    // Initialize Verticies To Original Rectangle Location
    ofPolyline line3;
    line3.clear();
    line3.addVertex(r3.getTopLeft());
    line3.addVertex(r3.getTopRight());
    line3.addVertex(r3.getBottomRight());
    line3.addVertex(r3.getBottomLeft());
    line3.addVertex(r3.getTopLeft());
    line3.setClosed(true);
    line3.close();
    
    // ------------------------------------------------------------>
    
    // Create and populate clipper
    ofx::Clipper clipper;
    
    clipper.addPolyline(line1, ClipperLib::ptSubject);
    clipper.addPolyline(line2, ClipperLib::ptClip);
    
    // Calculate intersection between the two polygons
    auto intersection = clipper.getClipped(ClipperLib::ClipType::ctDifference);
    
    clipper.Clear();
    clipper.addPolyline(line2, ClipperLib::ptSubject);
    clipper.addPolyline(line3, ClipperLib::ptClip);
    
    // Calculate intersection between the two polygons
    auto intersection2 = clipper.getClipped(ClipperLib::ClipType::ctDifference);
    
    // ------------------------------------------------------------>
    // Draw Outer-Most Rectangle
    
    ofFill();
    ofSetColor(RECT_COLOR);
    
    ofPushMatrix();
    ofRotateZDeg(-ROTATION_DEGREE);
    ofTranslate(-31, 0);
    
    ofBeginShape();
    for (auto& line: intersection)
    {
        vector<glm::vec3>& vertices = line.getVertices();
        for(int j = 0; j < vertices.size(); j++) {
            ofVertex(vertices[j]);
            if(j == vertices.size()-1) {
                ofVertex(vertices[0]);
            }
        }
    }
    ofEndShape();
    ofPopMatrix();
    
    // ------------------------------------------------------------>
    // Draw Middle Rectangle
    
    ofBeginShape();
    for (auto& line: intersection2)
    {
        vector<glm::vec3>& vertices = line.getVertices();
        for(int j = 0; j < vertices.size(); j++) {
            ofVertex(vertices[j]);
            if(j == vertices.size()-1) {
                ofVertex(vertices[0]);
            }
        }
    }
    ofEndShape();
    
    // ------------------------------------------------------------>
    // Draw Inner-Most Rectangle
    
    ofPushMatrix();
    
    ofRotateZDeg(ROTATION_DEGREE);
    ofTranslate(-2, -20);
    
    ofBeginShape();
        vector<glm::vec3>& vertices = line3.getVertices();
        for(int j = 0; j < vertices.size(); j++) {
            ofVertex(vertices[j]);
            if(j == vertices.size()-1) {
                ofVertex(vertices[0]);
            }
        }
    ofEndShape();
    
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
