#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){

}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){

    ofBackground(255);
    ofSetColor(0);
    
    int gridX = 100;
    int vertexCount = 20;
    int lineCount = 1+ofMap(mouseX, 0, ofGetWidth(), 0, 100);  //6;
    int lineLength = 600;
    
    int shapeArrayWidth = (lineCount * gridX - gridX) / 2;
    int centeredOffsetX = ofGetWidth()/2 - shapeArrayWidth;
    int centeredOffsetY = ofGetHeight()/2 - lineLength / 2;
    
    vector<ofPolyline> lines;
    
    // Initialize vertical polylines
    for(int x = 0; x < lineCount; x++) {
    
        // Make parallel vertical polylines
        ofPolyline p;
        p.addVertex(centeredOffsetX + x * gridX, centeredOffsetY);
        p.addVertex(centeredOffsetX + x * gridX, centeredOffsetY+lineLength);
        p = p.getResampledByCount(vertexCount);
        lines.push_back(p);
    }
    
    // Draw verticies as points
    for(int i = 0; i < lines.size(); i++) {
        
        ofPolyline p;
        p = lines[i];
        auto verts = p.getVertices();

        ofSetColor(0);
        p.draw();
        
        for(int point = 0; point < verts.size(); point++) {
            
            ofSetColor(ofColor::red);
            ofDrawCircle(verts[point].x, verts[point].y, 3.0);
        }
    }
    
    // Draw zig-zags
    for(int v = 0; v < vertexCount-1; v++) {
    
        for(int i = 0; i < lines.size()-1; i++) {
        
            ofPolyline currentLine;
            currentLine = lines[i];
            auto currentLineVerts = currentLine.getVertices();
            
            ofPolyline nextLine;
            nextLine = lines[i+1];
            auto nextLineVerts = nextLine.getVertices();
                
            ofSetColor(ofColor::blue);
                
            if(i != lines.size()-1) {
                if(i % 2 == 0) {
                    ofDrawLine(currentLine[v].x, currentLine[v].y, nextLineVerts.at(v+1).x, nextLineVerts.at(v+1).y);
                } else {
                    ofDrawLine(currentLine[v+1].x, currentLine[v+1].y, nextLineVerts[v].x, nextLineVerts[v].y);
                }
            } else {
                // you're at the last line. go down one and turn around,
                // going negative to the left until you connect to the first line.
                // then skip one vertex and do it all over again.
            }
        }
    }
    
    
    
    // Get points by space
    
    
    // Use points from each to connect a zig-zag line
    
    
    // Use above method to walk around a zig-zag shape and fill
    
    // p.setClosed(true);
    
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
