#include "stdafx.h"

#include "behaviour.h"
#include "character.h"

CBehaviour::CBehaviour(Character * owner): m_owner(owner), m_status(EBS_INVALID) {}

EBehaviourStatus CBehaviour::Tick() {
	if (m_status == EBS_INVALID) {
		OnEnter();
	}

	m_status = Update();

	if (m_status != EBS_RUNNING) {
		OnExit();
	}

	return m_status;
}

Character * CBehaviour::GetOwner() const {
	return m_owner;
}

EBehaviourStatus CBehaviour::Update() {
	return EBehaviourStatus::EBS_SUCCESS;
}

void CBehaviour::OnEnter() {

}

void CBehaviour::OnExit() {

}
