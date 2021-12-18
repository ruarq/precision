workspace "precision"
	configurations { "debug", "release" }

project "precision"
	kind "ConsoleApp"
	language "C++"
	warnings "Extra"

	targetdir "bin/%{cfg.buildcfg}"
	objdir "bin/obj"

	files { "include/**.hpp", "main.cpp" }

	includedirs { "include" }

	filter { "configurations:debug" }
		symbols "On"

	filter { "configurations:release" }
		optimize "On"