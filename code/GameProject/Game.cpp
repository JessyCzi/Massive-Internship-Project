#include "Game.h"

#include "Renderer.h"
#include "Timer.h"

#include "game\scenes\StartScene.h"

Game* Game::ourGame = nullptr;

bool Game::Create()
{
	if (ourGame == nullptr)
	{
		ourGame = new Game();
		if (!ourGame->Init())
		{
			delete ourGame;
			return false;
		}
	}
	return true;
}

Game* Game::GetInstance()
{
	return ourGame;
}

void Game::Destroy()
{
	if (ourGame)
	{
		ourGame->Shutdown();
		delete ourGame;
	}
}

Game::Game()
{

}

Game::~Game()
{

}

bool Game::Init()
{
	myRenderer.Init();
	//myInputManager.Init();
	myEventHandler.Init();
	//myProjectileManager.Init();

	return true;
}

bool Game::Run()
{
	myRunning = true;
	m_scene = new StartScene();

	m_scene->init();
	while (myRunning)
	{
		Update();
		Render();
	}

	delete m_scene;

	return true;
}

void Game::Render()
{
	myRenderer.Prepare();
	
	m_scene->Draw(Timer::GetElapsedFrameTime());


	//myProjectileManager.Draw();

	myRenderer.Render();
}

void Game::Stop()
{
	myRunning = false;
}

bool Game::Shutdown()
{
	myRenderer.Shutdown();
	return true;
}

void Game::Update()
{
	Timer::Update();

	myEventHandler.HandleEvents();
	
	//myProjectileManager.Update();

	m_scene->Update(Timer::GetElapsedFrameTime());
}


// Static getters
GameWindow* Game::GetGameWindow()
{
	if (ourGame)
	{
		return &ourGame->myGameWindow;
	}

	return nullptr;
}

Renderer* Game::GetRenderer()
{
	if (ourGame)
	{
		return &ourGame->myRenderer;
	} 

	return nullptr;
}

//ProjectileManager* Game::GetProjectiles()
//{
//	if (ourGame)
//	{
//		return &ourGame->myProjectileManager;
//	} 
//
//	return nullptr;
//}

Scene* Game::GetScene()
{
	if (ourGame)
	{
		return ourGame->m_scene;
	} 

	return nullptr;
}
