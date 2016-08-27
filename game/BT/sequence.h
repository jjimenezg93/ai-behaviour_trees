#ifndef _BT_SEQUENCE_H_
#define _BT_SEQUENCE_H_

#include <vector>
#include "group.h"

class CSequence: public CGroup {
public:

protected:
	virtual EBehaviourStatus Update();
	virtual void OnEnter();
	virtual void OnExit();
private:
	std::vector<CBehaviour *>::const_iterator m_currentChild;
};

#endif//!_BT_SEQUENCE_H_