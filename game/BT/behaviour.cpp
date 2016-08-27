#include "stdafx.h"

#include "behaviour.h"

CBehaviour::CBehaviour(): m_status(EBS_INVALID) {

}

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

EBehaviourStatus CBehaviour::Update() {
	return EBehaviourStatus::EBS_SUCCESS;
}

void CBehaviour::OnEnter() {

}

void CBehaviour::OnExit() {

}
