#ifndef _BT_BEHAVIOUR_H_
#define _BT_BEHAVIOUR_H_

enum EBehaviourStatus {
	EBS_INVALID,
	EBS_FAIL,
	EBS_SUCCESS,
	EBS_RUNNING
};

class CBehaviour {
public:
	CBehaviour();

	EBehaviourStatus Tick();
protected:
	virtual EBehaviourStatus Update();
	virtual void OnEnter();
	virtual void OnExit();
private:
	EBehaviourStatus m_status;
};

#endif//!_BT_BEHAVIOUR_H_