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

  bVert = 0;
  bHorizon = 0;
  bDiag = 0;
  bDiagAlt = 0;
  bArms = 0;
  bRings = 0;
  bSpiral = 0;
  
  sVert = 0;
  sHorizon = 0;
  sDiag = 0;
  sDiagAlt = 0;
  sArms = 0;
  sRings = 0;
  sSpiral = 0;
  
  vertSpeed = SPEED_DEFAULT;
  horizonSpeed = SPEED_DEFAULT;
  diagSpeed = SPEED_DEFAULT;
  diagAltSpeed = SPEED_DEFAULT;
  armSpeed = SPEED_DEFAULT;
  ringSpeed = SPEED_DEFAULT;
  spiralSpeed = SPEED_DEFAULT;
  
  vertPeriod = 0;
  horizonPeriod = 0;
  diagPeriod = 0;
  diagAltPeriod = 0;
  armPeriod = 0;
  ringPeriod = 0;
  spiralPeriod = 0;
  
  numVert = 96.0;
  numHorizon = 96.0;
  numDiag = 48.0;
  numDiagAlt = 48.0;
  numRings = 12.0;
  numArms = 3;
  numSpiral = 3;
  
  vertSign = 1;
  horizonSign = 1;
  diagSign = 1;
  diagAltSign = 1;
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
  sDiagAltTweener.update(dt);
  sArmsTweener.update(dt);
  sRingsTweener.update(dt);
  sSpiralTweener.update(dt);
  vertSpeedTweener.update(dt);
  horizonSpeedTweener.update(dt);
  diagSpeedTweener.update(dt);
  diagAltSpeedTweener.update(dt);
  armSpeedTweener.update(dt);
  ringSpeedTweener.update(dt);
  spiralSpeedTweener.update(dt);
  spiralSignTweener.update(dt);
    
  numVertTweener.update(dt);
    numHorizonTweener.update(dt);
    numDiagTweener.update(dt);
    numDiagAltTweener.update(dt);
    numArmsTweener.update(dt);
    numRingsTweener.update(dt);
  numSpiralTweener.update(dt);
  
  vertPeriod += vertSpeed*dt;
  horizonPeriod += horizonSpeed*dt;
  diagPeriod += diagSpeed*dt;
  diagAltPeriod += diagAltSpeed*dt;
  armPeriod += armSpeed*dt;
  ringPeriod += ringSpeed*dt;
  spiralPeriod += spiralSpeed*dt;
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
      sVertTweener.init(TOGGLE_TWEEN_TIME);
      sVertTweener.add(&sVert, (bVert ? 1.f : -1.f));
      sVertTweener.start();
    }
  }
  if(key == '2') {
    if(!sHorizonTweener.isRunning()) {
      bHorizon = !bHorizon;
      sHorizonTweener.init(TOGGLE_TWEEN_TIME);
      sHorizonTweener.add(&sHorizon, (bHorizon ? 1.f : -1.f));
      sHorizonTweener.start();
    }
  }
  if(key == '3') {
    if(!sDiagTweener.isRunning()) {
      bDiag = !bDiag;
      sDiagTweener.init(TOGGLE_TWEEN_TIME);
      sDiagTweener.add(&sDiag, (bDiag ? 1.f : -1.f));
      sDiagTweener.start();
    }
  }
  if(key == '4') {
    if(!sDiagAltTweener.isRunning()) {
      bDiagAlt = !bDiagAlt;
      sDiagAltTweener.init(TOGGLE_TWEEN_TIME);
      sDiagAltTweener.add(&sDiagAlt, (bDiagAlt ? 1.f : -1.f));
      sDiagAltTweener.start();
    }
  }
  if(key == '5') {
    if(!sArmsTweener.isRunning()) {
      bArms = !bArms;
      sArmsTweener.init(TOGGLE_TWEEN_TIME);
      sArmsTweener.add(&sArms, (bArms ? 1.f : -1.f));
      sArmsTweener.start();
    }
  }
  if(key == '6') {
    if(!sRingsTweener.isRunning()) {
      bRings = !bRings;
      sRingsTweener.init(TOGGLE_TWEEN_TIME);
      sRingsTweener.add(&sRings, (bRings ? 1.f : -1.f));
      sRingsTweener.start();
    }
  }
  if(key == '7') {
    if(!sSpiralTweener.isRunning()) {
      bSpiral = !bSpiral;
      sSpiralTweener.init(TOGGLE_TWEEN_TIME);
      sSpiralTweener.add(&sSpiral, (bSpiral ? 1.f : -1.f));
      sSpiralTweener.start();
    }
  }
  if(key == 'q') {
    if(!vertSpeedTweener.isRunning()) {
      vertSpeedTweener.init(SPEED_TWEEN_TIME);
      vertSpeedTweener.add(&vertSpeed, SPEED_DELTA);
      vertSpeedTweener.start();
    }
  }
  if (key == 'Q') {
    if(!vertSpeedTweener.isRunning()) {
      vertSpeedTweener.init(SPEED_TWEEN_TIME);
      vertSpeedTweener.add(&vertSpeed, -SPEED_DELTA);
      vertSpeedTweener.start();
    }
  }
  if(key == 'w') {
    if(!horizonSpeedTweener.isRunning()) {
      horizonSpeedTweener.init(SPEED_TWEEN_TIME);
      horizonSpeedTweener.add(&horizonSpeed, SPEED_DELTA);
      horizonSpeedTweener.start();
    }
  }
  if (key == 'W') {
    if(!horizonSpeedTweener.isRunning()) {
      horizonSpeedTweener.init(SPEED_TWEEN_TIME);
      horizonSpeedTweener.add(&horizonSpeed, -SPEED_DELTA);
      horizonSpeedTweener.start();
    }
  }
  if(key == 'e') {
    if(!diagSpeedTweener.isRunning()) {
      diagSpeedTweener.init(SPEED_TWEEN_TIME);
      diagSpeedTweener.add(&diagSpeed, SPEED_DELTA);
      diagSpeedTweener.start();
    }
  }
  if (key == 'E') {
    if(!diagSpeedTweener.isRunning()) {
      diagSpeedTweener.init(SPEED_TWEEN_TIME);
      diagSpeedTweener.add(&diagSpeed, -SPEED_DELTA);
      diagSpeedTweener.start();
    }
  }
  if(key == 'r') {
    if(!diagAltSpeedTweener.isRunning()) {
      diagAltSpeedTweener.init(SPEED_TWEEN_TIME);
      diagAltSpeedTweener.add(&diagAltSpeed, SPEED_DELTA);
      diagAltSpeedTweener.start();
    }
  }
  if (key == 'R') {
    if(!diagAltSpeedTweener.isRunning()) {
      diagAltSpeedTweener.init(SPEED_TWEEN_TIME);
      diagAltSpeedTweener.add(&diagAltSpeed, -SPEED_DELTA);
      diagAltSpeedTweener.start();
    }
  }
  if(key == 't') {
    if(!diagSpeedTweener.isRunning()) {
      armSpeedTweener.init(SPEED_TWEEN_TIME);
      armSpeedTweener.add(&armSpeed, SPEED_DELTA);
      armSpeedTweener.start();
    }
  }
  if (key == 'T') {
    if(!armSpeedTweener.isRunning()) {
      armSpeedTweener.init(SPEED_TWEEN_TIME);
      armSpeedTweener.add(&armSpeed, -SPEED_DELTA);
      armSpeedTweener.start();
    }
  }
  if(key == 'y') {
    if(!armSpeedTweener.isRunning()) {
      ringSpeedTweener.init(SPEED_TWEEN_TIME);
      ringSpeedTweener.add(&ringSpeed, SPEED_DELTA);
      ringSpeedTweener.start();
    }
  }
  if (key == 'Y') {
    if(!ringSpeedTweener.isRunning()) {
      ringSpeedTweener.init(SPEED_TWEEN_TIME);
      ringSpeedTweener.add(&ringSpeed, -SPEED_DELTA);
      ringSpeedTweener.start();
    }
  }
  if(key == 'u') {
    if(!spiralSpeedTweener.isRunning()) {
      spiralSpeedTweener.init(SPEED_TWEEN_TIME);
      spiralSpeedTweener.add(&spiralSpeed, SPEED_DELTA);
      spiralSpeedTweener.start();
    }
  }
  if (key == 'U') {
    if(!spiralSpeedTweener.isRunning()) {
      spiralSpeedTweener.init(SPEED_TWEEN_TIME);
      spiralSpeedTweener.add(&spiralSpeed, -SPEED_DELTA);
      spiralSpeedTweener.start();
    }
  }
    if(key == 'a') {
        numVert += 4.0;
        if(!numVertTweener.isRunning()) {
            numVertTweener.init(SPEED_TWEEN_TIME);
            numVertTweener.add(&numVert , 4.f);
            numVertTweener.start();
        }
    }
    if(key == 'A') {
        numVert -= 4.0;
        if(!numVertTweener.isRunning()) {
            numVertTweener.init(SPEED_TWEEN_TIME);
            numVertTweener.add(&numVert , -4.f);
            numVertTweener.start();
        }
    }
    if(key == 's') {
        numHorizon += 4.0;
        if(!numHorizonTweener.isRunning()) {
            numHorizonTweener.init(SPEED_TWEEN_TIME);
            numHorizonTweener.add(&numHorizon, 4.f);
            numHorizonTweener.start();
        }
    }
    if (key == 'S') {
        numHorizon -= 4.0;
        if(!numHorizonTweener.isRunning()) {
            numHorizonTweener.init(SPEED_TWEEN_TIME);
            numHorizonTweener.add(&numHorizon, -4.f);
            numHorizonTweener.start();
        }
    }
    if(key == 'd') {
        numDiag += 4.0;
        if(!numDiagTweener.isRunning()) {
            numDiagTweener.init(SPEED_TWEEN_TIME);
            numDiagTweener.add(&numDiag, 4.f);
            numDiagTweener.start();
        }
    }
    if (key == 'D') {
        numDiag -= 4.0;
        if(!numDiagTweener.isRunning()) {
            numDiagTweener.init(SPEED_TWEEN_TIME);
            numDiagTweener.add(&numDiag, -4.f);
            numDiagTweener.start();
        }
    }
  if(key == 'f') {
      numDiagAlt += 4.0;
      if(!numDiagAltTweener.isRunning()) {
          numDiagAltTweener.init(SPEED_TWEEN_TIME);
          numDiagAltTweener.add(&numDiagAlt, 4.f);
          numDiagAltTweener.start();
      }
  }
  if (key == 'F') {
      numDiagAlt -= 4.0;
      if(!numDiagAltTweener.isRunning()) {
          numDiagAltTweener.init(SPEED_TWEEN_TIME);
          numDiagAltTweener.add(&numDiagAlt, -4.f);
          numDiagAltTweener.start();
      }
  }
  if(key == 'g') {
      numArms += 1;
      if(!numArmsTweener.isRunning()) {
          numArmsTweener.init(SPEED_TWEEN_TIME);
          numArmsTweener.add(&numArms, 1.f);
          numArmsTweener.start();
      }
  }
  if (key == 'G') {
      numArms -= 1;
      if(!numArmsTweener.isRunning()) {
          numArmsTweener.init(SPEED_TWEEN_TIME);
          numArmsTweener.add(&numArms, -1.f);
          numArmsTweener.start();
      }
  }
  if(key == 'h') {
      numRings += 1;
      if(!numRingsTweener.isRunning()) {
          numRingsTweener.init(SPEED_TWEEN_TIME);
          numRingsTweener.add(&numRings, 1.f);
          numRingsTweener.start();
      }
  }
  if (key == 'H') {
      numRings -= 1;
      if(!numRingsTweener.isRunning()) {
          numRingsTweener.init(SPEED_TWEEN_TIME);
          numRingsTweener.add(&numRings, -1.f);
          numRingsTweener.start();
      }
  }
  if (key == 'j') {
      numSpiral += 1;
      if(!numSpiralTweener.isRunning()) {
          numSpiralTweener.init(SPEED_TWEEN_TIME);
          numSpiralTweener.add(&numSpiral, 1.f);
          numSpiralTweener.start();
      }
  }
  if (key == 'J') {
      numSpiral -= 1;
      if(!numSpiralTweener.isRunning()) {
          numSpiralTweener.init(SPEED_TWEEN_TIME);
          numSpiralTweener.add(&numSpiral, -1.f);
          numSpiralTweener.start();
      }
  }
  if (key == 'z') {
    vertSign *= -1.0;
  }
  if (key == 'x') {
    horizonSign *= -1.0;
  }
  if (key == 'c') {
    diagSign *= -1.0;
  }
  if (key == 'v') {
    diagAltSign *= -1.0;
  }
  if (key == 'b') {
    armSign *= -1.0;
  }
  if (key == 'n') {
    ringSign *= -1.0;
  }
  if (key == 'm') {
      if(!spiralSignTweener.isRunning()) {
          spiralSign *= -1.0;
          spiralSignTweener.init(TOGGLE_TWEEN_TIME);
          spiralSignTweener.add(&spiralSign, spiralSign);
          spiralSignTweener.start();
      }
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
  shader.setUniform1i("bVert", true);
  shader.setUniform1i("bHorizon", true);
  shader.setUniform1i("bDiag", true);
  shader.setUniform1i("bDiagAlt", true);
  shader.setUniform1i("bArms", true);
  shader.setUniform1i("bRings", true);
  shader.setUniform1i("bSpiral", true);

  //scalars for tweening
  shader.setUniform1f("sVert", sVert);
  shader.setUniform1f("sHorizon", sHorizon);
  shader.setUniform1f("sDiag", sDiag);
  shader.setUniform1f("sDiagAlt", sDiagAlt);
  shader.setUniform1f("sArms", sArms);
  shader.setUniform1f("sRings", sRings);
  shader.setUniform1f("sSpiral", sSpiral);
  
  //pattern periods
  shader.setUniform1f("vertPeriod", vertPeriod);
  shader.setUniform1f("horizonPeriod", horizonPeriod);
  shader.setUniform1f("diagPeriod", diagPeriod);
  shader.setUniform1f("diagAltPeriod", diagAltPeriod);
  shader.setUniform1f("armPeriod", armPeriod);
  shader.setUniform1f("ringPeriod", ringPeriod);
  shader.setUniform1f("spiralPeriod", spiralPeriod);

  //pattern parameters
  shader.setUniform1f("numVert", numVert);
  shader.setUniform1f("numHorizon", numHorizon);
  shader.setUniform1f("numDiag", numDiag);
  shader.setUniform1f("numDiagAlt", numDiagAlt);
  shader.setUniform1f("numArms", numArms);
  shader.setUniform1f("numRings", numRings);
  shader.setUniform1f("numSpiral", numSpiral);
  
  //direction parameters
  shader.setUniform1f("vertSign", vertSign);
  shader.setUniform1f("horizonSign", horizonSign);
  shader.setUniform1f("diagSign", diagSign);
  shader.setUniform1f("diagAltSign", diagAltSign);
  shader.setUniform1f("armSign", armSign);
  shader.setUniform1f("ringSign", ringSign);
  shader.setUniform1f("spiralSign", spiralSign);
}
