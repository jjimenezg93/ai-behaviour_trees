#ifndef _BT_SEQUENCE_H_
#define _BT_SEQUENCE_H_

#include <vector>
#include "group.h"

class CSequence: public CGroup {
public:
	CSequence(Character * owner);

	virtual void Reset() override;
protected:
	virtual EBehaviourStatus Update() override;
	virtual void OnEnter() override;
	virtual void OnExit() override;
private:
	std::vector<CBehaviour *>::const_iterator m_currentChild;
};

#endif//!_BT_SEQUENCE_H_