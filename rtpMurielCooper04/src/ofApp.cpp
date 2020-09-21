#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){

    font.load("Microsoft Sans Serif.ttf", 48, true, true, true);
    font.setLetterSpacing(0.8);
    
    ofEnableBlendMode(ofBlendMode::OF_BLENDMODE_MULTIPLY);
    
    ofHideCursor();
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){

    ofBackground(ofColor(239, 228, 208));
    
    ofColor fontColor = ofColor(40);
    ofColor fontColorA = ofColor( 52, 155, 207 ); //ofColor::blue;
    ofColor fontColorB = ofColor( 194, 30, 101 ); //ofColor::red;
    ofColor fontColorC = ofColor( 251, 219, 46 ); //ofColor::yellow;
    
    static float OFFSET_INTERACTION = 352.5;
    static float TOP_PADDING = 82.315; // 52.315;
    
    float txtShift = ofSignedNoise( ofGetElapsedTimef()*0.35 ) * 45;
    float txtShift2 = ofSignedNoise( ofGetElapsedTimef()*0.35 + 10 ) * 45;
    
    ofFill();
    
    // BUG: Using ints in the string location prints out strings from program memory
    // ofDrawBitmapString(mouseX + " / " + mouseY, 800, 800);
    
    // ofSetColor(0);
    // ofDrawBitmapString(ofToString(ofGetMouseX()) + " / " + ofToString(ofGetMouseY()), 900, 900);
    
    for(int i = 0; i < 19; i++) {
        
        ofSetColor(fontColor);
        font.drawString("MUL", 80, TOP_PADDING + i*52);
        
        ofSetColor(fontColor);
        font.drawString("       TIPLE", 75, TOP_PADDING + i*52);
        
        ofSetColor( fontColorA );
        font.drawString("INTERACTION", OFFSET_INTERACTION, TOP_PADDING + i*52 );
        
        // FIXME: Alpha Blending Isn't Working With ofTrueTypeFont.drawString(); Drawing As Paths In The Meantime.
        // ofSetColor(fontColorB);
        // font.drawString(" NTERACTION", offsetINTERACTION + txtShift, 52.315 + i*52 );
        
        vector < ofPath > paths = font.getStringAsPoints("INTERACTION");
        
        ofPushMatrix();
        
            ofTranslate( OFFSET_INTERACTION + txtShift, TOP_PADDING + i*52 );
        
            // Each Letter //
            for(int j = 0; j < paths.size(); j++) {
                
                paths[j].setPolyWindingMode(OF_POLY_WINDING_ODD);
                ofSetColor( fontColorB );
                paths[j].draw();
            }
        
        ofPopMatrix();
        
        ofPushMatrix();
        
            ofTranslate( OFFSET_INTERACTION + txtShift2, TOP_PADDING + i*52 );
            
            // Each Letter //
            for(int j = 0; j < paths.size(); j++) {
                
                paths[j].setPolyWindingMode(OF_POLY_WINDING_ODD);
                ofSetColor( fontColorC );
                paths[j].draw();
            }
        
        ofPopMatrix();
    }
    
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
