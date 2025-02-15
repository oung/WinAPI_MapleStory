#include "Ground.h"
#include "Collider.h"
#include "MainChar.h"
#include "Rigidbody.h"
#include "Transform.h"
#include "mushroom.h"

Ground::Ground()
{
}

Ground::~Ground()
{
}

void Ground::Initialize()
{
	Collider* collider = AddComponent<Collider>();
	collider->SetSize(Vector2(1700.0f, 50.0f));
	collider->SetCenter(Vector2(0.0f, 0.0f));
	GameObject::Initialize();
}

void Ground::Update()
{
	GameObject::Update();
}

void Ground::Render(HDC hdc)
{
	GameObject::Render(hdc);
}

void Ground::Release()
{
	GameObject::Release();
}

void Ground::OnCollisionEnter(Collider* other)
{
	MainChar* mainchar = dynamic_cast<MainChar*>(other->GetOwner());
	if (mainchar == nullptr) 
		return;

	//부딪히면 걸림
	Rigidbody* crb = mainchar->GetComponent<Rigidbody>();
	crb->SetGround(true);

	Collider* maincharCol = mainchar->GetComponent<Collider>();
	Vector2 maincharPos = maincharCol->GetPos();

	Collider* groundCol = this->GetComponent<Collider>();
	Vector2 groundPos = groundCol->GetPos();

	float fLen = fabs((maincharPos.y + 10.0f) - groundPos.y); //들어간 깊이  = 플레이어 위치 - 그라운드 깊이
	float fSize = (maincharCol->GetSize().y / 2.0f) + (groundCol->GetSize().y / 2.0f);
	
	//파고 들어가면 그라운드의 Y값으로 캐릭터 포지션 변경
	//if (fLen < fSize) //길이가 실제 사이즈보다 작다면
	//{
	//	Transform* mainTr = mainchar->GetComponent<Transform>();
	//	Transform* grTr = this->GetComponent<Transform>();
	//	
	//	Vector2 mainPos = mainTr->GetPos();
	//	Vector2 grPos = grTr->GetPos();
	//	
	//	mainPos -= (fSize - fLen); -1.0f;
	//	mainTr->SetPos(mainPos);
	//}
}

void Ground::OnCollisionStay(Collider* other)
{
}

void Ground::OnCollisionExit(Collider* other)
{
	MainChar* mainchar = dynamic_cast<MainChar*>(other->GetOwner());
	if (mainchar == nullptr) 
		return;

	Rigidbody* rb = mainchar->GetComponent<Rigidbody>();
	rb->SetGround(false);
}

