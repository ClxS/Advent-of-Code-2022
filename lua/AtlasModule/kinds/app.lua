function app(name)
    project(name)
        kind "WindowedApp"
    	language "C++"
        targetdir(imageDirectory)
        debugdir(imageDirectory)
    	files {
    		"*.lua",
    		"include/**",
    		"src/**",
    		"data/**",
    		"platform/Windows/**",
    	}
        includedirs {
            ".",
            "**",
        }
        defines {
            "NOMINMAX",
        }

    	flags { "FatalWarnings" }
        exports {
            ["includedirs"] = {
                path.getabsolute("include"),
            }
        }

        filter { "platforms:Windows" }
            includedirs {
                "platform/Windows/src",
            }
            exports {
                ["includedirs"] = {
                    path.getabsolute("platform/Windows/include"),
                }
            }
        filter {}
end


