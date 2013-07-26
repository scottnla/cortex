#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
  width = ofGetWidth();
  height = ofGetHeight();
  shader.load("forms");
  fbo.allocate(width,height);
}

//--------------------------------------------------------------
void testApp::update(){
}

//--------------------------------------------------------------
void testApp::draw(){
  float resolution[] = {width, height};
  float time = ofGetElapsedTimef();

  fbo.begin();
  shader.begin();
  shader.setUniform1f("time",time);
  shader.setUniform2fv("resolution",resolution);
  ofRect(0,0,width,height);
  shader.end();
  fbo.end();

  fbo.draw(0,0,width,height);
  
  ofSetHexColor(0xffffff);
  ofDrawBitmapString(ofToString(ofGetFrameRate(), 4), 10, 10);

}

//--------------------------------------------------------------
void testApp::keyPressed(int key){

}

//--------------------------------------------------------------
void testApp::keyReleased(int key){

}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y){

}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void testApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void testApp::dragEvent(ofDragInfo dragInfo){ 

}
