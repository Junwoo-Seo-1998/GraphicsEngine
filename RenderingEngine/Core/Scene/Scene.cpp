/* Start Header -------------------------------------------------------
Copyright (C) 2022 DigiPen Institute of Technology.
Reproduction or disclosure of this file or its contents without the prior written
consent of DigiPen Institute of Technology is prohibited.
File Name: Scene.cpp
Purpose: It defines Scene.
Language: C++ MSVC(2022)
Platform: MSVC(2022), GPU needs to support OpenGL 4.6.0, Windows11(x64)
Project: junwoo.seo_cs300_1
Author: Junwoo Seo, junwoo.seo, 0055213
Creation date: Sep 05 2022
End Header --------------------------------------------------------*/
#include "Scene.h"
#include "Core/Component/TransformComponent.h"

Scene::Scene(Application& app)
	:App(app)
{
	
}

Entity Scene::CreateEntity()
{
	Entity entity{ m_Registry.create(),this };
	entity.AddComponent<TransformComponent>();
	return entity;
}

entt::registry& Scene::GetRegistry()
{
	return m_Registry;
}
