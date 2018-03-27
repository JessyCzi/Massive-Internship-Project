#ifndef World_H
#define World_H

#include "lib\ces\Scene.h"

class World
{
	
	Scene m_scene;

public:
	World();
	void Create();
	void Destroy();
	void Update();
	void Draw();

private:

};

#endif
