--[[
Start Header -------------------------------------------------------
Copyright (C) 2022 DigiPen Institute of Technology.
Reproduction or disclosure of this file or its contents without the prior written
consent of DigiPen Institute of Technology is prohibited.
File Name: premake5.lua
Purpose: script to generate visual studio solution file.
Language: lua - used by premake5
Platform: premake5 Windows
Project: junwoo.seo_cs300_1
Author: Junwoo Seo, junwoo.seo, 0055213
Creation date: Sep 05 2022
End Header --------------------------------------------------------
--]]
workspace "RenderingEngine"
    platforms {"Win64"}
    configurations  { "Debug", "Release" }    
    startproject "RenderingEngine"
include "Libs/glfw"
include "Libs/glad"
include "Libs/imgui"
IncludeDir={}
IncludeDir["GLFW"]="Libs/glfw/glfw/include/"
IncludeDir["GLAD"]="Libs/glad/"
IncludeDir["GLM"]="Libs/glm/"
IncludeDir["ENTT"]="Libs/entt/"
IncludeDir["IMGUI"]="Libs/imgui/"
IncludeDir["STB_IMAGE"]="Libs/stb_image/"


project "RenderingEngine"
    location "RenderingEngine"
    kind "ConsoleApp"
    language "C++"
    cppdialect "c++17"
    targetdir "bin/%{cfg.buildcfg}"
    objdir "bin/%{cfg.buildcfg}-obj"
    architecture "x86_64"
    links {
        "GLFW",
        "GLAD",
        "opengl32.lib",
        "ImGui"
    }

    disablewarnings { "4819", "4002", "4005","6031", "4267", "26498", "26819", "28020", "26439" }
    linkoptions { "-IGNORE:4075","-IGNORE:4098"}
    includedirs
    {
        "RenderingEngine",
        "%{IncludeDir.GLFW}",
        "%{IncludeDir.GLAD}",
        "%{IncludeDir.GLM}",
        "%{IncludeDir.ENTT}",
        "%{IncludeDir.IMGUI}",
        "%{IncludeDir.STB_IMAGE}"
    }
    files {
        "RenderingEngine/**.h",
        "RenderingEngine/**.cpp"
    }
    defines{
        "GLFW_INCLUDE_NONE",
        "_CRT_SECURE_NO_WARNINGS"
    }

    postbuildcommands {
        "{COPYDIR} \"../Assets\" \"../bin/%{cfg.buildcfg}/Assets\"",
        "{COPYDIR} \"../Assets\" \"../RenderingEngine/Assets\"",
    }


    -- All of these settings will appear in the Debug configuration
    filter "configurations:Debug"
        defines { "DEBUG" }
        symbols "On"
    filter "configurations:Release"
        defines { "NDEBUG" }
        optimize "On"
