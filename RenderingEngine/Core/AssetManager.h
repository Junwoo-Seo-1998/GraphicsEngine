#pragma once
/* Start Header -------------------------------------------------------
Copyright (C) 2022 DigiPen Institute of Technology.
Reproduction or disclosure of this file or its contents without the prior written
consent of DigiPen Institute of Technology is prohibited.
File Name: AssetManager.h
Purpose: AssetManager for the engine.
Language: C++ MSVC(2022)
Platform: MSVC(2022), GPU needs to support OpenGL 4.6.0, Windows11(x64)
Project: junwoo.seo_cs300_1
Author: Junwoo Seo, junwoo.seo, 0055213
Creation date: Sep 05 2022
End Header --------------------------------------------------------*/
#include <string>
#include "Core/Data/Mesh.h"
#include <memory>
#include <unordered_map>
class Texture;
class Application;
class Scene;
class Shader;

class AssetManager
{
public:
	static void LoadMeshFromFile(const std::string& file_name, const std::string& key_name);
	static std::shared_ptr<Mesh> GetVertexNormalMesh(const std::string& name);
	static std::shared_ptr<LineMesh> GetVertexNormalLineMesh(const std::string& name);
	static std::shared_ptr<Mesh> GetFaceNormalMesh(const std::string& name);
	static std::shared_ptr<LineMesh> GetFaceNormalLineMesh(const std::string& name);

	static void GeneratePlane(const std::string& key_name, float size = 1.f);
	static void GenerateSphere(const std::string& key_name, float radius = 1.f, int segments = 30, int rings = 30);
	static void GenerateSkybox();
	static std::shared_ptr<VertexBuffer> GetSkybox();

	static std::shared_ptr<Shader> LoadShaderFromFile(const std::string& key_name, const std::string& vert_file, const std::string& frag_file);
	static std::shared_ptr<Shader> LoadShaderFromFile(const std::string& key_name, const std::string& common_file, const std::string& vert_file, const std::string& frag_file);
	static std::shared_ptr<Shader> ReloadSherFromFile(const std::string& key_name, const std::string& common_file, const std::string& vert_file, const std::string& frag_file);
	static std::shared_ptr<Shader> GetShader(const std::string& key_name);

	static std::shared_ptr<Texture> LoadTextureFromFile(const std::string& key_name, const std::string& file_name);
	static std::shared_ptr<Texture> GetTexture(const std::string& key_name);


	static void RegisterScene(const std::string& scene_name, std::shared_ptr<Scene> scene);
	static std::shared_ptr<Scene> GetScene(const std::string& scene_name);
private:
	static std::shared_ptr<VertexBuffer>m_Skybox;
	static std::unordered_map<std::string, std::shared_ptr<Mesh>>m_VertexNormalMesh;
	static std::unordered_map<std::string, std::shared_ptr<LineMesh>>m_VertexNormalLineMesh;
	static std::unordered_map<std::string, std::shared_ptr<Mesh>>m_FaceNormalMesh;
	static std::unordered_map<std::string, std::shared_ptr<LineMesh>>m_FaceNormalLineMesh;

	static std::unordered_map<std::string, std::shared_ptr<Shader>>m_Shaders;
	static std::unordered_map<std::string, std::shared_ptr<Texture>>m_Textures;

	static std::unordered_map<std::string, std::shared_ptr<Scene>>m_Scenes;
};


