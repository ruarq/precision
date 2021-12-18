workspace "precision"
	configurations { "debug", "release" }

project "precision"
	kind "SharedLib"
	language "C++"
	warnings "Extra"
	cppdialect "C++17"

	targetdir "lib/%{cfg.buildcfg}"
	objdir "lib/obj"

	files { "include/**.hpp", "source/**.cpp" }

	includedirs { "include" }

	filter { "configurations:debug" }
		symbols "On"

	filter { "configurations:release" }
		optimize "On"

project "example"
	kind "ConsoleApp"
	language "C++"
	warnings "Extra"
	cppdialect "C++17"

	targetdir "bin/%{cfg.buildcfg}"
	objdir "bin/obj"

	files { "example/**.hpp", "example/**.cpp" }

	includedirs { "include" }
	links { "precision" }

	filter { "configurations:debug" }
		symbols "On"

	filter { "configurations:release" }
		optimize "On"