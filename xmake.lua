-- xmake.lua (根目录)
set_project("GungnirEngine")

set_arch("x64")
add_rules("mode.debug", "mode.release")
set_languages("c++20")

add_requires("vulkan-hpp", "vulkan-memory-allocator-hpp", "assimp", "eigen", "robin-map", "spirv-reflect", "boost", "glfw", "fmt")
add_includedirs("$(projectdir)", "$(projectdir)/third-party")
add_linkdirs("$(projectdir)/third-party")

target("platform")
    set_kind("binary")
    add_headerfiles("platform/*.h")
    add_files("platform/*.cpp")
    add_packages("eigen", "boost", "glfw", "vulkan-hpp", "vulkan-memory-allocator-hpp", "spirv-reflect")
    add_deps("common", "driver", "engine")

target("engine")
    set_kind("shared")
    add_headerfiles("engine/*.h", "engine/**/*.h")
    add_files("engine/*.cpp", "engine/**/*.cpp")
    add_packages("eigen", "robin_map")
    add_deps("common", "driver")

target("common")
    set_kind("shared")
    add_headerfiles("common/*.h", "common/**/*.h")
    add_files("common/*.cpp", "common/**/*.cpp")
    add_packages("eigen", "robin_map", "fmt")
    add_defines("GUNGNIR_STATIC")

target("driver")
    set_kind("shared")
    add_headerfiles("driver/**/*.h")
    add_files("driver/**/*.cpp")
    add_packages("eigen", "vulkan-hpp", "vulkan-memory-allocator-hpp", "spirv-reflect", "fmt")
    add_deps("common")
    add_linkdirs(os.getenv("VK_SDK_PATH").."/Lib/")
    add_links("vulkan-1")
    add_defines("GUNGNIR_STATIC")
