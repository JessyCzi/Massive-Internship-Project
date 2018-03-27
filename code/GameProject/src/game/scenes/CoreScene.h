#ifndef HEADER_SCENE_CORE
#define HEADER_SCENE_CORE

#include "lib\ces\Scene.h"

class CoreScene : public Scene 
{
public:
	CoreScene();
	// Inherited via Scene
	virtual void init() override;
};

#endif // !HEADER_SCENE_CORE
