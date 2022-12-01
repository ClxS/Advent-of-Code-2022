function lib(name)
    project(name)
        kind "StaticLib"
    	language "C++"
    	files {
    		"*.lua",
    		"include/**",
    		"src/**",
    		"data/**",
    		"components/**",
    		"platform/Windows/**",
    		"natvis/**"
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


