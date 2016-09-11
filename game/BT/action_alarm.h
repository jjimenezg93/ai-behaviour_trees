#ifndef _ACTION_ALARM_H_
#define _ACTION_ALARM_H_

#include "behaviour.h"

class CActionAlarm: public CBehaviour {
public:
	CActionAlarm(Character * owner, float targetAlarmTime);

	virtual void Reset() override;
protected:
	virtual EBehaviourStatus Update(float deltaTime) override;

	virtual void OnEnter() override;
	virtual void OnExit() override;
private:
	float m_targetAlarmTime;
	float m_alarmTime;
};

#endif//!_ACTION_ALARM_H_