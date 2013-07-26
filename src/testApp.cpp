#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
  width = ofGetWidth();
  height = ofGetHeight();
  shader.load("cortex");
  fbo.allocate(width,height);
  //set default values
  bVert = 0;
  bHorizon = 0;
  bDiag = 0;
  bArms = 0;
  bRings = 0;
  bSpiral = 0;
  vertSpeed = 1.0;
  horizonSpeed = 1.0;
  diagSpeed = 1.0;
  armSpeed = 1.0;
  ringSpeed = 1.0;
  spiralSpeed = 1.0;
  numVert = 6.0;
  numHorizon = 6.0;
  numDiag = 6.0;
  numRings = 6.0;
  numArms = 5;
  numSpiral = 3;
}

//--------------------------------------------------------------
void testApp::update(){
}

//--------------------------------------------------------------
void testApp::draw(){
  fbo.begin();
  shader.begin();
  setUniforms();
  ofRect(0,0,width,height);
  shader.end();
  fbo.end();

  fbo.draw(0,0,width,height);
  
  ofSetHexColor(0xffffff);
  ofDrawBitmapString(ofToString(ofGetFrameRate(), 4), 10, 10);

}

//--------------------------------------------------------------
void testApp::keyPressed(int key){
  if(key == '1') {
    bVert = !bVert;
  }
  if(key == '2') {
    bHorizon = !bHorizon;
  }
  if(key == '3') {
    bDiag = !bDiag;
  }
  if(key == '4') {
    bArms = !bArms;
  }
  if(key == '5') {
    bRings = !bRings;
  }
  if(key == '6') {
    bSpiral = !bSpiral;
  }
  if(key == 'q') {
    vertSpeed += 1.0;
  }
  if (key == 'Q') {
    vertSpeed -= 1.0;
  }
  if(key == 'w') {
    horizonSpeed += 1.0;
  }
  if (key == 'W') {
    horizonSpeed -= 1.0;
  }
  if(key == 'e') {
    diagSpeed += 1.0;
  }
  if (key == 'E') {
    diagSpeed -= 1.0;
  }
  if(key == 'r') {
    armSpeed += 1.0;
  }
  if (key == 'R') {
    armSpeed -= 1.0;
  }
  if(key == 't') {
    ringSpeed += 1.0;
  }
  if (key == 'T') {
    ringSpeed -= 1.0;
  }
  if(key == 'y') {
    spiralSpeed += 1.0;
  }
  if (key == 'Y') {
    spiralSpeed -= 1.0;
  }
  if(key == 'q') {
    vertSpeed += 1.0;
  }
  if (key == 'Q') {
    vertSpeed -= 1.0;
  }
  if(key == 'w') {
    horizonSpeed += 1.0;
  }
  if (key == 'W') {
    horizonSpeed -= 1.0;
  }
  if(key == 'e') {
    diagSpeed += 1.0;
  }
  if (key == 'E') {
    diagSpeed -= 1.0;
  }
  if(key == 'r') {
    armSpeed += 1.0;
  }
  if (key == 'R') {
    armSpeed -= 1.0;
  }
  if(key == 't') {
    ringSpeed += 1.0;
  }
  if (key == 'T') {
    ringSpeed -= 1.0;
  }
  if(key == 'y') {
    spiralSpeed += 1.0;
  }
  if (key == 'Y') {
    spiralSpeed -= 1.0;
  }
  if(key == 'a') {
    numVert += 1.0;
  }
  if (key == 'A') {
    numVert -= 1.0;
  }
  if(key == 's') {
    numHorizon += 1.0;
  }
  if (key == 'S') {
    numHorizon -= 1.0;
  }
  if(key == 'd') {
    numDiag += 1.0;
  }
  if (key == 'D') {
    numDiag -= 1.0;
  }
  if(key == 'f') {
    numArms += 1;
  }
  if (key == 'F') {
    numArms -= 1;
  }
  if(key == 'G') {
    numRings += 1.0;
  }
  if (key == 'g') {
    numRings -= 1.0;
  }
  if(key == 'h') {
    numSpiral += 1;
  }
  if (key == 'H') {
    numSpiral -= 1;
  }
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

//--------------------------------------------------------------
void testApp::setUniforms(){ 
  float resolution[] = {width, height};
  float time = ofGetElapsedTimef();

  shader.setUniform1f("time",time);
  shader.setUniform2fv("resolution",resolution);

  //flags for turning patterns on/off
  shader.setUniform1f("bVert", bVert);
  shader.setUniform1i("bHorizon", bHorizon);
  shader.setUniform1i("bDiag", bDiag);
  shader.setUniform1i("bArms", bArms);
  shader.setUniform1i("bRings", bRings);
  shader.setUniform1i("bSpiral", bSpiral);

  //pattern speeds
  shader.setUniform1f("vertSpeed", vertSpeed);
  shader.setUniform1f("horizonSpeed", horizonSpeed);
  shader.setUniform1f("diagSpeed", diagSpeed);
  shader.setUniform1f("armSpeed", armSpeed);
  shader.setUniform1f("ringSpeed", ringSpeed);
  shader.setUniform1f("spiralSpeed", spiralSpeed);

  //pattern parameters
  shader.setUniform1f("numVert", numVert);
  shader.setUniform1f("numHorizon", numHorizon);
  shader.setUniform1f("numDiag", numDiag);
  shader.setUniform1f("numArms", numArms);
  shader.setUniform1f("numRings", numRings);
  shader.setUniform1f("numSpiral", numSpiral);
}
