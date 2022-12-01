require "lua/AtlasModule"

rootDirectory = path.getabsolute(".")
toolsDirectory = path.getabsolute("bin/tools")
dataDirectory = path.getabsolute("data")
imageDirectory = path.getabsolute("image/%{cfg.platform}_%{cfg.buildcfg}")

workspace "AdventOfCode"
    location "build"
    platforms { "Windows" }
    configurations { "Debug", "Release" }
    cppdialect "C++latest"
    flags { "MultiProcessorCompile" }
    filter { "platforms:Windows" }
        system "Windows"
        architecture "x86_64"
        buildoptions { 
            "/Zc:__cplusplus",
        }
    filter{}

    filter { "configurations:Release" }
       	optimize "Full"
        flags "NoRuntimeChecks"
        inlining "Auto"
        intrinsics "on"
        defines { "NDEBUG" }
    filter{}

    for _,v in pairs(os.matchfiles("src/*/premake5.lua")) do
        print(v)
        include(v)
    end

    group("third-party")
    include('third-party/benchmark.lua')