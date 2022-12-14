function test(name)
    project(name)
        kind "ConsoleApp"
    	language "C++"
    	files {
    		"*.lua",
    		"include/**",
    		"src/**",
    		"data/**",
    	}
    	links {
    	    "benchmark",
    	    "gtest",
    	}

    	flags { "FatalWarnings" }
        exports {
            ["includedirs"] = {
                path.getabsolute("include"),
            }
        }
end


