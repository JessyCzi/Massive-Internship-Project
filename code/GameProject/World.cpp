#include "World.h"
#include "Image.h"
#include "Game.h"
#include "Settings.h"
#include "Timer.h"

#include "game\Components.h"
#include "game\Systems.h"



World::World() : m_scene(256) {}

void World::Create()
{
	typedef unsigned int Mask;
	typedef unsigned int Entity;

	
}

void World::Destroy()
{

	// fix when image managent 

	//m_scene.~Scene();
}

void World::Update() { m_scene.Update(Timer::GetElapsedFrameTime()); }

void World::Draw() { m_scene.Draw(Timer::GetElapsedFrameTime()); }

