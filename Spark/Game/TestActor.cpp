#include "TestActor.h"

#include "Spark/Utility/Config.h"

TestActor::TestActor()
	:m_speed{0}
{
}

void TestActor::OnBeginPlay()
{
	if(Config* config = GetConfig())
	{
		m_speed = config->GetValue<float>("player", "speed");
	}
}

void TestActor::OnTick(float _dt)
{
	const Vec2 Movement
	{
		static_cast<float>(IsKeyDown(KEY_D) - static_cast<float>(IsKeyDown(KEY_A))),
		static_cast<float>(IsKeyDown(KEY_S) - static_cast<float>(IsKeyDown(KEY_W)))
	};
	UpdateActorTransform(
		Mat3::CreateTransform(Movement * _dt * m_speed)
	);
	float Rotation = static_cast<float>(IsKeyDown(KEY_E)) - static_cast<float>(IsKeyDown(KEY_Q));
	SetActorRotation(GetActorRotation() + Rotation * _dt * 90.f);
}

void TestActor::OnRender()
{
	Vec2 pos = GetActorPosition();
	Vec2 scale = GetActorScale();
	float rot = GetActorRotation();
	Rectangle rect
	{
		pos.x,
		pos.y,
		scale.x,
		scale.y
	};

	DrawRectanglePro(rect,scale *.5f,rot,GREEN);
}
