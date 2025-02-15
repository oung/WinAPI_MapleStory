#include "ArcanaBack.h"
#include "SceneManager.h"
#include "Transform.h"
#include "RResources.h"
#include "Camera.h"

ArcanaBack::ArcanaBack()
{
}

ArcanaBack::~ArcanaBack()
{
}

void ArcanaBack::Initialize()
{
	mImage = RResources::Load<Image>(L"ArcanaBack", L"..\\Resources\\Map\\Arcana\\Arcana_Back.bmp");
	GameObject::Initialize();
}

void ArcanaBack::Update()
{
	GameObject::Update();

	Transform* tr = GetComponent<Transform>();
	Vector2 pos = tr->GetPos();
	tr->SetPos(pos);
}
void ArcanaBack::Render(HDC hdc)
{
	GameObject::Render(hdc);
	Transform* tr = GetComponent<Transform>();
	Vector2 pos = tr->GetPos();
	pos = Camera::CaluatePos(pos);
	BitBlt(hdc, pos.x, pos.y, mImage->GetWidth(), mImage->GetHeight(), mImage->GetHdc(), 0, 0, SRCCOPY);
}
void ArcanaBack::Release()
{
	GameObject::Release();

}