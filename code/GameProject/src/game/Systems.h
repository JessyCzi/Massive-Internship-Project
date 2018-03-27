#ifndef HEADER_SYSTEMS
#define HEADER_SYSTEMS

#include "lib\ces\Scene.h"
#include "game\Components.h"
#include "lib\collections\DynamicBuffer.h"

#include "../Vector2f.h"
#include "../Renderer.h"
#include "../Game.h";

#include <math.h>

#define arccos acos

namespace System
{
	using namespace Component;

	SYSTEM(Draw, scene, t, e)
	{
		Transform& transform = scene.GetComponent<Transform>(e);
		Sprite sprite = scene.GetComponent<Sprite>(e);

				
		sprite.image->SetPosition(Vector2f(transform.pos.x, transform.pos.y));
		static Renderer *renderer = Game::GetRenderer();
		renderer->Draw(sprite.image);
	}

	SYSTEM(PlayerMove, scene, t, e)
	{
		Transform& transform = scene.GetComponent<Transform>(e);
	
//		Game::GetInput()->GetCursorPosition(transform.pos.x, transform.pos.y);
	
//		std::cout << transform.pos.x << ", " << transform.pos.y << std::endl;
	}

	
	


	SYSTEM(Physics, s, t, e)
	{
		static Scene::Mask s_mask = s.GetMask<PhysicsBody>() | s.GetMask<Transform>();
		static unsigned int end = s.GetEntityCompacity();
		
		Transform& tf = s.GetComponent<Transform>(e);
		PhysicsBody& cc = s.GetComponent<PhysicsBody>(e);
		for (unsigned int i = 0; i < end; i++)
		{
			if (i == e) continue;
			if ((s.GetEntityMask(i) & s_mask ) == s_mask) 
			{
				PhysicsBody& othercc = s.GetComponent<PhysicsBody>(i);
				//if (othercc.colliding) continue;

				Transform& othertf = s.GetComponent<Transform>(i);
				
				
				//IF COLLIDING
				if ((tf.pos - othertf.pos).Length() < othercc.radie + cc.radie)
				{

					


					//re.name.ing
					Vector2f A = tf.pos;
					Vector2f B = othertf.pos;

					float Ar = cc.radie;
					float Br = othercc.radie;
					
					Vector2f X = B - A;
					Vector2f Nx = X.Normalized();
					float Lx = X.Length();


					//calulte f1 & f2					

					Vector2f f1 = Nx * Ar;

					float Lp = (X - f1).Length();
					float q = Br - Lp;
					float r = Ar - q;
					
					Vector2f f2 = Nx * r;					

					//calculte pink & purple
					float temp1 = Lx * Lx + Ar * Ar - Br * Br;
					float temp2 = 2 * Lx * Ar;
					float temp3 = temp1 / temp2;
					float v = arccos(temp3);

					float base = sin(v) * Ar;

					if (base > Lx)
					{
						//throw;
					}

					Vector2f pink = Nx * base;
					Vector2f purple = pink - f2;
					Vector2f gray = f1 - pink;


					//move
					othertf.pos += purple;
					tf.pos -= gray;
					
					//cc.other = i;
					//cc.colliding = true;
					//othercc.other = e;
					//othercc.colliding = true;



					std::cout << "collition!" << std::endl;

				}
			}
		}
	}
	
}
#endif // !HEADER_SYSTEMS
