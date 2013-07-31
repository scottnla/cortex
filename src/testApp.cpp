#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
  ofEnableSmoothing();
  ofSetFrameRate(60);
  ofSetVerticalSync(true);
  width = ofGetWidth();
  height = ofGetHeight();
  shader.load("cortex");
  fbo.allocate(width,height);
    
  syphonOutput.setName("Cortex");
    
  //set default values
  deltaSpeed = 0.02;
  bVert = 0;
  bHorizon = 0;
  bDiag = 0;
  bArms = 0;
  bRings = 0;
  bSpiral = 0;
  sVert = 0;
  sHorizon = 0;
  sDiag = 0;
  sArms = 0;
  sRings = 0;
  sSpiral = 0;
  vertSpeed = 0.0;
  horizonSpeed = 0.0;
  diagSpeed = 0.0;
  armSpeed = 0.04;
  ringSpeed = 0.04;
  spiralSpeed = 0.04;
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
  float dt = 1.f / ofGetFrameRate();
  sVertTweener.update(dt);
  sHorizonTweener.update(dt);
  sDiagTweener.update(dt);
  sArmsTweener.update(dt);
  sRingsTweener.update(dt);
  sSpiralTweener.update(dt);
  vertSpeedTweener.update(dt);
  horizonSpeedTweener.update(dt);
  diagSpeedTweener.update(dt);
  armSpeedTweener.update(dt);
  ringSpeedTweener.update(dt);
  spiralSpeedTweener.update(dt);
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
  syphonOutput.publishScreen();
}

//--------------------------------------------------------------
void testApp::keyPressed(int key){
  if(key == '1') {
    if(!sVertTweener.isRunning()) {
      bVert = !bVert;
      sVertTweener.init(2.f);
      sVertTweener.add(&sVert, (bVert ? 1.f : -1.f));
      sVertTweener.start();
    }
  }
  if(key == '2') {
    if(!sHorizonTweener.isRunning()) {
      bHorizon = !bHorizon;
      sHorizonTweener.init(2.f);
      sHorizonTweener.add(&sHorizon, (bHorizon ? 1.f : -1.f));
      sHorizonTweener.start();
    }
  }
  if(key == '3') {
    if(!sDiagTweener.isRunning()) {
      bDiag = !bDiag;
      sDiagTweener.init(2.f);
      sDiagTweener.add(&sDiag, (bDiag ? 1.f : -1.f));
      sDiagTweener.start();
    }
  }
  if(key == '4') {
    if(!sArmsTweener.isRunning()) {
      bArms = !bArms;
      sArmsTweener.init(2.f);
      sArmsTweener.add(&sArms, (bArms ? 1.f : -1.f));
      sArmsTweener.start();
    }
  }
  if(key == '5') {
    if(!sRingsTweener.isRunning()) {
      bRings = !bRings;
      sRingsTweener.init(2.f);
      sRingsTweener.add(&sRings, (bRings ? 1.f : -1.f));
      sRingsTweener.start();
    }
  }
  if(key == '6') {
    if(!sSpiralTweener.isRunning()) {
      bSpiral = !bSpiral;
      sSpiralTweener.init(2.f);
      sSpiralTweener.add(&sSpiral, (bSpiral ? 1.f : -1.f));
      sSpiralTweener.start();
    }
  }
  if(key == 'q') {
    if(!vertSpeedTweener.isRunning()) {
      float target = vertSpeed + deltaSpeed;
      vertSpeedTweener.init(2.f);
      vertSpeedTweener.add(&vertSpeed, 1.0);
      vertSpeedTweener.start();
    }
  }
  if (key == 'Q') {
    if(!vertSpeedTweener.isRunning()) {
      float target = vertSpeed - deltaSpeed;
      vertSpeedTweener.init(2.f);
      vertSpeedTweener.add(&vertSpeed, target);
      vertSpeedTweener.start();
    }
  }
  if(key == 'w') {
    if(!horizonSpeedTweener.isRunning()) {
      float target = horizonSpeed + deltaSpeed;
      horizonSpeedTweener.init(2.f);
      horizonSpeedTweener.add(&horizonSpeed, target);
      horizonSpeedTweener.start();
    }
  }
  if (key == 'W') {
    if(!horizonSpeedTweener.isRunning()) {
      float target = horizonSpeed - deltaSpeed;
      horizonSpeedTweener.init(2.f);
      horizonSpeedTweener.add(&horizonSpeed, target);
      horizonSpeedTweener.start();
    }
  }
  if(key == 'e') {
    if(!diagSpeedTweener.isRunning()) {
      float target = diagSpeed + deltaSpeed;
      diagSpeedTweener.init(2.f);
      diagSpeedTweener.add(&diagSpeed, target);
      diagSpeedTweener.start();
    }
  }
  if (key == 'E') {
    if(!diagSpeedTweener.isRunning()) {
      float target = diagSpeed - deltaSpeed;
      diagSpeedTweener.init(2.f);
      diagSpeedTweener.add(&diagSpeed, target);
      diagSpeedTweener.start();
    }
  }
  if(key == 'r') {
    if(!diagSpeedTweener.isRunning()) {
      float target = armSpeed + deltaSpeed;
      armSpeedTweener.init(2.f);
      armSpeedTweener.add(&armSpeed, target);
      armSpeedTweener.start();
    }
  }
  if (key == 'R') {
    if(!armSpeedTweener.isRunning()) {
      float target = armSpeed - deltaSpeed;
      armSpeedTweener.init(2.f);
      armSpeedTweener.add(&armSpeed, target);
      armSpeedTweener.start();
    }
  }
  if(key == 't') {
    if(!armSpeedTweener.isRunning()) {
      float target = ringSpeed + deltaSpeed;
      ringSpeedTweener.init(2.f);
      ringSpeedTweener.add(&ringSpeed, target);
      ringSpeedTweener.start();
    }
  }
  if (key == 'T') {
    if(!ringSpeedTweener.isRunning()) {
      float target = ringSpeed - deltaSpeed;
      ringSpeedTweener.init(2.f);
      ringSpeedTweener.add(&ringSpeed, target);
      ringSpeedTweener.start();
    }
  }
  if(key == 'y') {
    if(!spiralSpeedTweener.isRunning()) {
      float target = spiralSpeed + deltaSpeed;
      spiralSpeedTweener.init(2.f);
      spiralSpeedTweener.add(&spiralSpeed, target);
      spiralSpeedTweener.start();
    }
  }
  if (key == 'Y') {
    if(!spiralSpeedTweener.isRunning()) {
      float target = spiralSpeed - deltaSpeed;
      spiralSpeedTweener.init(2.f);
      spiralSpeedTweener.add(&spiralSpeed, target);
      spiralSpeedTweener.start();
    }
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
    numSpiral++;
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
  float time = ofGetFrameNum();

  shader.setUniform1f("time",time);
  shader.setUniform2fv("resolution",resolution);

  //flags for turning patterns on/off
  shader.setUniform1i("bVert", true);
  shader.setUniform1i("bHorizon", true);
  shader.setUniform1i("bDiag", true);
  shader.setUniform1i("bArms", true);
  shader.setUniform1i("bRings", true);
  shader.setUniform1i("bSpiral", true);

  //scalars for tweening
  shader.setUniform1f("sVert", sVert);
  shader.setUniform1f("sHorizon", sHorizon);
  shader.setUniform1f("sDiag", sDiag);
  shader.setUniform1f("sArms", sArms);
  shader.setUniform1f("sRings", sRings);
  shader.setUniform1f("sSpiral", sSpiral);
  
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
