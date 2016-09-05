#ifndef _BT_GROUP_H_
#define _BT_GROUP_H_

#include <vector>
#include "behaviour.h"

class CGroup: public CBehaviour {
public:
	CGroup(Character * owner);

	//bool AddChild(CBehaviour * child);
	void AddChild(CBehaviour * child, int16_t pos = -1);//if(pos == -1) at the end
protected:
	virtual void OnExit() override;

	const std::vector<CBehaviour *>& GetChildren() const;
private:
	std::vector<CBehaviour *> m_children;
};

#endif//!_BT_GROUP_H_