#include "BasicSkill.h"
#include "Transform.h"
#include "Time.h"
#include "Animator.h"
#include "Object.h"
#include "Collider.h"
#include "Animation.h"
#include "MainChar.h"
#include "Object.h"
BasicSkill::BasicSkill()
	:mTime(0.0f)
	, posx(0)
{
}

BasicSkill::~BasicSkill()
{
}

void BasicSkill::Initialize()
{
	GameObject::Initialize();
}

void BasicSkill::Update()
{
	if(m_Animator->IsComplte())
	{
		object::Destory(this);
	}
	GameObject::Update();
}

void BasicSkill::Render(HDC hdc)
{
	GameObject::Render(hdc); //TransparentBlt����

}

void BasicSkill::Release()
{
	GameObject::Release();
}

void BasicSkill::RightAttack()
{
	Transform* pos = GetComponent<Transform>();
	m_Animator = AddComponent<Animator>();
	m_Animator->CreateAnimations(L"..\\Resources\\Skill\\BasicAttack\\BasicAttackRight", Vector2::Zero, 0.065f);
	m_Animator->Play(L"BasicAttackBasicAttackRight", false);
	Collider* collider = AddComponent<Collider>();
	collider->SetCenter(Vector2(-300.0f, -380.0f));
	collider->SetSize(Vector2(580.0f, 380.0f));
}
void BasicSkill::LeftAttack()
{
	Transform* pos = GetComponent<Transform>();
	m_Animator = AddComponent<Animator>();
	m_Animator->CreateAnimations(L"..\\Resources\\Skill\\BasicAttack\\BasicAttackLeft", Vector2::Zero, 0.065f);
	m_Animator->Play(L"BasicAttackBasicAttackLeft", false);
	Collider* collider = AddComponent<Collider>();
	collider->SetCenter(Vector2(-300.0f, -380.0f));
	collider->SetSize(Vector2(580.0f, 380.0f));
}
