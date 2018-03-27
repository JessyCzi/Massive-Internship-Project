#ifndef HEADER_SCENE_CORE
#define HEADER_SCENE_CORE

#include "lib\ces\Scene.h"

class StartScene : public Scene 
{
public:
	StartScene();
	// Inherited via Scene
	virtual void init() override;
};

#endif // !HEADER_SCENE_CORE
