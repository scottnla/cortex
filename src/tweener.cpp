//
//  tweener.cpp
//  cortex
//
//  Created by dzog on 7/28/13.
//
//

#include "tweener.h"
#include <iostream>

using namespace std;

Tweener::Tweener() {
    this->duration = 2.f;
    this->cTime = 0;
    this->state = INIT;
}

void Tweener::add(float *var, float value) {
    Tween *tween = new Tween();
    tween->var = var;
    tween->tdv = value;
    tweens.push_back(tween);
}

void Tweener::init(float duration) {
    this->duration = duration;
    this->cTime = 0;
    this->state = INIT;
}

void Tweener::start() {
    this->state = RUNNING;
    for(vector<Tween*>::iterator it = tweens.begin(); it != tweens.end(); it++) {
        (*it)->pDelta = 0; //TODO unused for now
        (*it)->iValue = *((*it)->var);
    }
}

void Tweener::update(float dt) {
    if(state == RUNNING) {
        //cout << "UPDATE: " << cTime << endl;
        cTime += dt;
        if(cTime >= duration) {
            cTime = duration;
            finish();
            return;
        }
        
        for(vector<Tween*>::iterator it = tweens.begin(); it != tweens.end(); it++) {
            float delta = dt*((*it)->tdv / duration);
            //cout << "DELTA: " << delta << endl;
            *((*it)->var) += delta;
        }
    }
}

void Tweener::finish() {
    state = FINISHED;
    
    for(vector<Tween*>::iterator it = tweens.begin(); it != tweens.end(); it++) {
        *((*it)->var) = (*it)->iValue + (*it)->tdv; //assign more-accurate final value
    }
    
    int s = tweens.size();
    while(--s>=0) {
        delete tweens[0];
        tweens.erase(tweens.begin());
    }
}

int Tweener::isRunning() {
    return state == RUNNING;
}

int Tweener::isFinished() {
    return state == FINISHED;
}

