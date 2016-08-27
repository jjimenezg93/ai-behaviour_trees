#include "stdafx.h"

#include "group.h"

const std::vector<CBehaviour *>& CGroup::GetChildren() const {
	return m_children;
}

