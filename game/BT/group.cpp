#include "stdafx.h"

#include "group.h"

CGroup::CGroup(Character * owner): CBehaviour(owner) {}

void CGroup::AddChild(CBehaviour *child, int16_t pos) {
	if (pos == -1) {
		m_children.insert(m_children.end(), child);
	} else {
		std::vector<CBehaviour *>::iterator it = m_children.begin() + pos;
		m_children.insert(it, child);
	}
}

const std::vector<CBehaviour *>& CGroup::GetChildren() const {
	return m_children;
}

void CGroup::OnExit() {
	for (std::vector<CBehaviour *>::iterator itr = m_children.begin(); itr != m_children.end();
	++itr) {
		(*itr)->Reset();
	}
}
