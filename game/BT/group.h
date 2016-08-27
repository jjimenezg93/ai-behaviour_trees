#ifndef _BT_GROUP_H_
#define _BT_GROUP_H_

#include <vector>
#include "behaviour.h"

class CGroup: public CBehaviour {
public:
protected:
	const std::vector<CBehaviour *>& GetChildren() const;
private:
	std::vector<CBehaviour *> m_children;
};

#endif//!_BT_GROUP_H_