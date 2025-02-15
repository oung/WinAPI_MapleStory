#pragma once
#include "GameObject.h"

class Animation;
class Animator;
class SolunaDivideEffect;
class SolunaDivideBG;

class SolunaDivideStart : public GameObject
{
public:
	SolunaDivideStart();
	~SolunaDivideStart();

	virtual void Initialize() override;
	virtual void Update() override;
	virtual void Render(HDC hdc) override;
	virtual void Release() override;

private:
	Animator* m_Animator;
	SolunaDivideEffect* Effect;
	float mTime;

	void Loop();
	void End();

};

