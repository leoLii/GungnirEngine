target("common")
    set_kind("static")
    add_headerfiles("./*.h", "./**/*.h")
    add_files("./*.cpp", "./**/*.cpp")
    add_packages("eigen", "robin_map", "fmt")
    add_defines("GUNGNIR_STATIC")