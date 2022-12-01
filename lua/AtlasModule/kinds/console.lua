function console(name)
    local origin = debug.getinfo(2).source
    origin = origin:sub(2)
    origin = getDirectory(origin)

    project(name)
        kind "ConsoleApp"
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
        postbuildcommands {
            "robocopy " .. origin .. "data \"" .. imageDirectory .. "/data/" .. name .. "\" /E > nul",
            "@ver > nul",
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


