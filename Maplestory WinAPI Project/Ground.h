#pragma once
#include "GameObject.h"

class Collider;

class Ground : public GameObject
{
public:
	Ground();
	virtual ~Ground();

	virtual void Initialize();
	virtual void Update();
	virtual void Render(HDC hdc);
	virtual void Release();

	virtual void OnCollisionEnter(class Collider* other);
	virtual void OnCollisionStay(class Collider* other);
	virtual void OnCollisionExit(class Collider* other);


private:
	//class Collider* mCollider;
	//class Collider* collider;


};

