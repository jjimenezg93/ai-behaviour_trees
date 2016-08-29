#ifndef _BT_BEHAVIOUR_H_
#define _BT_BEHAVIOUR_H_

class Character;

enum EBehaviourStatus {
	EBS_INVALID,
	EBS_FAIL,
	EBS_SUCCESS,
	EBS_RUNNING
};

class CBehaviour {
public:
	CBehaviour(Character * owner);

	EBehaviourStatus Tick();
protected:
	Character * GetOwner() const;

	virtual EBehaviourStatus Update();
	virtual void OnEnter();
	virtual void OnExit();
private:
	Character * m_owner;

	EBehaviourStatus m_status;
};

#endif//!_BT_BEHAVIOUR_H_