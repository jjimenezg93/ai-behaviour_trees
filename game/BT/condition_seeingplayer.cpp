#include "stdafx.h"

#include "character.h"
#include "condition_seeingplayer.h"

CConditionSeeingPlayer::CConditionSeeingPlayer(Character * owner): CBehaviour(owner),
m_conditionResult(EBS_INVALID) {}

void CConditionSeeingPlayer::OnEnter() {
	if (GetOwner()->IsTargetActive())
		m_conditionResult = EBS_SUCCESS;
	else
		m_conditionResult = EBS_FAIL;
}

EBehaviourStatus CConditionSeeingPlayer::Update(float deltaTime) {
	return m_conditionResult;
}
