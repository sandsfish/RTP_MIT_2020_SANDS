#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){

}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){

    ofBackground(206, 195, 165);
    ofSetColor(42, 41, 37);
    ofSetLineWidth(1);
    
    ofDrawBitmapString("Sands Fish", 20, 30);
    ofDrawBitmapString("After Bridget Riley", 20, 42);
    ofDrawBitmapString(ofGetTimestampString("%c"), 20, 54);
    
    int gridX = 20;
    int vertexCount = 11; //ofClamp(ofMap(ofGetMouseY(), 0, ofGetHeight(), 0, 100), 2, 200);
    int lineCount = 13; //ofClamp(2+ofMap(mouseX, 0, ofGetWidth(), 0, 100), 2, 20);  //7;
    int lineLength = 400;
    
    int shapeArrayWidth = (lineCount * gridX - gridX) / 2;
    int centeredOffsetX = ofGetWidth()/2 - shapeArrayWidth;
    int centeredOffsetY = ofGetHeight()/2 - lineLength / 2;
    
    vector<ofPolyline> lines;
    
    // Initialize vertical polylines
    for(int x = 0; x < lineCount; x++) {
    
        // Make parallel vertical polylines
        ofPolyline p;
        p.addVertex( (sin(ofGetElapsedTimef())*60*x) + centeredOffsetX + x * gridX, centeredOffsetY );
        p.addVertex( (sin(ofGetElapsedTimef()+1.5)*60*x) + centeredOffsetX + x * gridX, centeredOffsetY+lineLength );
        p = p.getResampledByCount(vertexCount); // .getSmoothed(20);
        lines.push_back(p);
    }
    
    ofSetLineWidth(1);
    
    // Draw verticies as points and vertical polylines
    for(int i = 0; i < lines.size(); i++) {
        
        ofPolyline p;
        p = lines[i];
        auto verts = p.getVertices();

        if(drawPolylines == true) {
            ofPushStyle();
            ofSetColor(ofColor::blue);
            p.draw();
            ofPopStyle();
        }
        
        if(drawVerticies == true) {
            for(int point = 0; point < verts.size(); point++) {
                ofPushStyle();
                ofSetColor(ofColor::red);
                ofDrawCircle(verts[point].x, verts[point].y, 3.0);
                ofPopStyle();
            }
        }
    }
    
    ofSetLineWidth(1);
    
    // Draw Zig-Zags, Starting By Looping Through Parallel Vertices
    for(int v = 0; v < vertexCount-1; v++) {
    
        // Loop Through Each Line (i) While At This Vertex (v)
        for(int i = 0; i < lines.size()-1; i++) {
        
            ofPolyline firstLine;
            firstLine = lines[0];
            auto firstLineVerts = firstLine.getVertices();
            
            ofPolyline currentLine;
            currentLine = lines[i];
            auto currentLineVerts = currentLine.getVertices();
            
            ofPolyline nextLine;
            nextLine = lines[i+1];
            auto nextLineVerts = nextLine.getVertices();
                
            //ofSetColor(ofColor::blue);
            
            if(i % 2 == 0) {
                // Going Down!
                ofDrawLine(currentLine[v].x, currentLine[v].y, nextLineVerts.at(v+1).x, nextLineVerts.at(v+1).y);
            } else {
                // Going Up!
                ofDrawLine(currentLine[v+1].x, currentLine[v+1].y, nextLineVerts[v].x, nextLineVerts[v].y);
            }
            
            // We're At The Last Line (left to right) and on an even vertex
            if(i == lines.size()-2 && v % 2 == 1) {
                
                ofSetLineWidth(1);
                //ofSetColor(ofColor::blue);
                
                // Close the end & beginning of the shape if we're at the end of a row
                // For an even numbered vertical line:
                if(v % 2 == 1) {
                    
                    // Close End
                    ofDrawLine(nextLine[v-1].x, nextLine[v-1].y, nextLine[v].x, nextLine[v].y);
                    
                    // Close Beginning
                    ofDrawLine(firstLine[v-1].x, firstLine[v-1].y, firstLine[v].x, firstLine[v].y);
                
                // For an odd numbered vertical line (balanced):
//                } else {
//
//                    if(v+2 < vertexCount-3) {
//
//                        ofSetLineWidth(3);
//                        ofSetColor(ofColor::red);
//                        ofDrawLine(nextLine[v+1].x, nextLine[v+1].y, nextLine[v+2].x, nextLine[v+2].y);
//                        ofSetLineWidth(1);
//                    }
                }
            }
        }
    }
    
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

    if(key == OF_KEY_LEFT) {
        
        drawPolylines = !drawPolylines;
    }
    
    if(key == OF_KEY_RIGHT) {
        
        drawVerticies = !drawVerticies;
    }
    
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
