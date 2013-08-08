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
  int bVert, bHorizon, bDiag, bDiagAlt, bArms, bRings, bSpiral, bSpiralAlt;
  float sVert, sHorizon, sDiag, sDiagAlt, sArms, sRings, sSpiral, sSpiralAlt;
  float vertSpeed, horizonSpeed, diagSpeed, diagAltSpeed, armSpeed, ringSpeed, spiralSpeed, spiralAltSpeed;
  float vertPeriod, horizonPeriod, diagPeriod, diagAltPeriod, armPeriod, ringPeriod, spiralPeriod, spiralAltPeriod;
  float numVert, numHorizon, numDiag, numDiagAlt, numRings, numArms, numSpiral, numSpiralAlt;
    
  Tweener sVertTweener, sHorizonTweener, sDiagTweener, sDiagAltTweener, sArmsTweener, sRingsTweener, sSpiralTweener, sSpiralAltTweener,
    vertSpeedTweener, horizonSpeedTweener, diagSpeedTweener, diagAltSpeedTweener, armSpeedTweener, ringSpeedTweener, spiralSpeedTweener, spiralAltSpeedTweener,
    numVertTweener, numHorizonTweener, numDiagTweener, numDiagAltTweener, numRingsTweener, numArmsTweener, numSpiralTweener, numSpiralAltTweener;
    
    ofxSyphonClient syphonClient;
    ofxSyphonServer syphonOutput;
};
