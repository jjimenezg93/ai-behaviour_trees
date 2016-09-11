#ifndef _ACTION_MOVE_TO_TARGET_H_
#define _ACTION_MOVE_TO_TARGET_H_

#include "behaviour.h"

class CActionMoveToTarget: public CBehaviour {
public:
	CActionMoveToTarget(Character * owner);

	virtual void Reset();
protected:
	virtual EBehaviourStatus Update(float deltaTime);

	virtual void OnEnter();
	virtual void OnExit();
private:

};

#endif//!_ACTION_MOVE_TO_TARGET_H_