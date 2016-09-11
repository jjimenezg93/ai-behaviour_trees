#include "stdafx.h"

#include "behaviour.h"
#include "character.h"

CBehaviour::CBehaviour(Character * owner): m_owner(owner), m_status(EBS_INVALID) {}

EBehaviourStatus CBehaviour::Tick(float deltaTime) {
	if (m_status == EBS_INVALID) {
		OnEnter();
	}

	m_status = Update(deltaTime);

	if (m_status != EBS_RUNNING) {
		OnExit();
	}
	
	return m_status;
}

Character * CBehaviour::GetOwner() const {
	return m_owner;
}

//overriden if necessary, leads to OnExit() inside Tick() if not
EBehaviourStatus CBehaviour::Update(float deltaTime) {
	return EBehaviourStatus::EBS_SUCCESS;
}

void CBehaviour::OnEnter() {

}

void CBehaviour::OnExit() {

}

void CBehaviour::Reset() {
	m_status = EBS_INVALID;
}
