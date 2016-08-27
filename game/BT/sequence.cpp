#include "stdafx.h"

#include <vector>
#include "sequence.h"

EBehaviourStatus CSequence::Update() {
	EBehaviourStatus status;
	while (1) {
		status = (*m_currentChild)->Tick();

		if (status != EBS_SUCCESS) {
			return status;
		}

		m_currentChild++;

		if (m_currentChild == GetChildren().end()) {
			return EBS_SUCCESS;
		}
	}
}

void CSequence::OnEnter() {
	m_currentChild = GetChildren().begin();
}

void CSequence::OnExit() {

}
