//
//  tweener.h
//  cortex
//
//  Created by dzog on 7/28/13.
//
//

#ifndef __cortex__tweener__
#define __cortex__tweener__

#include <vector>

using namespace std;

enum TweenerState {
    INIT,
    RUNNING,
    FINISHED
};

struct Tween {
    float* var;
    float tdv; //target delta value
    float iValue; //initial value
    float pDelta;
};

class Tweener {
public:
    Tweener();
    void add(float* var, float dv);
    void init(float duration);
    void start();
    void update(float dt);
    int isFinished();
    int isRunning();
private:
    TweenerState state;
    vector<Tween*> tweens;
    float duration;
    float cTime;
    void finish();
};

#endif /* defined(__cortex__tweener__) */
