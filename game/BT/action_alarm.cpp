#include "stdafx.h"

#include "action_alarm.h"
#include "character.h"

CActionAlarm::CActionAlarm(Character * owner, float targetTime): CBehaviour(owner),
m_alarmTime(0.f), m_targetAlarmTime(targetTime) {

}

void CActionAlarm::Reset() {

}

EBehaviourStatus CActionAlarm::Update(float deltaTime) {
	if (!GetOwner()->IsMoving()) {
		m_alarmTime += deltaTime;
		if (m_alarmTime >= m_targetAlarmTime) {
			return EBS_SUCCESS;
		} else return EBS_RUNNING;
	}
}

void CActionAlarm::OnEnter() {

}

void CActionAlarm::OnExit() {
	m_alarmTime = 0.f;
}
