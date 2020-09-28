#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){

    ofEnableAntiAliasing();
    ofEnableSmoothing();
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){

    ofBackground(206, 195, 165);
    ofSetColor(42, 41, 37);
    
    ofDrawBitmapString("Sands Fish", 20, 30);
    ofDrawBitmapString("After Bridget Riley", 20, 44);
    ofDrawBitmapString(ofGetTimestampString("%c"), 20, 58);
    
    int gridX = 2;
    
    int vertexCount = ofClamp(ofMap(ofGetMouseY(), 0, ofGetHeight(), 0, 100), 2, 200); //11;
    (vertexCount % 2 == 0) ? vertexCount = vertexCount+1 :  vertexCount;
    
    int lineCount = ofClamp(2+ofMap(ofGetMouseX(), 0, ofGetWidth(), 0, 100), 2, 20);  //13;
    (lineCount % 2 == 0) ? lineCount = lineCount+1 :  lineCount;
    
    int lineLength = ofClamp(2+ofMap(ofGetMouseY(), 0, ofGetWidth(), 20, ofGetHeight()), 2, ofGetWidth());
    
    // Center drawing based on the width & height of the configured line/grid counts
    int shapeArrayWidth = (lineCount * gridX - gridX) / 2;
    int centeredOffsetX = ofGetWidth()/2 - shapeArrayWidth;
    int centeredOffsetY = ofGetHeight()/2 - lineLength / 2;
    
    int lineWidth = 3;
    ofSetLineWidth(lineWidth);
    
    //--------------------------------------------------------------
    
    vector<ofPolyline> lines;
    
    // Initialize vertical polylines
    for(int x = 0; x < lineCount; x++) {
    
        // Make parallel vertical polylines
        ofPolyline p;
        p.addVertex( (sin(ofGetElapsedTimef()*0.65)*55*x) + centeredOffsetX + x * gridX, centeredOffsetY );
        p.addVertex( (sin(ofGetElapsedTimef()*0.65+1.5)*55*x) + centeredOffsetX + x * gridX, centeredOffsetY+lineLength );
        p = p.getResampledByCount(vertexCount); // .getSmoothed(20);
        lines.push_back(p);
    }
    
    //--------------------------------------------------------------
    
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
    
    //--------------------------------------------------------------

    // Draw Zig-Zags, Starting By Looping Through Parallel Vertices
    for(int v = 0; v < vertexCount-1; v++) {
    
        // Loop Through Each Line (i) While At This Vertex (v)
        for(int i = 0; i < lines.size()-1; i++) {
        
            ofPolyline firstLine;
            firstLine = lines[0];
            
            ofPolyline currentLine;
            currentLine = lines[i];
            
            ofPolyline nextLine;
            nextLine = lines[i+1];
            
            if(i % 2 == 0) {
                // Going Down!
                ofDrawLine(currentLine[v].x, currentLine[v].y, nextLine[v+1].x, nextLine[v+1].y);
            } else {
                // Going Up!
                ofDrawLine(currentLine[v+1].x, currentLine[v+1].y, nextLine[v].x, nextLine[v].y);
            }
            
            // Close the beginning & end of the shape when we hit the last line on an odd numbered vertex
            if(i == lines.size()-2 && v % 2 == 1) {
                    
                // Close Beginning
                ofDrawLine(firstLine[v-1].x, firstLine[v-1].y, firstLine[v].x, firstLine[v].y);
                
                // Close End
                ofDrawLine(nextLine[v-1].x, nextLine[v-1].y, nextLine[v].x, nextLine[v].y);
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
