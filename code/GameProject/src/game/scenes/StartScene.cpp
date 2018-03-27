#include "StartScene.h"
#include "game\Components.h"
#include "game\Systems.h"

#include "../Settings.h"

StartScene::StartScene() : Scene(255)
{
	Mask sprite = SubmitComponent<Component::Sprite>();
	Mask transform = SubmitComponent<Component::Transform>();
	Mask player_mask = SubmitComponent<Component::Player>();
	Mask circleCollider = SubmitComponent<Component::PhysicsBody>();


	SubmitUpdateSystem(System::PlayerMove, player_mask | transform);
	SubmitUpdateSystem(System::Physics, transform | circleCollider);

	SubmitDrawSystem(System::Draw, transform | sprite);



}

void StartScene::init()
{

	Mask sprite = GetMask<Component::Sprite>();
	Mask transform = GetMask<Component::Transform>();
	Mask player_mask = GetMask<Component::Player>();
	Mask circleCollider = GetMask<Component::PhysicsBody>();


	Entity background = RegisterEntity(transform | sprite);
	GetComponent<Component::Sprite>(background).image = new Image(Settings::Background_defaultImage);


	Entity player = RegisterEntity(transform | sprite | circleCollider | player);
	GetComponent<Component::Sprite>(player).image = new Image(Settings::Avatar_defaultImage, 32, 0, 32, 32);
	GetComponent<Component::PhysicsBody>(player).radie = 16;


	Entity Enemy = RegisterEntity(transform | circleCollider | sprite);
	GetComponent<Component::Transform>(Enemy).pos = { 250, 250 };
	GetComponent<Component::PhysicsBody>(Enemy).radie = 16;
	GetComponent<Component::Sprite>(Enemy).image = new  Image(Settings::Enemy_defaultImage, 32, 0, 32, 32);

}
