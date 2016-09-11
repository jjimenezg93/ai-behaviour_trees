#include "stdafx.h"

#include <vector>
#include "selector.h"

CSelector::CSelector(Character * owner): CGroup(owner) {}

EBehaviourStatus CSelector::Update(float deltaTime) {
	EBehaviourStatus status;
	while (1) {
		status = (*m_currentChild)->Tick(deltaTime);

		if (status != EBS_FAIL) {
			OnExit();
			return status;
		}

		m_currentChild++;

		if (m_currentChild == GetChildren().end()) {
			OnExit();
			return EBS_FAIL;
		}
	}
}

void CSelector::OnEnter() {
	m_currentChild = GetChildren().begin();
}

void CSelector::OnExit() {
	CGroup::OnExit();
	m_currentChild = GetChildren().begin();
}

void CSelector::Reset() {
	CBehaviour::Reset();
	m_currentChild = GetChildren().begin();
}
