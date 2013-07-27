#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
  //ofSetFrameRate(60);
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
  vertSpeed = 4.0;
  horizonSpeed = 4.0;
  diagSpeed = 4.0;
  armSpeed = 4.0;
  ringSpeed = 4.0;
  spiralSpeed = 4.0;
  numVert = 48.0;
  numHorizon = 48.0;
  numDiag = 48.0;
  numRings = 12.0;
  numArms = 4;
  numSpiral = 3;
  vertSign = 1;
  horizonSign = 1;
  diagSign = 1;
  armSign = 1;
  ringSign = 1;
  spiralSign = 1;
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
  
  //ofSetHexColor(0xffffff);
  //ofDrawBitmapString(ofToString(ofGetFrameRate(), 4), 10, 10);

  //ofSaveFrame(true);
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
    vertSpeed += 2.0;
  }
  if (key == 'Q') {
    vertSpeed -= 2.0;
  }
  if(key == 'w') {
    horizonSpeed += 2.0;
  }
  if (key == 'W') {
    horizonSpeed -= 2.0;
  }
  if(key == 'e') {
    diagSpeed += 2.0;
  }
  if (key == 'E') {
    diagSpeed -= 2.0;
  }
  if(key == 'r') {
    armSpeed += 2.0;
  }
  if (key == 'R') {
    armSpeed -= 2.0;
  }
  if(key == 't') {
    ringSpeed += 2.0;
  }
  if (key == 'T') {
    ringSpeed -= 2.0;
  }
  if(key == 'y') {
    spiralSpeed += 2.0;
  }
  if (key == 'Y') {
    spiralSpeed -= 2.0;
  }
  if(key == 'q') {
    vertSpeed += 2.0;
  }
  if (key == 'Q') {
    vertSpeed -= 2.0;
  }
  if(key == 'w') {
    horizonSpeed += 2.0;
  }
  if (key == 'W') {
    horizonSpeed -= 2.0;
  }
  if(key == 'e') {
    diagSpeed += 2.0;
  }
  if (key == 'E') {
    diagSpeed -= 2.0;
  }
  if(key == 'r') {
    armSpeed += 2.0;
  }
  if (key == 'R') {
    armSpeed -= 2.0;
  }
  if(key == 't') {
    ringSpeed += 2.0;
  }
  if (key == 'T') {
    ringSpeed -= 2.0;
  }
  if(key == 'y') {
    spiralSpeed += 2.0;
  }
  if (key == 'Y') {
    spiralSpeed -= 2.0;
  }
  if(key == 'a') {
    numVert += 4.0;
  }
  if (key == 'A') {
    numVert -= 4.0;
  }
  if(key == 's') {
    numHorizon += 4.0;
  }
  if (key == 'S') {
    numHorizon -= 4.0;
  }
  if(key == 'd') {
    numDiag += 4.0;
  }
  if (key == 'D') {
    numDiag -= 4.0;
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
  if (key == 'z') {
    vertSign *= -1;
  }
  if (key == 'x') {
    horizonSign *= -1;
  }
  if (key == 'c') {
    diagSign *= -1;
  }
  if (key == 'v') {
    armSign *= -1;
  }
  if (key == 'b') {
    ringSign *= -1;
  }
  if (key == 'n') {
    spiralSign *= -1;
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
  
  //direction parameters
  shader.setUniform1f("vertSign", vertSign);
  shader.setUniform1f("horizonSign", horizonSign);
  shader.setUniform1f("diagSign", diagSign);
  shader.setUniform1f("armSign", armSign);
  shader.setUniform1f("ringSign", ringSign);
  shader.setUniform1f("spiralSign", spiralSign);
}
