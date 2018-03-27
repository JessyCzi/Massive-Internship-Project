#include "InputManager.h"
#include <memory.h>
Input input; // = new Input();



void InputManager::Update()
{
	for (unsigned int i = 0; i < KeyCount; i++)
	{
		
	}

}

Input::Input()
{
	memset(input.buttenData, 0, ButtenCount * sizeof(int));
	memset(input.keyData, 0, KeyCount * sizeof(int));
}

int Input::operator[](Key key)
{

	return 0;
}

int Input::operator[](Butten btn)
{
	return 0;
}
