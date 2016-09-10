#ifndef _ACTION_MOVE_TO_TARGET_H_
#define _ACTION_MOVE_TO_TARGET_H_

#include "behaviour.h"

class CActionMoveToTarget: public CBehaviour {
public:
	CActionMoveToTarget(Character * owner);
protected:
	virtual void OnEnter();
	virtual EBehaviourStatus Update();
private:
};

#endif//!_ACTION_MOVE_TO_TARGET_H_