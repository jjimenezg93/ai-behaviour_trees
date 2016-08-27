#include "stdafx.h"

#include <vector>
#include "selector.h"

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

}
