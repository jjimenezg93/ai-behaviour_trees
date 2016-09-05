#include "stdafx.h"

#include <vector>
#include "sequence.h"

CSequence::CSequence(Character * owner): CGroup(owner) {}

EBehaviourStatus CSequence::Update() {
	EBehaviourStatus status;
	while (1) {
		status = (*m_currentChild)->Tick();

		if (status != EBS_SUCCESS) {
			OnExit();
			return status;
		}

		m_currentChild++;

		if (m_currentChild == GetChildren().end()) {
			OnExit();
			return EBS_SUCCESS;
		}
	}
}

void CSequence::OnEnter() {
	m_currentChild = GetChildren().begin();
}

void CSequence::OnExit() {
	CGroup::OnExit();
	m_currentChild = GetChildren().begin();
}

void CSequence::Reset() {
	CBehaviour::Reset();
	m_currentChild = GetChildren().begin();
}
