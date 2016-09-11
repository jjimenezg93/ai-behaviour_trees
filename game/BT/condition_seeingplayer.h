#ifndef _CONDITION_SEEING_PLAYER_H_
#define _CONDITION_SEEING_PLAYER_H_

#include "behaviour.h"

class CConditionSeeingPlayer: public CBehaviour {
public:
	CConditionSeeingPlayer(Character * owner);
protected:
	virtual void OnEnter() override;
	virtual EBehaviourStatus Update(float deltaTime) override;
private:
	EBehaviourStatus m_conditionResult;
};

#endif//!_CONDITION_SEEING_PLAYER_H_