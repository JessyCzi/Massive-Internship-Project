#ifndef HEADER_COMPONENTS
#define HEADER_COMPONENTS

#include "../Image.h"




#include "lib\math\Vector.h"
	

namespace Component
{
	struct Transform
	{
		Vector2f pos;
	};

	struct PhysicsBody
	{
		float radie;

		Component::Transform last;

	};


	struct Sprite
	{
		Image * image;
	};

	struct Player {
	
	
	};
}

#endif // !HEADER_COMPONENTS
