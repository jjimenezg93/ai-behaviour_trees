#ifndef __CHARACTER_H__
#define __CHARACTER_H__

#include <moaicore/MOAIEntity2D.h>
#include <params.h>

#include <vector>

enum ECharacterStates {
	ECS_IDLE,
	ECS_ALARM,
	ECS_WINDUP
};

class CSelector;
class CGroup;
class Steering;

struct Accelerations {
	Accelerations(): linearAcc(0, 0), angularAcc(0) {}
	USVec2D linearAcc;
	float angularAcc;
};

class Character: public MOAIEntity2D {
public:
	DECL_LUA_FACTORY(Character)
protected:
	virtual void OnStart();
	virtual void OnStop();
	virtual void OnUpdate(float step);
public:
	virtual void DrawDebug();

	Character();
	~Character();

	void SetLinearVelocity(float x, float y) { mLinearVelocity.mX = x; mLinearVelocity.mY = y; }
	void SetAngularVelocity(float angle) { mAngularVelocity = angle; }

	USVec2D GetLinearVelocity() const { return mLinearVelocity; }
	float GetAngularVelocity() const { return mAngularVelocity; }

	float GetArriveRadius() const { return mArriveRadius; }

	Params &GetParams() { return mParams; }

	bool IsTargetActive() const { return mIsTargetActive; }
	//also sets if can move
	void SetIsTargetActive(bool value) { mIsTargetActive = value; }

	bool CanMove() const { return mCanMove; }
	void SetCanMove(bool value) { mCanMove = value; }

	bool IsMoving() const { return mIsMoving; }
	void SetIsMoving(bool value) { mIsMoving = value; }

	USVec2D GetTarget() const { return mTarget; }
private:
	void FillPath();

	USVec2D mLinearVelocity;
	float mAngularVelocity;
	float mArriveRadius;
	USVec2D mLastLinearAcc;

	Params mParams;

	std::vector<Steering *> mSteerings;
	USVec2D mTarget;

	bool mIsTargetActive;
	bool mCanMove;

	bool mIsMoving;

	float mLastInputTime;

	//Behaviour Tree
	CGroup * m_rootBehaviour;

	// Lua configuration
public:
	virtual void RegisterLuaFuncs(MOAILuaState& state);
private:
	static int _setLinearVel(lua_State* L);
	static int _setAngularVel(lua_State* L);
	static int _setTarget(lua_State* L);
	static int _setTargetActive(lua_State* L);
};

#endif