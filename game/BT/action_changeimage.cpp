#include "stdafx.h"

#include "action_changeimage.h"
#include "character.h"

CActionChangeImage::CActionChangeImage(Character * owner, uint16_t imageID):
	CBehaviour(owner), m_targetImageID(imageID) {}

void CActionChangeImage::OnEnter() {
	GetOwner()->SetImage(m_targetImageID);
}
