#ifndef HEADER_SCENE
#define HEADER_SCENE

#include <map>
#include <iostream>

#include <stdlib.h>

#define SYSTEM(name, pScene, pDeltaTime, pEntity) void name (Scene& pScene, float pDeltaTime, Scene::Entity pEntity)



class Scene
{
public:
	typedef unsigned int Entity;
	typedef unsigned int Mask;
protected:
	typedef void(*System)(Scene& scene, float deltaTime, Entity entity);
	typedef unsigned int uint;
	typedef unsigned char byte;
	typedef unsigned int Hash;
private:
	struct internalSystem
	{
		System System;
		Mask Mask;
	};

	uint m_maxEntities;
	uint m_currentEntities = 0;
	Entity * m_entityMasks;

	uint m_componentCount;
	void** m_componentStorage;
	std::map<Hash, uint> componentIndex;
	

	internalSystem m_updateSystems[64];
	internalSystem m_drawSystems[32];

	byte m_updateSystemCount = 0;
	byte m_drawSystemCount = 0;

	Entity CreateEntity();

protected:
	Scene(uint EntityCompacity);
public:
	~Scene();

	template <typename T>
	Mask SubmitComponent();

	template <typename T>
	T& GetComponent(Entity entity);

	template <typename T>
	Mask GetMask();


	void SubmitUpdateSystem(System system, Mask mask);
	void SubmitDrawSystem(System system, Mask mask);


	uint DestroyEntity(Entity entity);
	Entity RegisterEntity(Mask entityMask);

	uint GetEntityCompacity();
	uint GetCurrentEntityCount();
	Mask GetEntityMask(uint index);


	void Update(float deltaTime);
	void Draw(float deltaTime);

	virtual void init() = 0;
};

template<typename T>
inline Scene::Mask Scene::SubmitComponent()
{
	m_componentStorage[m_componentCount] = new T[m_maxEntities];

	componentIndex[(uint)typeid(T).hash_code()] = m_componentCount;

	++m_componentCount;

	return 1 << (m_componentCount - 1);
}

template<typename T>
inline T& Scene::GetComponent(Scene::Entity entity)
{
	return ((T*)m_componentStorage[componentIndex[(uint)typeid(T).hash_code()]])[entity];
}

template<typename T>
Scene::Mask Scene::GetMask()
{
	return 1 << componentIndex[(uint)typeid(T).hash_code()];
}


#endif