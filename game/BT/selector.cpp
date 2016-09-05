#include "stdafx.h"

#include <vector>
#include "selector.h"

CSelector::CSelector(Character * owner): CGroup(owner) {}

EBehaviourStatus CSelector::Update() {
	EBehaviourStatus status;
	while (1) {
		status = (*m_currentChild)->Tick();

		if (status != EBS_FAIL) {
			return status;
		}

		m_currentChild++;

		if (m_currentChild == GetChildren().end()) {
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
