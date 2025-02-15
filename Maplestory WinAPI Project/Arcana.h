#pragma once
#include "Scene.h"
#include "Image.h"


class MainChar;
class ArcanaBack;
class ArcanaObject;
class waterspirit;
class Sound;

class Arcana : public Scene
{
public:
	Arcana();
	~Arcana();

	virtual void Initialize() override;
	virtual void Update() override;
	virtual void Render(HDC hdc) override;
	virtual void Release() override;

	virtual void OnEnter() override;
	virtual void OnExit() override;

	virtual MainChar* GetPlayer() override { return m_mainchar; };

private:
	MainChar* m_mainchar;
	ArcanaBack* m_arcanaback;
	ArcanaObject* m_arcanaobject;
	Sound* ArcanaSound;
	Sound* NextMap;
};

