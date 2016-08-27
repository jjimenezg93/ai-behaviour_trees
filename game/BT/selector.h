#ifndef _BT_SELECTOR_H_
#define _BT_SELECTOR_H_

#include <vector>
#include "group.h"

class CSelector: public CGroup {
public:

protected:
	virtual EBehaviourStatus Update();
	virtual void OnEnter();
	virtual void OnExit();
private:
	std::vector<CBehaviour *>::const_iterator m_currentChild;
};

#endif//!_BT_SELECTOR_H_