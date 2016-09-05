#ifndef _ACTION_CHANGE_IMAGE_H_
#define _ACTION_CHANGE_IMAGE_H_

#include "behaviour.h"

class CActionChangeImage: public CBehaviour {
public:
	CActionChangeImage(Character * owner, uint16_t imageID);
protected:
	virtual void OnEnter();
	virtual EBehaviourStatus Update();
	virtual void Reset() {}
private:
	uint16_t m_targetImageID;
	EBehaviourStatus m_localStatus;
};

#endif//!_ACTION_CHANGE_IMAGE_H_