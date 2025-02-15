#pragma once
#include "GameObject.h"

class Animation;
class Animator;
class Sound;

class SoulEclipseStart : public GameObject
{
public:

	SoulEclipseStart();
	~SoulEclipseStart();

	virtual void Initialize() override;
	virtual void Update() override;
	virtual void Render(HDC hdc) override;
	virtual void Release() override;

	void Start();
	void End();

private:
	void Loop();

private:
	Animator* m_Animator;
	Sound* S_SoulEclipse_Start;
	Sound* S_SoulEclipse_Loop;

	float mTime;
	bool PSound;
};

