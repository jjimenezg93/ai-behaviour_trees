#include "stdafx.h"

#include "action_movetotarget.h"
#include "character.h"

#define DIST_THRESHOLD 2

CActionMoveToTarget::CActionMoveToTarget(Character * owner): CBehaviour(owner) {}

void CActionMoveToTarget::OnEnter() {
	if (abs((static_cast<USVec2D>(GetOwner()->GetLoc()) - GetOwner()->GetTarget()).Length()) > DIST_THRESHOLD) {
		GetOwner()->SetCanMove(true);
		GetOwner()->SetIsMoving(true);
	}
}

void CActionMoveToTarget::Reset() {

}

EBehaviourStatus CActionMoveToTarget::Update(float deltaTime) {
	USVec2D targetPos = GetOwner()->GetTarget();
	USVec2D chPos = static_cast<USVec2D>(GetOwner()->GetLoc());
	USVec2D distVec = chPos - targetPos;
	float dist = abs(distVec.Length());
	if (dist < DIST_THRESHOLD) {
		GetOwner()->SetCanMove(false);
		GetOwner()->SetIsTargetActive(false);
		GetOwner()->SetIsMoving(false);
		return EBS_SUCCESS;
	} else if (GetOwner()->CanMove()){
		return EBS_RUNNING;
	} else {
		return EBS_FAIL;
	}
}

void CActionMoveToTarget::OnExit() {

}
