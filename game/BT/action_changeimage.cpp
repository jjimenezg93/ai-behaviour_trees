#include "stdafx.h"

#include "action_changeimage.h"
#include "character.h"

CActionChangeImage::CActionChangeImage(Character * owner, uint16_t imageID):
	CBehaviour(owner), m_targetImageID(imageID), m_localStatus(EBS_INVALID) {}

void CActionChangeImage::OnEnter() {
	GetOwner()->SetImage(m_targetImageID);
	m_localStatus = EBS_SUCCESS;
}

EBehaviourStatus CActionChangeImage::Update(float deltaTime) {
	return m_localStatus;
}
