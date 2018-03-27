#include "Scene.h"

Scene::Scene(uint EntityCompacity)
	:m_maxEntities(EntityCompacity)
{
	m_componentStorage = new void*[32];
	m_entityMasks = new Scene::uint[m_maxEntities];

	for (uint i = 0; i < m_maxEntities; ++i)
	{
		m_entityMasks[i] = NULL;
	}
}
Scene::~Scene()
{
	delete[] m_componentStorage;
	delete[] m_entityMasks;
}


void Scene::SubmitUpdateSystem(System system, Mask mask)
{
	m_updateSystems[m_updateSystemCount] = { system, mask };
	++m_updateSystemCount;
}
void Scene::SubmitDrawSystem(System system, Mask mask)
{
	m_drawSystems[m_drawSystemCount] = { system, mask };
	++m_drawSystemCount;
}


Scene::uint Scene::CreateEntity()
{
	Scene::uint entity = 0;
	for (; entity < m_maxEntities; ++entity)
	{
		if (m_entityMasks[entity] == NULL)
		{
			return entity;
		}
	}

	printf("Error!  No more entities left!\n");

	return(m_maxEntities);
}
Scene::uint Scene::DestroyEntity(Scene::Entity entity)
{
	if (m_entityMasks[entity])
	{
		--m_currentEntities;
		m_entityMasks[entity] = NULL;
	}

	return 0;
}
Scene::Entity Scene::RegisterEntity(Scene::Mask entityMask)
{
	++m_currentEntities;

	uint entity = CreateEntity();

	m_entityMasks[entity] = entityMask;

	return entity;
}

Scene::uint Scene::GetEntityCompacity()
{
	return m_maxEntities;
}
Scene::uint Scene::GetCurrentEntityCount()
{
	return m_currentEntities;
}
Scene::uint Scene::GetEntityMask(uint index)
{
	return m_entityMasks[index];
}

void Scene::Update(float deltaTime)
{
	for (uint entity = 0; entity < m_currentEntities; ++entity)
	{
		for (int system = 0; system < m_updateSystemCount; ++system)
		{
			internalSystem& isystem  = m_updateSystems[system];
			if ((m_entityMasks[entity] & isystem.Mask) == isystem.Mask)
			{
				isystem.System(*this, deltaTime, entity);
			}
		}
	}
}
void Scene::Draw(float deltaTime)
{
	for (uint entity = 0; entity < m_currentEntities; ++entity)
	{
		for (byte system = 0; system < m_drawSystemCount; ++system)
		{
			internalSystem& isystem = m_drawSystems[system];
			if ((m_entityMasks[entity] & isystem.Mask) == isystem.Mask)
			{
				isystem.System(*this, deltaTime, entity);
			}
		}
	}
}
