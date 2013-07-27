#pragma once

#include "ofMain.h"

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
  int bVert, bHorizon, bDiag, bArms, bRings, bSpiral;
  float vertSpeed, horizonSpeed, diagSpeed, armSpeed, ringSpeed, spiralSpeed;
  float numVert, numHorizon, numDiag, numRings;
  int numArms, numSpiral;
  float vertSign, horizonSign, diagSign, armSign, ringSign, spiralSign;
};
