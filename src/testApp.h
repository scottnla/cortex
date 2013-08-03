#pragma once

#include "ofMain.h"
#include "tweener.h"
#include "ofxSyphon.h"

static const float SPEED_DEFAULT = 4.0f;
static const float SPEED_TWEEN_TIME = 0.5f;
static const float SPEED_DELTA = 2.0f;
static const float TOGGLE_TWEEN_TIME = 2.0f;

class testApp : public ofBaseApp{
 public:
  void setup();
  void update();
  void draw();
  
  void keyPressed(int key);
  void keyReleased(int key);
  void mouseMoved(int x, int y);
  void mouseDragged(int x, int y, int button);
  void mousePressed(int x, int y, int button);
  void mouseReleased(int x, int y, int button);
  void windowResized(int w, int h);
  void dragEvent(ofDragInfo dragInfo);
  void gotMessage(ofMessage msg);
  void setUniforms();

 private:
  ofShader shader;
  ofFbo fbo;
  float width, height;
  float deltaSpeed;
  int bVert, bHorizon, bDiag, bArms, bRings, bSpiral;
  float sVert, sHorizon, sDiag, sArms, sRings, sSpiral;
  float vertSpeed, horizonSpeed, diagSpeed, armSpeed, ringSpeed, spiralSpeed;
  float vertPeriod, horizonPeriod, diagPeriod, armPeriod, ringPeriod, spiralPeriod;
  float numVert, numHorizon, numDiag, numRings, numArms, numSpiral;
  float vertSign, horizonSign, diagSign, armSign, ringSign, spiralSign;
    
  Tweener sVertTweener, sHorizonTweener, sDiagTweener, sArmsTweener, sRingsTweener, sSpiralTweener, vertSpeedTweener, horizonSpeedTweener, diagSpeedTweener, armSpeedTweener, ringSpeedTweener, spiralSpeedTweener, numSpiralTweener;
    
    ofxSyphonClient syphonClient;
    ofxSyphonServer syphonOutput;
};
